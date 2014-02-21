//
// CTestDlg.h : header file
//

#pragma once
#include "afxcmn.h"


// CTestDlg dialog
class CTestDlg : public CDialog
{
// Construction
public:
   CTestDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
   enum
   {
      IDD = IDD_TEST_DIALOG
   };

   CListCtrl m_ListCtrl;
   CString m_szTest;
   CString m_szDbFile;
protected:
   virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV support
//
// Implementation
//
protected:
   HICON m_hIcon;

   // Generated message map functions
   virtual BOOL OnInitDialog();
   afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
   afx_msg void OnPaint();
   afx_msg HCURSOR OnQueryDragIcon();
   afx_msg void OnPbCreate();
   afx_msg void OnPbReview();
   DECLARE_MESSAGE_MAP()
};

