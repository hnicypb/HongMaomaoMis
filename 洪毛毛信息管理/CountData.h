#pragma once
#include "afxdtctl.h"
#include "afxcmn.h"


// CCountData �Ի���

class CCountData : public CDialog
{
	DECLARE_DYNAMIC(CCountData)

public:
	CCountData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCountData();

// �Ի�������
	enum { IDD = IDD_DIALOG_COUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CDateTimeCtrl m_dtBegin;
	CTime m_timeEnd;
	CTime m_timeBegin;

	void fRefresh();
	CListCtrl m_listName;
	CListCtrl m_listType;
	CListCtrl m_listOffice;
	CListCtrl m_listOffice2;


	map<CString,DWORD> m_mapName;
	map<CString,DWORD> m_mapType;
	map<CString,DWORD> m_mapOffice;
	map<CString,DWORD> m_mapOffice2;
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList4(NMHDR *pNMHDR, LRESULT *pResult);
};
