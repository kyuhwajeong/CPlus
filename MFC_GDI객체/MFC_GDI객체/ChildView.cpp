
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFC_GDI객체.h"
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

	//// [ Page 185 펜 예제
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
	//// ] Page 185 펜 예제

	//// [ Page 186 브러시 예제1
	//CBrush brush(RGB(255, 0, 0));
	//CBrush *pOldBrush = dc.SelectObject(&brush);
	//dc.Ellipse(100, 100, 200, 200);
	//dc.SelectObject(pOldBrush); // 기존의 브러시를 선택 해제 - 생략해도 무방함
	//// ] Page 186 브러시 예제1

	//// [ Page 188 브러시 예제2
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//CBrush brush(&bitmap);
	//dc.SelectObject(&brush);
	//dc.Ellipse(100, 100, 300, 300);
	//// ] Page 188 브러시 예제2

	////[ Page 189 폰트 예제
	//CFont font;
	//font.CreatePointFont(400, L"Arial");
	//dc.SelectObject(&font);
	//dc.TextOutW(10, 10, CString("Hello"));
	////] Page 189 폰트 예제

	////[ Page 190 내장객체 예제
	//// 내장객체(Stock Object)란 원오두 운영체제가 미리 만들어서 제공하는 GDI 객체를 말한다. CDC::SelectStockObject()함수를 사용
	//// 클라이언트 영역을 초록색 해치 브러시로 채운다.
	//CRect rect;
	//GetClientRect(&rect);
	//CBrush brush(HS_DIAGCROSS, RGB(0, 255, 0));
	//dc.SelectObject(&brush);
	//dc.Rectangle(&rect);

	//// 경계선이 없고 내부가 회색으로 채워진 사각형을 그린다.
	//dc.SelectStockObject(NULL_PEN);
	//dc.SelectStockObject(GRAY_BRUSH);
	//dc.Rectangle(100, 100, 200, 200);

	//// 경계선이 검정색이고 내부가 비어 있는 사각형을 그린다.
	//dc.SelectStockObject(BLACK_PEN);
	//dc.SelectStockObject(NULL_BRUSH);
	//dc.Rectangle(300, 100, 400, 200);
	////] Page 190 내장객체 예제

	////[ Page 191 비트맵정보 예제
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);
	//BITMAP bmpinfo;
	//bitmap.GetBitmap(&bmpinfo);
	//TRACE("가로 = %d, 세로 = %d", bmpinfo.bmWidth, bmpinfo.bmHeight);
	////] Page 191 비트맵정보 예제


	//[ Page 194 비트맵출력 예제
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	// 메모리 디바이스 컨텍스트를 만든 후 비트맵을 선택해 넣는다.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	// 비트맵을 화면에 출력
	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
	
	dc.StretchBlt(100, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 4, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	//] Page 194 비트맵출력 예제

	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

