//
// CTestApp.h : main header file for the w32Test application
//

#pragma once

#ifndef __AFXWIN_H__
   #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CTestApp:
// See CTestApp.cpp for the implementation of this class
//

class CTestApp : public CWinApp
{
public:
   CTestApp();

// Overrides
public:
   virtual BOOL InitInstance();

// Implementation

   DECLARE_MESSAGE_MAP()
};

