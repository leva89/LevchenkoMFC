
// ChildView.h : ��������� ������ CChildView
//


#pragma once
#include "Figure.h"
#include <vector>
// ���� CChildView

class CChildView : public CWnd
{
// ��������
public:
	CChildView();

// ��������
public:

protected:
//	CCircle m_Circle; 

	CMy2DObjectA4 figure, figure2;
	CPoint m_MousePos; 
	std::vector<CMy2DObjectA4*> m_Objects;
	
	int m_nCatched;


 //If the point is inside of a circle, 

 //the function will return its number, otherwise -1
	int FindObject(CPoint point);

	// ��������
public:

// ���������������
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����������
public:
	virtual ~CChildView();

	// ��������� ������� ����� ���������
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNewFigure();
};

