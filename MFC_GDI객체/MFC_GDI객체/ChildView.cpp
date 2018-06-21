
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFC_GDI��ü.h"
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

	//// [ Page 185 �� ����
	//int nPenStyle[] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME };
	//WCHAR *PenStyle[] = { L"PS_SOLID", L"PS_DASH", L"PS_DOT", L"PS_DASHDOT", L"PS_DASHDOTDOT", L"PS_NULL", L"PS_INSIDEFRAME" };

	//dc.SetTextAlign(TA_BASELINE);

	//for (int i = 0; i < sizeof(nPenStyle) / sizeof(nPenStyle[0]); i++)
	//{
	//	CPen pen(nPenStyle[i], 1, RGB(0, 0, 255));
	//	dc.SelectObject(&pen);
	//	CString str = PenStyle[i];
	//	dc.TextOutW(50, 50 + i * 25, str);
	//	dc.MoveTo(200, 50 + i * 25);
	//	dc.LineTo(400, 50 + i * 25);
	//}

	//CPen blackpen(PS_SOLID, 1, RGB(0, 0, 0));
	//dc.SelectObject(&blackpen);
	//dc.Rectangle(50, 250, 150, 350);
	//
	//CPen pen1(PS_SOLID, 20, RGB(255, 0, 0));
	//dc.SelectObject(&pen1);
	//dc.Ellipse(50, 250, 150, 350);

	//dc.SelectObject(&blackpen);
	//dc.Rectangle(250, 250, 350, 350);

	//CPen pen2(PS_INSIDEFRAME, 20, RGB(255, 0, 0));
	//dc.SelectObject(&pen2);
	//dc.Ellipse(250, 250, 350, 350);
	//// ] Page 185 �� ����

	//// [ Page 186 �귯�� ����1
	//CBrush brush(RGB(255, 0, 0));
	//CBrush *pOldBrush = dc.SelectObject(&brush);
	//dc.Ellipse(100, 100, 200, 200);
	//dc.SelectObject(pOldBrush); // ������ �귯�ø� ���� ���� - �����ص� ������
	//// ] Page 186 �귯�� ����1

	//// [ Page 188 �귯�� ����2
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//dc.SelectObject(&brush);
	//dc.Ellipse(100, 100, 300, 300);
	//// ] Page 188 �귯�� ����2

	////[ Page 189 ��Ʈ ����
	//CFont font;
	//font.CreatePointFont(400, L"Arial");
	//dc.SelectObject(&font);
	//dc.TextOutW(10, 10, CString("Hello"));
	////] Page 189 ��Ʈ ����

	////[ Page 190 ���尴ü ����
	//// ���尴ü(Stock Object)�� ������ �ü���� �̸� ���� �����ϴ� GDI ��ü�� ���Ѵ�. CDC::SelectStockObject()�Լ��� ���
	//// Ŭ���̾�Ʈ ������ �ʷϻ� ��ġ �귯�÷� ä���.
	//CRect rect;
	//GetClientRect(&rect);
	//CBrush brush(HS_DIAGCROSS, RGB(0, 255, 0));
	//dc.SelectObject(&brush);
	//dc.Rectangle(&rect);

	//// ��輱�� ���� ���ΰ� ȸ������ ä���� �簢���� �׸���.
	//dc.SelectStockObject(NULL_PEN);
	//dc.SelectStockObject(GRAY_BRUSH);
	//dc.Rectangle(100, 100, 200, 200);

	//// ��輱�� �������̰� ���ΰ� ��� �ִ� �簢���� �׸���.
	//dc.SelectStockObject(BLACK_PEN);
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.Rectangle(300, 100, 400, 200);
	////] Page 190 ���尴ü ����

	////[ Page 191 ��Ʈ������ ����
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//BITMAP bmpinfo;
	//bitmap.GetBitmap(&bmpinfo);
	//TRACE("���� = %d, ���� = %d", bmpinfo.bmWidth, bmpinfo.bmHeight);
	////] Page 191 ��Ʈ������ ����


	//[ Page 194 ��Ʈ����� ����
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	// �޸� ����̽� ���ؽ�Ʈ�� ���� �� ��Ʈ���� ������ �ִ´�.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// ��Ʈ���� ȭ�鿡 ���
	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	
	dc.StretchBlt(100, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 4, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	//] Page 194 ��Ʈ����� ����

	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

