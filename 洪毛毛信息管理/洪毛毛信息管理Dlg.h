
// 洪毛毛信息管理Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

//************************************************************************************
// 当前应用运行路径
CString fCommGetAppPath();

// 检查文件是否存在
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


// C洪毛毛信息管理Dlg 对话框
class C洪毛毛信息管理Dlg : public CDialog
{
// 构造
public:
	C洪毛毛信息管理Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CString m_strXmlFile;
	CString m_strSqliteDbFile;

	CPoint m_pointOld;
	CRect  m_rect;   //用于保存原对话框大小
	
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
