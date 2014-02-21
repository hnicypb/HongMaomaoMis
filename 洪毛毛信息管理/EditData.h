#pragma once
#include "afxwin.h"


// CEditData �Ի���

class CEditData : public CDialog
{
	DECLARE_DYNAMIC(CEditData)

public:
	CEditData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditData();

// �Ի�������
	enum { IDD = IDD_DIALOG_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_editName;
	CEdit m_editTel;
	CEdit m_editOffice;
	CEdit m_editOffice2;
	CComboBox m_comboxType;
	CEdit m_editDetail;
	CString m_strName;
	CString m_strTel;
	CString m_strOffice;
	CString m_strOffice2;
	CString m_strType;
	CString m_strDetail;
	afx_msg void OnEnChangeEditName();
};
