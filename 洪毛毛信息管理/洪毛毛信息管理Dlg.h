
// ��ëë��Ϣ����Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

//************************************************************************************
// ��ǰӦ������·��
CString fCommGetAppPath();

// ����ļ��Ƿ����
BOOL fCommIsExistFile(CString strFullPathName);
//************************************************************************************

enum DATA_STATUS
{
	DATA_OLD,
	DATA_NEW,
	DATA_MODIFY,
	DATA_DEL,
};

struct tagDataDetail
{
	CString strDate;

	CString strName;
	CString strTel;
	CString strOffice;
	CString strOffice2;
	CString strType;
	CString strDetail;
	CString strMemo;

	int iStatus;
		
};


// C��ëë��Ϣ����Dlg �Ի���
class C��ëë��Ϣ����Dlg : public CDialog
{
// ����
public:
	C��ëë��Ϣ����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CString m_strXmlFile;
	CString m_strSqliteDbFile;

	CPoint m_pointOld;
	CRect  m_rect;   //���ڱ���ԭ�Ի����С
	
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CListCtrl m_listData;

	vector<tagDataDetail> m_vecData;
	vector<CString> m_vecDataType;

	void fRefreshData();
	void fSaveData();
	void resize();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCount();
	afx_msg void OnBnClickedDel();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButton m_btnAdd;
	CButton m_btnDel;
	CButton m_btnCount;
	CButton m_btnExit;
};
