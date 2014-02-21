// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestApp.h"
#include "TestDlg.h"
#include "DbSQLite.h"

#ifdef _DEBUG
   #define new DEBUG_NEW
   #undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTestDlg::IDD, pParent)
{
   //{{AFX_DATA_INIT(CTestDlg)
   m_szTest = _T("");
   m_szDbFile = _T("SQLite3Test.db");
   //}}AFX_DATA_INIT
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CTestDlg)
   DDX_Text(pDX, IDC_EDIT1, m_szTest);
   DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
//{{AFX_MSG_MAP(CTestDlg)
   ON_BN_CLICKED(IDC_PB_CREATE, OnPbCreate)
   ON_BN_CLICKED(IDC_PB_REVIEW, OnPbReview)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);       // Set big icon
   SetIcon(m_hIcon, FALSE);      // Set small icon

   CenterWindow(GetDesktopWindow());   // center to the hpc screen

   // TODO: Add extra initialization here

   return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnPbCreate() 
{
   bool fTest;
   CDbSQLite sqlite;

   fTest = sqlite.Open(m_szDbFile);

   if ( !fTest )
   {
      CString szError = _T("Could not open ");
      szError += m_szDbFile;
      AfxMessageBox(szError);
      return;
   }

   m_szTest = _T("CREATED");
   fTest = sqlite.DirectStatement(_T("CREATE TABLE foo (bar, baz, Name)"));

   if ( !fTest )
   {
      AfxMessageBox(_T("Couldn't create table foo"));
   }

   CString szQuery;

   szQuery = _T("INSERT INTO foo VALUES (2, 3, 'John Q. Public')");

   fTest = sqlite.DirectStatement(szQuery);

   if ( !fTest )
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   szQuery = _T("INSERT INTO foo VALUES (4, 2, 'Lizzie Borden')");

   fTest = sqlite.DirectStatement(szQuery);

   if ( !fTest )
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   szQuery = _T("INSERT INTO foo values (6, 1, 'Last Entry')");

   fTest = sqlite.DirectStatement(szQuery);

   if ( !fTest )
   {
      m_szTest = _T("FAILURE: ");
      m_szTest += szQuery;
      AfxMessageBox(m_szTest);
   }

   UpdateData(FALSE);
}

void CTestDlg::OnPbReview() 
{
   BOOL fTest;
   CDbSQLite sqlite;

   fTest = sqlite.Open(m_szDbFile);

   if ( !fTest )
   {
      CString szError = _T("Could not open ");
      szError += m_szDbFile;
      AfxMessageBox(szError);
      return;
   }

   m_szTest = _T("INVALID STATEMENT");
   CSqlStatement* stmt = sqlite.Statement(_T("SELECT * FROM foo"));

   if ( stmt != NULL )
   {
      m_ListCtrl.DeleteAllItems();
      while ( m_ListCtrl.DeleteColumn(0) );
      CRect rect;
      m_ListCtrl.GetWindowRect(&rect);
      int nFields = stmt->Fields();
      int nWidth = rect.Width() * 1 / (nFields + 1);
      int nCol = 0;
      int nRow = 0;
      CString szText;

      m_ListCtrl.InsertColumn(0, _T("ROW ID"), LVCFMT_LEFT, nWidth, 0);

      for ( nCol=0; nCol < nFields; nCol++ )
      {
         szText = stmt->FieldName(nCol);
         szText.MakeUpper();
         m_ListCtrl.InsertColumn(nCol+1, szText, LVCFMT_LEFT, nWidth, nCol+1);
      }

      while ( stmt->NextRow() )
      {
         szText.Format(_T("%d"), nRow + 1);
         m_ListCtrl.InsertItem(nRow, szText);

         for ( nCol=0; nCol < nFields; nCol++ )
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