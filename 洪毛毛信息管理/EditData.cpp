// EditData.cpp : 实现文件
//

#include "stdafx.h"
#include "洪毛毛信息管理.h"
#include "EditData.h"
#include "洪毛毛信息管理Dlg.h"


// CEditData 对话框

IMPLEMENT_DYNAMIC(CEditData, CDialog)

CEditData::CEditData(CWnd* pParent /*=NULL*/)
	: CDialog(CEditData::IDD, pParent)
	, m_strName(_T(""))
	, m_strTel(_T(""))
	, m_strOffice(_T(""))
	, m_strOffice2(_T(""))
	, m_strType(_T(""))
	, m_strDetail(_T(""))
{

}

CEditData::~CEditData()
{
}

void CEditData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, m_editName);
	DDX_Control(pDX, IDC_EDIT_TEL, m_editTel);
	DDX_Control(pDX, IDC_EDIT_OFFICE, m_editOffice);
	DDX_Control(pDX, IDC_EDIT_OFFICE2, m_editOffice2);
	DDX_Control(pDX, IDC_COMBO_TYPE, m_comboxType);
	DDX_Control(pDX, IDC_EDIT_DETAIL, m_editDetail);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_TEL, m_strTel);
	DDX_Text(pDX, IDC_EDIT_OFFICE, m_strOffice);
	DDX_Text(pDX, IDC_EDIT_OFFICE2, m_strOffice2);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_strType);
	DDX_Text(pDX, IDC_EDIT_DETAIL, m_strDetail);
}


BEGIN_MESSAGE_MAP(CEditData, CDialog)
	ON_BN_CLICKED(IDOK, &CEditData::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CEditData::OnEnChangeEditName)
END_MESSAGE_MAP()


// CEditData 消息处理程序

BOOL CEditData::OnInitDialog()
{
	CDialog::OnInitDialog();

	C洪毛毛信息管理Dlg * pDlg = (C洪毛毛信息管理Dlg *)theApp.m_pMainWnd;
	for (vector<CString>::iterator it = pDlg->m_vecDataType.begin();it!=pDlg->m_vecDataType.end();it++)
	{
		m_comboxType.InsertString(0,*it);
	}

	this->UpdateData(FALSE);
	return TRUE;
}

void CEditData::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData();

	if (m_strName == _T(""))
	{
		AfxMessageBox(_T("亲，你没有输入名字！"));
		m_editName.SetFocus();
		return;
	}
	if (m_strType == _T(""))
	{
		AfxMessageBox(_T("亲，工作类型没选择！"));
		m_comboxType.SetFocus();
		return;
	}

	CDialog::OnOK();
}

void CEditData::OnEnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData();
	C洪毛毛信息管理Dlg * pDlg = (C洪毛毛信息管理Dlg *)theApp.m_pMainWnd;
	for (vector<tagDataDetail>::iterator it = pDlg->m_vecData.begin();it!=pDlg->m_vecData.end();it++)
	{
		if (it->strName == m_strName)
		{
			m_strTel = it->strTel;
			m_strOffice = it->strOffice;
			m_strOffice2 = it->strOffice2;

			UpdateData(FALSE);
		}
	}
}
