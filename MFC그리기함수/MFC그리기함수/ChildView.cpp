
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFC�׸����Լ�.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView �޽��� ó����

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// ���� �ϳ��� ��� �׸��� �׸��ų� ��Ʈ���� ���
	// �ý��� �޸𸮿��� �׷��� ī���� ���� �޸𸮱��� ���µ� ���� ��θ� ���ľ� �ϰ� ��ΰ� �þ���� ���� �ð��� �ҿ�
	// ���� ��� :  �ý��� �޸𸮿� ���� ��� ���� ���� �Ѳ����� ���� �޸𸮷� ����
	// �׷��� ī�� ��ġ�� ��� ������ �����͸� �����ϴ� ��� ���� �̷��� ����� Bit '��'���� �д´�.
	// �ý��� �޸𸮸� ��ġ DC�� ��ó�� ����� �� �ִ� ���. �޸�DC�� CDC::CreateCompatibleDC()�� ���� ����
	////[ Page 169 ����� ����	
	//for (int x = 0; x < 256; x++)
	//	for (int y = 0; y < 256; y++)
	//		dc.SetPixelV(x, y, RGB(x, y, 0));
	////] Page 169 ����� ����	

	////[ Page 172 ���׸��� ����	
	//CRect rect;
	//GetClientRect(&rect);
	//dc.MoveTo(0, 0);
	//dc.LineTo(rect.right, rect.bottom);
	//dc.MoveTo(0, rect.bottom);
	//dc.LineTo(rect.right, 0);
	////] Page 172 ���׸��� ����	

	////[ Page 174 �ؽ�Ʈ�Լ� ����
	//// TextOut() - Ư�� ��ġ�� ���ڿ��� ���
	//// DrawText() - �簢���� �������� ���ڿ��� ���
	/*CRect rect;
	GetClientRect(&rect);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	dc.DrawText(CString("�ؽ�Ʈ �Լ��� �����մϴ�."), &rect, 
													DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	dc.SetTextAlign(TA_CENTER);
	dc.TextOutW(rect.Width() / 2, rect.Height() / 4, CString("MFC�� ���迡 ���� ���� ȯ���մϴ�."));*/
	////] Page 174 �ؽ�Ʈ�Լ� ����


	//// ���θ�� 
	//// MM_TEXT �� ������ ��ġ������ 1�� 1�� ����, GDI�Լ��� ���Ǵ� ������ �ȼ��� �����ص� ��, ��ġ�� ������ ���� �׸� ũ�Ⱑ �޶�����.
	//// MM_LOMETRIC ~ MM_TWIPS ���θ�带 ����ϸ� �ػ󵵸� ����Ͽ� �� ������ ��ġ������ �� �ȼ��� �ٲٹǷ� �׸��� ũ�Ⱑ ����
	//// MM_ISOTROPIC, MM_ANISOTROPIC ����ڰ� �������� ��ġ ������ ��ȯ ���踦 ������ �� �����Ƿ� ���α׷����� ������ ���θ�� CDC::SetWindowExt(), CDD::SetViewportExt()�� ���Ƿ� ������ �� ����.
	//// [ Page 177 ���� 1
	//dc.SetMapMode(MM_LOMETRIC);
	//dc.Rectangle(0, 0, 500, -500);
	//// ] Page 177 ���� 1

	//// [ Page 177 ���� 2
	//CRect rect;
	//GetClientRect(&rect);
	//dc.SetMapMode(MM_ANISOTROPIC);
	//dc.SetWindowExt(300, 300);	// �� ����
	//dc.SetViewportExt(rect.Width(), rect.Height());	// ��ġ����
	//dc.Ellipse(0, 0, 300, 300);
	//dc.Rectangle(50, 50, 250, 250);
	//// ] Page 177 ���� 2

	// [ Page 181 �Ӽ� �Լ�
	// ����� ���� ȸ������ ĥ�Ѵ�.
	dc.SelectStockObject(LTGRAY_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	//dc.SetBkMode(TRANSPARENT);
	dc.SetBkMode(OPAQUE);
	dc.TextOutW(100, 100, CString("�ȳ��ϼ���."));
	// ] Page 181 �Ӽ� �Լ�

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

