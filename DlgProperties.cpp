// DlgProperties.cpp: файл реализации
//

#include "stdafx.h"
#include "Experiment_MFC.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// диалоговое окно CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(double A, 
							   double A1,
							   double A2,
							   double A3,
							   double Angle,
							   CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgProperties::IDD, pParent)
	, m_dA(A)
	, m_dA1(A1)
	, m_dA2(A2)
	, m_dA3(A3)
	, m_dAngle(Angle)
{
}



CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_A, m_dA);
	DDX_Text(pDX, IDC_E_A1, m_dA1);
	DDX_Text(pDX, IDC_E_A2, m_dA2);
	DDX_Text(pDX, IDC_E_A3, m_dA3);
	DDX_Text(pDX, IDC_E_ANGLE, m_dAngle);
}


BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgProperties::OnBnClickedOk)
END_MESSAGE_MAP()


// обработчики сообщений CDlgProperties


void CDlgProperties::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
