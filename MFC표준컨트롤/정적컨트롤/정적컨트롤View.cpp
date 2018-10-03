
// ������Ʈ��View.cpp : C������Ʈ��View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "������Ʈ��.h"
#endif

#include "������Ʈ��Doc.h"
#include "������Ʈ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������Ʈ��View

IMPLEMENT_DYNCREATE(C������Ʈ��View, CFormView)

BEGIN_MESSAGE_MAP(C������Ʈ��View, CFormView)
	ON_STN_CLICKED(IDC_ENHMETA, &C������Ʈ��View::OnClickedEnhmeta)
	ON_BN_CLICKED(IDC_BTNCLR, &C������Ʈ��View::OnBnClickedBtnclr)
	ON_BN_CLICKED(IDC_BTNCUT, &C������Ʈ��View::OnBnClickedBtncut)
	ON_BN_CLICKED(IDC_BTNPASTE, &C������Ʈ��View::OnBnClickedBtnpaste)
	ON_BN_CLICKED(IDC_BTNUNDO, &C������Ʈ��View::OnBnClickedBtnundo)
	ON_BN_CLICKED(IDC_BTNREPLACE, &C������Ʈ��View::OnBnClickedBtnreplace)
	ON_BN_CLICKED(IDC_BTNTXTDSP, &C������Ʈ��View::OnBnClickedBtntxtdsp)
	ON_BN_CLICKED(IDC_BTNREPLACE2, &C������Ʈ��View::OnBnClickedBtnreplace2)
	ON_EN_CHANGE(IDC_EDIT1, &C������Ʈ��View::OnChangeEdit1)
	ON_LBN_DBLCLK(IDC_LIST1, &C������Ʈ��View::OnDblclkList1)
	ON_LBN_SELCHANGE(IDC_LIST1, &C������Ʈ��View::OnSelchangeList1)
	ON_LBN_SELCANCEL(IDC_LIST1, &C������Ʈ��View::OnSelcancelList1)
	ON_LBN_SETFOCUS(IDC_LIST1, &C������Ʈ��View::OnSetfocusList1)
	ON_LBN_KILLFOCUS(IDC_LIST1, &C������Ʈ��View::OnKillfocusList1)
	ON_BN_CLICKED(IDC_BTNADD, &C������Ʈ��View::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTNDEL, &C������Ʈ��View::OnBnClickedBtndel)
	ON_CBN_CLOSEUP(IDC_COMBO1, &C������Ʈ��View::OnCloseupCombo1)
	ON_CBN_DBLCLK(IDC_COMBO1, &C������Ʈ��View::OnDblclkCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &C������Ʈ��View::OnDropdownCombo1)
	ON_CBN_EDITUPDATE(IDC_COMBO1, &C������Ʈ��View::OnEditupdateCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &C������Ʈ��View::OnKillfocusCombo1)
	ON_CBN_SELENDCANCEL(IDC_COMBO1, &C������Ʈ��View::OnSelendcancelCombo1)
	ON_CBN_SELENDOK(IDC_COMBO1, &C������Ʈ��View::OnSelendokCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO1, &C������Ʈ��View::OnSetfocusCombo1)
	ON_BN_CLICKED(IDC_BTNCOMBOADD, &C������Ʈ��View::OnBnClickedBtncomboadd)
	ON_BN_CLICKED(IDC_BTNCOMBODEL, &C������Ʈ��View::OnBnClickedBtncombodel)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// C������Ʈ��View ����/�Ҹ�

C������Ʈ��View::C������Ʈ��View()
	: CFormView(C������Ʈ��View::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

C������Ʈ��View::~C������Ʈ��View()
{
}

void C������Ʈ��View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ENHMETA, m_enhmeta);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scrollbar1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_scrollbar2);
}

BOOL C������Ʈ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void C������Ʈ��View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_enhmeta.SetEnhMetaFile(::GetEnhMetaFile(L"Example.emf"));

	// �ؽ�Ʈ�� ����
	m_edit.SetWindowTextW(L"�ʱⰪ�Դϴ�.");


	// �Է� ������ ���ڿ��� ���̸� �����ϱ�
	//m_edit.SetLimitText(20);

	m_list.AddString(L"����");
	m_list.AddString(L"�ٳ���");
	m_list.AddString(L"���");
	m_list.AddString(L"����");
	m_list.AddString(L"����");
	m_list.AddString(L"����");

	m_list.SetSel(3);// 4��° �׸� ����(���� ���� ����Ʈ �ڽ� ��Ʈ���� ���)

	//m_list.SetCurSel(3);// ���� ���� ����Ʈ �ڽ� ��Ʈ���� ���

	m_combo.SetCurSel(0);

	m_scrollbar1.SetScrollRange(0, 360, FALSE);
	m_scrollbar1.SetScrollPos(0);
	m_scrollbar2.SetScrollRange(0, 360, FALSE);
	m_scrollbar2.SetScrollPos(0);

}


// C������Ʈ��View ����

#ifdef _DEBUG
void C������Ʈ��View::AssertValid() const
{
	CFormView::AssertValid();
}

void C������Ʈ��View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C������Ʈ��Doc* C������Ʈ��View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������Ʈ��Doc)));
	return (C������Ʈ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C������Ʈ��View �޽��� ó����


void C������Ʈ��View::OnClickedEnhmeta()
{
	MessageBox(L"��Ÿ���Ϸ� �׸� �׸��� Ŭ���߽��ϴ�.");
}


void C������Ʈ��View::OnBnClickedBtnclr()// ���� ���õ� ���ڿ��� �����Ѵ�.
{
	m_edit.Clear();
}


void C������Ʈ��View::OnBnClickedBtncut()// Ŭ�����忡 �����Ѵ�. 
{
	m_edit.Cut();
}


void C������Ʈ��View::OnBnClickedBtnpaste()// Ŭ�����忡 ����� ������ �ٿ��ִ´�.
{
	m_edit.Paste();
}


void C������Ʈ��View::OnBnClickedBtnundo() // �������� �ǵ�����
{
	m_edit.Undo();
}


void C������Ʈ��View::OnBnClickedBtnreplace()  // ���۰� �������� ������ ġȯ�Ѵ�.
{
	m_edit.SetSel(5, 7);
	m_edit.ReplaceSel(L"ABC");
}


void C������Ʈ��View::OnBnClickedBtntxtdsp()  // ǥ�õ� �ؽ�Ʈ�� ������ �޽��� ǥ��
{
	// �Էµ� �ؽ�Ʈ�� �˾Ƴ���
	CString str;
	//m_edit.GetWindowTextW(str);
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str);

	MessageBox(str);
}


void C������Ʈ��View::OnBnClickedBtnreplace2()
{
	int len = m_edit.GetWindowTextLengthW();
	m_edit.SetSel(len, len);
	m_edit.ReplaceSel(L"���� �߰��� ���ڿ��Դϴ�.");
}


void C������Ʈ��View::OnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CFormView::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.
	TRACE(L"OnChangeEdit1(������ �����ϸ� ȭ�鿡 ��Ʈ���� �ٽ� �׷����µ� �� �Ŀ� �޽��� �߻�");
}


void C������Ʈ��View::OnDblclkList1()
{
	TRACE(L"\n����ڰ� �׸��� ���� Ŭ��");

	// ������ �׸� �˾Ƴ���(���� ���� ����Ʈ �ڽ� ��Ʈ���� ���)
	//int nIndex = m_list.GetCurSel();

	// ������ �׸� �˾Ƴ���(���� ���� ����Ʈ �ڽ� ��Ʈ���� ���)
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		CString str;
		m_list.GetText(nIndex, str);

		MessageBox(str);
	}
}


void C������Ʈ��View::OnSelchangeList1()
{
	TRACE(L"\n����ڰ� ������ �����ߴ�.");
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		CString str;
		m_list.GetText(nIndex, str);
		GetDlgItem(IDC_EDIT2)->SetWindowTextW(str);
	}
}


void C������Ʈ��View::OnSelcancelList1()
{
	TRACE(L"\n����ڰ� ������ ����ߴ�.");
}


void C������Ʈ��View::OnSetfocusList1()
{
	TRACE(L"\nŰ���� ��Ŀ���� �����.");
}


void C������Ʈ��View::OnKillfocusList1()
{
	TRACE(L"\nŰ���� ��Ŀ���� �Ҿ���.");
}


void C������Ʈ��View::OnBnClickedBtnadd()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(str);
	m_list.AddString(str);
}


void C������Ʈ��View::OnBnClickedBtndel()
{
	int nIndex = m_list.GetCaretIndex();
	if (nIndex != LB_ERR){
		m_list.DeleteString(nIndex);
	}
}


void C������Ʈ��View::OnCloseupCombo1()
{
	TRACE(L"\n����Ʈ �ڽ��� ������.");
}


void C������Ʈ��View::OnDblclkCombo1()
{
	TRACE(L"\n����ڰ� �׸��� ���� Ŭ���ߴ�."); 
}


void C������Ʈ��View::OnDropdownCombo1()
{
	TRACE(L"\n����Ʈ �ڽ��� ������ �����̴�.");
}


void C������Ʈ��View::OnEditupdateCombo1()
{
	TRACE(L"\nEN_EDITUPDATE.");
}


void C������Ʈ��View::OnKillfocusCombo1()
{
	TRACE(L"\nŰ���� ��Ŀ���� �Ҿ���.");
}


void C������Ʈ��View::OnSelendcancelCombo1()
{
	TRACE(L"\nLBN_SELENDCANCEL");
}


void C������Ʈ��View::OnSelendokCombo1()
{
	TRACE(L"\n����ڰ� �׸��� �����ߴ�.");
	int nIndex = m_combo.GetCurSel();
	if (nIndex != LB_ERR){
		CString str;
		m_combo.GetLBText(nIndex, str);

		MessageBox(str);
	}
}


void C������Ʈ��View::OnSetfocusCombo1()
{
	TRACE(L"\nŰ���� ��Ŀ���� �����.");
}


void C������Ʈ��View::OnBnClickedBtncomboadd()
{
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(str);
	m_combo.AddString(str);
}


void C������Ʈ��View::OnBnClickedBtncombodel()
{
	int nIndex = m_combo.GetCurSel();
	if (nIndex != LB_ERR){
		m_combo.DeleteString(nIndex);
	}
}



void C������Ʈ��View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nScrollPos;

	if (pScrollBar->GetSafeHwnd() == m_scrollbar1.GetSafeHwnd()){
		switch (nSBCode){
		case SB_LINELEFT:
			nScrollPos = pScrollBar->GetScrollPos();
			if (nScrollPos > 0){
				pScrollBar->SetScrollPos(--nScrollPos);
				SetDlgItemInt(IDC_EDIT4, nScrollPos);
				Invalidate();
			}
			break;
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			SetDlgItemInt(IDC_EDIT4, nPos);
			Invalidate();
			break;
		}
	}
	else if (pScrollBar->GetSafeHwnd() == m_scrollbar2.GetSafeHwnd()){
		switch (nSBCode){
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			SetDlgItemInt(IDC_EDIT5, nPos);
			Invalidate();
			break;
		}
	}

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void C������Ʈ��View::OnDraw(CDC* pDC)
{
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 300;
	lf.lfEscapement = 10 * m_scrollbar1.GetScrollPos();
	lf.lfOrientation = 10 * m_scrollbar1.GetScrollPos();
	::lstrcpy(lf.lfFaceName, L"Arial");
	CFont font;
	font.CreatePointFontIndirect(&lf);
	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(m_scrollbar2.GetScrollPos(), 0, 0));
	pDC->TextOut(700, 180, L"MFC");
}
