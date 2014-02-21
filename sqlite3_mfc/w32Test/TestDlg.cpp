//
// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestApp.h"
#include "TestDlg.h"
#include "DbSQLite.h"

#ifdef _DEBUG
   #define new DEBUG_NEW
#endif

//
// CTestDlg dialog
//

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTestDlg::IDD, pParent)
{
   m_szTest = _T("");
   m_szDbFile = _T("SQLite3Test.db");
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   DDX_Text(pDX, IDC_EDIT1, m_szTest);
   DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   //}}AFX_MSG_MAP
   ON_BN_CLICKED(IDC_PB_CREATE, OnPbCreate)
   ON_BN_CLICKED(IDC_PB_REVIEW, OnPbReview)
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);       // Set big icon
   SetIcon(m_hIcon, FALSE);      // Set small icon

   // TODO: Add extra initialization here

   return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
   if ( IsIconic() )
   {
      CPaintDC dc(this); // device context for painting

      SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

      // Center icon in client rectangle
      int cxIcon = GetSystemMetrics(SM_CXICON);
      int cyIcon = GetSystemMetrics(SM_CYICON);
      CRect rect;
      GetClientRect(&rect);
      int x = (rect.Width() - cxIcon + 1) / 2;
      int y = (rect.Height() - cyIcon + 1) / 2;

      // Draw the icon
      dc.DrawIcon(x, y, m_hIcon);
   }
   else
   {
      CDialog::OnPaint();
   }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
   return static_cast<HCURSOR>(m_hIcon);
}

void
CTestDlg::OnPbCreate()
{
   bool fTest;
   CDbSQLite sqlite;

   fTest = sqlite.Open(m_szDbFile);

   if (!fTest)
   {
      CString szError = _T("Could not open ");
      szError += m_szDbFile;
      AfxMessageBox(szError);
      return;
   }

   m_szTest = _T("CREATED");
   fTest = sqlite.DirectStatement(_T("CREATE TABLE foo (bar, baz, Name)"));

   if (!fTest)
   {
      AfxMessageBox(_T("Couldn't create table foo"));
   }

   CString szQuery;

   szQuery = _T("INSERT INTO foo VALUES (2, 3, 'John Q. Public')");

   fTest = sqlite.DirectStatement(szQuery);

   if (!fTest)
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   szQuery = _T("INSERT INTO foo VALUES (4, 2, 'Lizzie Borden')");

   fTest = sqlite.DirectStatement(szQuery);

   if (!fTest)
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   szQuery = _T("INSERT INTO foo VALUES (6, 1, 'Last Entry')");

   fTest = sqlite.DirectStatement(szQuery);

   if (!fTest)
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   UpdateData(FALSE);
}

void
CTestDlg::OnPbReview()
{
   BOOL fTest;
   CDbSQLite sqlite;

   fTest = sqlite.Open(m_szDbFile);

   if (!fTest)
   {
      CString szError = _T("Could not open ");
      szError += m_szDbFile;
      AfxMessageBox(szError);
      return;
   }

   m_szTest = _T("INVALID STATEMENT");
   CSqlStatement* stmt = sqlite.Statement(_T("SELECT * FROM foo"));
   //
   // Now we will populate the listbox if the statment is not NULL.
   //
   if (stmt != NULL)
   {
      m_ListCtrl.DeleteAllItems();
      while(m_ListCtrl.DeleteColumn(0));
      CRect rect;
      m_ListCtrl.GetWindowRect(&rect);
      int nFields = stmt->Fields();
      int nWidth = rect.Width() * 1 / (nFields + 1);
      int nCol = 0;
      int nRow = 0;
      CString szText;

      m_ListCtrl.InsertColumn(0, _T("ROW ID"), LVCFMT_LEFT, nWidth, 0);

      for(nCol=0; nCol < nFields; nCol++)
      {
         szText = stmt->FieldName(nCol);
         szText.MakeUpper();
         m_ListCtrl.InsertColumn(nCol+1, szText, LVCFMT_LEFT, nWidth, nCol+1);
      }

      while (stmt->NextRow())
      {
         szText.Format(_T("%d"), nRow + 1);
         m_ListCtrl.InsertItem(nRow, szText);

         for(nCol=0; nCol < nFields; nCol++)
         {
            szText = stmt->ValueString(nCol);
            m_ListCtrl.SetItem(nRow, nCol+1, LVIF_TEXT, szText, 0,0,0,0);
         }

         ++nRow;
      }

      m_szTest = _T("COMPLETE");
   }

   UpdateData(FALSE);
}

