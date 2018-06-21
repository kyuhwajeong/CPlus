
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC그리기함수.h"
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



// CChildView 메시지 처리기

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
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 점을 하나씩 찍어 그림을 그리거나 비트맵을 출력
	// 시스템 메모리에서 그래픽 카드의 비디오 메모리까지 가는데 많은 경로를 거쳐야 하고 경로가 늘어날수록 많은 시간을 소요
	// 개선 방안 :  시스템 메모리에 점을 모두 찍은 다음 한꺼번에 비디오 메모리로 전송
	// 그래픽 카드 장치는 블록 단위의 데이터를 전송하는 기능 제공 이러한 기능을 Bit '블릿'으로 읽는다.
	// 시스템 메모리를 마치 DC인 것처럼 사용할 수 있는 기능. 메모리DC는 CDC::CreateCompatibleDC()을 통해 생성
	////[ Page 169 점찍기 샘플	
	//for (int x = 0; x < 256; x++)
	//	for (int y = 0; y < 256; y++)
	//		dc.SetPixelV(x, y, RGB(x, y, 0));
	////] Page 169 점찍기 샘플	

	////[ Page 172 선그리기 샘플	
	//CRect rect;
	//GetClientRect(&rect);
	//dc.MoveTo(0, 0);
	//dc.LineTo(rect.right, rect.bottom);
	//dc.MoveTo(0, rect.bottom);
	//dc.LineTo(rect.right, 0);
	////] Page 172 선그리기 샘플	

	////[ Page 174 텍스트함수 샘플
	//// TextOut() - 특정 위치에 문자열을 출력
	//// DrawText() - 사각형을 기준으로 문자열을 출력
	/*CRect rect;
	GetClientRect(&rect);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	dc.DrawText(CString("텍스트 함수를 연습합니다."), &rect, 
													DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	dc.SetTextAlign(TA_CENTER);
	dc.TextOutW(rect.Width() / 2, rect.Height() / 4, CString("MFC의 세계에 오신 것을 환영합니다."));*/
	////] Page 174 텍스트함수 샘플


	//// 매핑모드 
	//// MM_TEXT 논리 단위와 장치단위가 1대 1로 대응, GDI함수에 사용되는 단위를 픽셀로 간주해도 됨, 장치의 종류에 따라 그림 크기가 달라진다.
	//// MM_LOMETRIC ~ MM_TWIPS 매핑모드를 사용하면 해상도를 고려하여 논리 단위를 장치단위로 즉 픽셀로 바꾸므로 그림의 크기가 일정
	//// MM_ISOTROPIC, MM_ANISOTROPIC 사용자가 논리단위와 장치 단위의 변환 관계를 정의할 수 있으므로 프로그래밍이 가능한 매핑모드 CDC::SetWindowExt(), CDD::SetViewportExt()로 임의로 정의할 수 있음.
	//// [ Page 177 예제 1
	//dc.SetMapMode(MM_LOMETRIC);
	//dc.Rectangle(0, 0, 500, -500);
	//// ] Page 177 예제 1

	//// [ Page 177 예제 2
	//CRect rect;
	//GetClientRect(&rect);
	//dc.SetMapMode(MM_ANISOTROPIC);
	//dc.SetWindowExt(300, 300);	// 논리 단위
	//dc.SetViewportExt(rect.Width(), rect.Height());	// 장치단위
	//dc.Ellipse(0, 0, 300, 300);
	//dc.Rectangle(50, 50, 250, 250);
	//// ] Page 177 예제 2

	// [ Page 181 속성 함수
	// 배경을 밝은 회색으로 칠한다.
	dc.SelectStockObject(LTGRAY_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	//dc.SetBkMode(TRANSPARENT);
	dc.SetBkMode(OPAQUE);
	dc.TextOutW(100, 100, CString("안녕하세요."));
	// ] Page 181 속성 함수

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

