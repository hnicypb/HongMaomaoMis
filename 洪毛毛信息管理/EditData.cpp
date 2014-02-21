// EditData.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ëë��Ϣ����.h"
#include "EditData.h"
#include "��ëë��Ϣ����Dlg.h"


// CEditData �Ի���

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


// CEditData ��Ϣ�������

BOOL CEditData::OnInitDialog()
{
	CDialog::OnInitDialog();

	C��ëë��Ϣ����Dlg * pDlg = (C��ëë��Ϣ����Dlg *)theApp.m_pMainWnd;
	for (vector<CString>::iterator it = pDlg->m_vecDataType.begin();it!=pDlg->m_vecDataType.end();it++)
	{
		m_comboxType.InsertString(0,*it);
	}

	this->UpdateData(FALSE);
	return TRUE;
}

void CEditData::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData();

	if (m_strName == _T(""))
	{
		AfxMessageBox(_T("�ף���û���������֣�"));
		m_editName.SetFocus();
		return;
	}
	if (m_strType == _T(""))
	{
		AfxMessageBox(_T("�ף���������ûѡ��"));
		m_comboxType.SetFocus();
		return;
	}

	CDialog::OnOK();
}

void CEditData::OnEnChangeEditName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	C��ëë��Ϣ����Dlg * pDlg = (C��ëë��Ϣ����Dlg *)theApp.m_pMainWnd;
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
