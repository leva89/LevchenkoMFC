
// Experiment_MFC.h : главный файл заголовка для приложения Experiment_MFC
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы
#include "Experiment_MFC_i.h"


// CExperiment_MFCApp:
// О реализации данного класса см. Experiment_MFC.cpp
//

class CExperiment_MFCApp : public CWinApp
{
public:
	CExperiment_MFCApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment_MFCApp theApp;
