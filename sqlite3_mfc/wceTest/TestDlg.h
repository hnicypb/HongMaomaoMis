// TestDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__03F16F3F_FFBA_428A_8AF6_A9FAAAD61839__INCLUDED_)
#define AFX_TESTDLG_H__03F16F3F_FFBA_428A_8AF6_A9FAAAD61839__INCLUDED_

#if _MSC_VER >= 1000
   #pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
   CTestDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
   //{{AFX_DATA(CTestDlg)
   enum
   {
      IDD = IDD_WCETEST_DIALOG
   };
   CListCtrl m_ListCtrl;
   CString m_szTest;
   CString m_szDbFile;
   //}}AFX_DATA

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CTestDlg)
protected:
   virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:
   HICON m_hIcon;

   // Generated message map functions
   //{{AFX_MSG(CTestDlg)
   virtual BOOL OnInitDialog();
   afx_msg void OnPbCreate();
   afx_msg void OnPbReview();
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__03F16F3F_FFBA_428A_8AF6_A9FAAAD61839__INCLUDED_)

