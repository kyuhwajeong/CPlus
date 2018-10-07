
// 공통대화상자View.cpp : C공통대화상자View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "공통대화상자.h"
#endif

#include "공통대화상자Doc.h"
#include "공통대화상자View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static UINT WM_FINDREPLACE =
::RegisterWindowMessage(FINDMSGSTRING);

// C공통대화상자View

IMPLEMENT_DYNCREATE(C공통대화상자View, CView)

BEGIN_MESSAGE_MAP(C공통대화상자View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FINDREPLACE, &C공통대화상자View::OnFindreplace)
	ON_REGISTERED_MESSAGE(WM_FINDREPLACE, &C공통대화상자View::OnFindReplaceCmd)
END_MESSAGE_MAP()

// C공통대화상자View 생성/소멸

C공통대화상자View::C공통대화상자View()
	: pFindReplaceDlg(NULL)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

C공통대화상자View::~C공통대화상자View()
{
}

BOOL C공통대화상자View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C공통대화상자View 그리기

void C공통대화상자View::OnDraw(CDC* /*pDC*/)
{
	C공통대화상자Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// C공통대화상자View 인쇄

BOOL C공통대화상자View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C공통대화상자View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C공통대화상자View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// C공통대화상자View 진단

#ifdef _DEBUG
void C공통대화상자View::AssertValid() const
{
	CView::AssertValid();
}

void C공통대화상자View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C공통대화상자Doc* C공통대화상자View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C공통대화상자Doc)));
	return (C공통대화상자Doc*)m_pDocument;
}
#endif //_DEBUG


// C공통대화상자View 메시지 처리기


void C공통대화상자View::OnFindreplace()
{
	if (pFindReplaceDlg != NULL)
		pFindReplaceDlg->SetFocus();
	else{
		pFindReplaceDlg = new CFindReplaceDialog();
		pFindReplaceDlg->Create(FALSE, L"", L"", FR_DOWN, this);
	}

}


HRESULT C공통대화상자View::OnFindReplaceCmd(WPARAM wParam, LPARAM lParam)
{
	CString str;

	if (pFindReplaceDlg->IsTerminating()) // 대화상자 종료
	{
		pFindReplaceDlg = NULL;
		return 0;
	}
	else if (pFindReplaceDlg->FindNext())
	{
		str.Format(L"찾을 문자열: %s", pFindReplaceDlg->GetFindString());
		MessageBox(str);
	}
	else if (pFindReplaceDlg->ReplaceCurrent())
	{
		str.Format(L"찾을 문자열: %s\n\r바꿀 문자열: %s", pFindReplaceDlg->GetFindString(), pFindReplaceDlg->GetReplaceString());
		MessageBox(str);
	}
	else if (pFindReplaceDlg->ReplaceAll())
	{
		str.Format(L"찾을 문자열: %s\n\r바꿀 문자열: %s", pFindReplaceDlg->GetFindString(), pFindReplaceDlg->GetReplaceString());
		MessageBox(str);
	}

	return E_NOTIMPL;
}
