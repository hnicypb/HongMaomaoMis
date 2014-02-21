// CountData.cpp : 实现文件
//

#include "stdafx.h"
#include "洪毛毛信息管理.h"
#include "CountData.h"
#include "洪毛毛信息管理Dlg.h"


// CCountData 对话框

IMPLEMENT_DYNAMIC(CCountData, CDialog)

CCountData::CCountData(CWnd* pParent /*=NULL*/)
	: CDialog(CCountData::IDD, pParent)
	, m_timeEnd(0)
	, m_timeBegin(0)
{

}

CCountData::~CCountData()
{
}

void CCountData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_dtBegin);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_timeEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_timeBegin);
	DDX_Control(pDX, IDC_LIST1, m_listName);
	DDX_Control(pDX, IDC_LIST2, m_listType);
	DDX_Control(pDX, IDC_LIST3, m_listOffice2);
	DDX_Control(pDX, IDC_LIST4, m_listOffice);
}


BEGIN_MESSAGE_MAP(CCountData, CDialog)
	ON_BN_CLICKED(IDOK, &CCountData::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCountData::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCountData 消息处理程序

BOOL CCountData::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_listName.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listName.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,100);
	m_listName.InsertColumn(1,_T("总计"),LVCFMT_LEFT,60);

	m_listType.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listType.InsertColumn(0,_T("类型"),LVCFMT_LEFT,100);
	m_listType.InsertColumn(1,_T("总计"),LVCFMT_LEFT,60);

	m_listOffice.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listOffice.InsertColumn(0,_T("办公室"),LVCFMT_LEFT,100);
	m_listOffice.InsertColumn(1,_T("总计"),LVCFMT_LEFT,60);

	m_listOffice2.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listOffice2.InsertColumn(0,_T("科室"),LVCFMT_LEFT,100);
	m_listOffice2.InsertColumn(1,_T("总计"),LVCFMT_LEFT,60);


	m_timeEnd = CTime::GetCurrentTime();
	m_timeBegin = CTime(m_timeEnd.GetYear(),m_timeEnd.GetMonth(),1,0,0,0);
	UpdateData(FALSE);

	return TRUE;
}

void CCountData::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();

	CString strTimeBegin;
	CString strTimeEnd;
	strTimeBegin.Format(_T("%04d%02d%02d %02d:%02d:%02d"),m_timeBegin.GetYear(),m_timeBegin.GetMonth(),m_timeBegin.GetDay(),m_timeBegin.GetHour(),m_timeBegin.GetMinute(),m_timeBegin.GetSecond());
	strTimeEnd.Format(_T("%04d%02d%02d %02d:%02d:%02d"),m_timeEnd.GetYear(),m_timeEnd.GetMonth(),m_timeEnd.GetDay(),m_timeEnd.GetHour(),m_timeEnd.GetMinute(),m_timeEnd.GetSecond());
	C洪毛毛信息管理Dlg * pDlg = (C洪毛毛信息管理Dlg *)theApp.m_pMainWnd;

	m_mapName.clear();
	m_mapType.clear();
	m_mapOffice.clear();
	m_mapOffice2.clear();

	for (vector<tagDataDetail>::iterator it = pDlg->m_vecData.begin();it!=pDlg->m_vecData.end();it++)
	{
		if (it->strDate >= strTimeBegin && it->strDate <= strTimeEnd && it->iStatus != DATA_DEL)
		{
			if (m_mapName.find(it->strName) == m_mapName.end())
				m_mapName.insert(pair<CString,DWORD>(it->strName,1));
			else
				m_mapName[it->strName]++;

			if (m_mapType.find(it->strType) == m_mapType.end())
				m_mapType.insert(pair<CString,DWORD>(it->strType,1));
			else
				m_mapType[it->strType]++;

			if (m_mapOffice.find(it->strOffice) == m_mapOffice.end())
				m_mapOffice.insert(pair<CString,DWORD>(it->strOffice,1));
			else
				m_mapOffice[it->strOffice]++;

			if (m_mapOffice2.find(it->strOffice2) == m_mapOffice2.end())
				m_mapOffice2.insert(pair<CString,DWORD>(it->strOffice2,1));
			else
				m_mapOffice2[it->strOffice2]++;
		}
	}


	m_listName.DeleteAllItems();
	for (map<CString,DWORD>::iterator it = m_mapName.begin();it!=m_mapName.end();it++)
	{
		int iRow = m_listName.InsertItem(0,it->first);
		CString strValue;
		strValue.Format(_T("%d"),it->second);
		m_listName.SetItemText(iRow,1,strValue);		
	}

	m_listType.DeleteAllItems();
	for (map<CString,DWORD>::iterator it = m_mapType.begin();it!=m_mapType.end();it++)
	{
		int iRow = m_listType.InsertItem(0,it->first);
		CString strValue;
		strValue.Format(_T("%d"),it->second);
		m_listType.SetItemText(iRow,1,strValue);		
	}

	m_listOffice.DeleteAllItems();
	for (map<CString,DWORD>::iterator it = m_mapOffice.begin();it!=m_mapOffice.end();it++)
	{
		int iRow = m_listOffice.InsertItem(0,it->first);
		CString strValue;
		strValue.Format(_T("%d"),it->second);
		m_listOffice.SetItemText(iRow,1,strValue);		
	}

	m_listOffice2.DeleteAllItems();
	for (map<CString,DWORD>::iterator it = m_mapOffice2.begin();it!=m_mapOffice2.end();it++)
	{
		int iRow = m_listOffice2.InsertItem(0,it->first);
		CString strValue;
		strValue.Format(_T("%d"),it->second);
		m_listOffice2.SetItemText(iRow,1,strValue);		
	}

}

void CCountData::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


void CCountData::fRefresh()
{
}