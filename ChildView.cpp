
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "Experiment_MFC.h"
#include "ChildView.h"
#include "Figure.h"
#include "DlgProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

//CChildView::CChildView():m_Circle(100, 100, 100){ } 

CChildView::CChildView() {
	m_nCatched = -1;
}


CChildView::~CChildView()
{
	for(int i=0; m_Objects.size(); i++){
		delete m_Objects[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_NEWFIGURE, OnNewFigure)
END_MESSAGE_MAP()

void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point) {
	for (int i = 0; i < m_Objects.size(); i++)
		if (m_Objects[i]->IsInside(point.x, point.y)) {
			CDlgProperties Dlg(m_Objects[i]->GetA(), m_Objects[i]->GetA1(), m_Objects[i]->GetA2(), m_Objects[i]->GetA3(), m_Objects[i]->GetAngle());
			if (Dlg.DoModal()) {
				m_Objects[i]->SetA(Dlg.m_dA);
				m_Objects[i]->SetA1(Dlg.m_dA1);
				m_Objects[i]->SetA2(Dlg.m_dA2);
				m_Objects[i]->SetA3(Dlg.m_dA3);
				m_Objects[i]->SetDAngle(Dlg.m_dAngle);
				Invalidate();
			}

			CWnd::OnLButtonDblClk(nFlags, point);
			break;
		}
}

// обработчики сообщений CChildView

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
	CPaintDC dc(this); // контекст устройства для рисования
	for(int i=0; i< m_Objects.size(); i++){
		m_Objects[i]->Draw(dc);
	}

	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
	//dc.SetMapMode(MM_LOENGLISH);
	
	//CCircle circle(200, 200, 100);
	//circle.Draw(dc); 
	//m_Circle.Draw(dc); 
	figure.Draw(dc);
}

int CChildView::FindObject(CPoint point){
	int nObj = -1; // if none object found, return -1
	for (int i= m_Objects.size()-1; i>=0; i--) {
		if(m_Objects[i]->IsInside(point.x, point.y)) {
			nObj = i;
			break;
		}
	}
	return nObj;
}

//void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
//
//	CWnd::OnLButtonUp(nFlags, point);
//}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
//	if(m_Circle.IsInside(point.x, point.y))

	//double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); //такие знаки, потому что поворот по часовой стрелке
	//double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
	//point.x = x_mouse;
	//point.y = y_mouse;
	m_nCatched = FindObject(point);

	if (m_nCatched >=0 ) {
		m_MousePos = point;
		SetCapture();
	}

	CRect rect;
	GetClientRect(&rect);

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); 
	//double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
	//point.x = x_mouse;
	//point.y = y_mouse;
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_nCatched = -1;

	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if(m_nCatched>=0) {
		//double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); 
		//double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
		//point.x = x_mouse;
		//point.y = y_mouse;
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y)); 
		CPoint Delta = point - m_MousePos;
		m_Objects[m_nCatched]->Move(Delta.x, Delta.y);
		m_MousePos = point;
		Invalidate();
	}  
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnNewFigure(){
	CRect rect;
	GetClientRect(&rect);
	int mya = rand() % 110 + 40, limit = mya * 0.4;
	int mya1 = rand() % limit + 2;
	limit = mya - 1.1 * mya1;
	int mya2 = rand() % limit + 2;
	if (limit > mya - 1.1 * mya2) limit = mya - 1.2 * mya2;
	int mya3 = rand() % limit + 2;
	m_Objects.push_back(new CMy2DObjectA4(mya, mya1, mya2, mya3, 50 + rand() % 1300, 50 + rand() % 500, 0));
	Invalidate();
}