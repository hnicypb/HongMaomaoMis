
// 洪毛毛信息管理Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "洪毛毛信息管理.h"
#include "洪毛毛信息管理Dlg.h"
#include "Markup.h"
#include "EditData.h"
#include "CountData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// C洪毛毛信息管理Dlg 对话框

//************************************************************************************
//函    数：fGetAppPath()      
//功    能：当前应用运行路径
//参    数：
//返    回: 当前应用运行路径
//************************************************************************************
CString fCommGetAppPath()
{
	CString strPath;
	GetModuleFileName(NULL,strPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	strPath.ReleaseBuffer();
	int pos = strPath.ReverseFind('\\');
	strPath = strPath.Left(pos);
	return strPath;
}


// 检查文件是否存在
BOOL fCommIsExistFile(CString strFullPathName)
{
	if(::GetFileAttributes(strFullPathName) == 0xFFFFFFFF)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	} 
}


C洪毛毛信息管理Dlg::C洪毛毛信息管理Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C洪毛毛信息管理Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C洪毛毛信息管理Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listData);
	DDX_Control(pDX, IDOK, m_btnAdd);
	DDX_Control(pDX, ID_DEL, m_btnDel);
	DDX_Control(pDX, ID_COUNT, m_btnCount);
	DDX_Control(pDX, IDCANCEL, m_btnExit);
}

BEGIN_MESSAGE_MAP(C洪毛毛信息管理Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &C洪毛毛信息管理Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &C洪毛毛信息管理Dlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &C洪毛毛信息管理Dlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(ID_COUNT, &C洪毛毛信息管理Dlg::OnBnClickedCount)
	ON_BN_CLICKED(ID_DEL, &C洪毛毛信息管理Dlg::OnBnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &C洪毛毛信息管理Dlg::OnNMDblclkList1)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &C洪毛毛信息管理Dlg::OnHdnItemdblclickList1)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// C洪毛毛信息管理Dlg 消息处理程序

BOOL C洪毛毛信息管理Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_listData.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listData.InsertColumn(0,_T("日期"),LVCFMT_LEFT,170);
	m_listData.InsertColumn(1,_T("姓名"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(2,_T("办公室"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(3,_T("处室"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(4,_T("电话"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(5,_T("工作类型"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(6,_T("工作内容"),LVCFMT_LEFT,500);
	m_listData.SetFocus();

	m_strXmlFile = fCommGetAppPath() + _T("\\database.xml");
	m_strSqliteDbFile = fCommGetAppPath() + _T("\\database.db");

	GetClientRect(&m_rect);
	m_pointOld.x = m_rect.right - m_rect.left;
	m_pointOld.y = m_rect.bottom - m_rect.top;

	CMarkup xml;
	if (!fCommIsExistFile(m_strXmlFile))
	{
		//if(MessageBox(_T("未找到数据，是否初始化？"),_T("提示"),MB_YESNO) == IDYES)
		//{
			xml.ResetMainPos();
			xml.AddElem(_T("ROOT"));

			xml.AddChildElem(_T("工作类型"));
			xml.IntoElem();
			xml.AddChildElem(_T("类型"));
			xml.AddChildAttrib(_T("名称"),_T("日常维护"));
			xml.OutOfElem();

			xml.AddChildElem(_T("工作列表"));

			xml.Save(m_strXmlFile);

		//}
		//else
		//	CDialog::OnCancel();

	}

	if (xml.Load(m_strXmlFile))
	{		
		xml.ResetMainPos();
		xml.FindElem();	
		if(xml.FindChildElem(_T("工作类型")))
		{
			xml.IntoElem();
			while (xml.FindChildElem(_T("类型")))
			{
				m_vecDataType.push_back(xml.GetChildAttrib(_T("名称")));
			}
			xml.OutOfElem();
		}

		if(xml.FindChildElem(_T("工作列表")))
		{
			xml.IntoElem();
			
			while (xml.FindChildElem(_T("工作")))
			{
				tagDataDetail tagData;
				tagData.strDate = xml.GetChildAttrib(_T("日期"));
				tagData.strName = xml.GetChildAttrib(_T("姓名"));
				tagData.strOffice = xml.GetChildAttrib(_T("办公室"));
				tagData.strOffice2 = xml.GetChildAttrib(_T("处室"));
				tagData.strTel = xml.GetChildAttrib(_T("电话"));
				tagData.strType = xml.GetChildAttrib(_T("工作类型"));
				tagData.strDetail = xml.GetChildAttrib(_T("工作内容"));
				tagData.iStatus = DATA_OLD;

				m_vecData.push_back(tagData);					
			}
			xml.OutOfElem();
		}

		fRefreshData();
	}



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C洪毛毛信息管理Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C洪毛毛信息管理Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C洪毛毛信息管理Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C洪毛毛信息管理Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CEditData dlgEdit;
	if(dlgEdit.DoModal() == IDOK)
	{
		tagDataDetail tagData;
		tagData.strName = dlgEdit.m_strName;
		tagData.strTel = dlgEdit.m_strTel;
		tagData.strOffice = dlgEdit.m_strOffice;
		tagData.strOffice2 = dlgEdit.m_strOffice2;
		tagData.strType = dlgEdit.m_strType;
		tagData.strDetail = dlgEdit.m_strDetail;

		CTime time = CTime::GetCurrentTime();
		tagData.strDate.Format(_T("%04d%02d%02d %02d:%02d:%02d"),time.GetYear(),time.GetMonth(),time.GetDay(),time.GetHour(),time.GetMinute(),time.GetSecond());

		tagData.iStatus = DATA_NEW;

		m_vecData.push_back(tagData);

		fRefreshData();
	}

}

void C洪毛毛信息管理Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	fSaveData();

	OnCancel();
}

void C洪毛毛信息管理Dlg::fRefreshData()
{
	m_listData.DeleteAllItems();
	for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
	{
		if (it->iStatus != DATA_DEL)
		{
			int iRow = m_listData.InsertItem(0,it->strDate);
			m_listData.SetItemText(iRow,1,it->strName);
			m_listData.SetItemText(iRow,2,it->strOffice);
			m_listData.SetItemText(iRow,3,it->strOffice2);
			m_listData.SetItemText(iRow,4,it->strTel);
			m_listData.SetItemText(iRow,5,it->strType);
			m_listData.SetItemText(iRow,6,it->strDetail);
		}
	}
}

void C洪毛毛信息管理Dlg::fSaveData()
{
	
	CMarkup xml;
	if (fCommIsExistFile(m_strXmlFile))
	{
		if (xml.Load(m_strXmlFile))
		{		
			xml.ResetMainPos();
			xml.FindElem();				
			if(xml.FindChildElem(_T("工作列表")))
			{
				xml.IntoElem();

				while(xml.FindChildElem(_T("工作")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}

			xml.ResetMainPos();
			xml.FindElem();	
			if(xml.FindChildElem(_T("工作列表")))
			{
				xml.IntoElem();

				for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
				{
					if (it->iStatus != DATA_DEL)
					{
						xml.AddChildElem(_T("工作"));
						xml.AddChildAttrib(_T("日期"),it->strDate);
						xml.AddChildAttrib(_T("姓名"),it->strName);
						xml.AddChildAttrib(_T("办公室"),it->strOffice);
						xml.AddChildAttrib(_T("处室"),it->strOffice2);
						xml.AddChildAttrib(_T("电话"),it->strTel);
						xml.AddChildAttrib(_T("工作类型"),it->strType);
						xml.AddChildAttrib(_T("工作内容"),it->strDetail);
					}
				}

				xml.OutOfElem();
			}
			
			xml.Save(m_strXmlFile);
		}
	}

}
void C洪毛毛信息管理Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if(pNMLV->uChanged == LVIF_STATE)
	{
		if(pNMLV->uNewState)
		{
			int nIndex = pNMLV->iItem;
			
			m_listData.SetItemState(nIndex, LVIS_FOCUSED | LVIS_SELECTED,LVIS_FOCUSED | LVIS_SELECTED);   //选中行
			m_listData.SetSelectionMark(nIndex);
		}

	}
	*pResult = 0;
}

void C洪毛毛信息管理Dlg::OnBnClickedCount()
{
	// TODO: 在此添加控件通知处理程序代码
	CCountData dlgCount;
	dlgCount.DoModal();
}

void C洪毛毛信息管理Dlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strDate = m_listData.GetItemText(m_listData.GetSelectionMark(),0);

	for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
	{
		if (it->strDate == strDate)
		{
			it->iStatus = DATA_DEL;
			fRefreshData();
			break;
		}
	}

}

void C洪毛毛信息管理Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	int iIndex = m_listData.GetSelectionMark();
	CString strDate = m_listData.GetItemText(iIndex,0);
	CEditData dlgEdit;
	dlgEdit.m_strName = m_listData.GetItemText(iIndex,1);
	dlgEdit.m_strTel = m_listData.GetItemText(iIndex,2);
	dlgEdit.m_strOffice = m_listData.GetItemText(iIndex,3);
	dlgEdit.m_strOffice2 = m_listData.GetItemText(iIndex,4);
	dlgEdit.m_strType = m_listData.GetItemText(iIndex,5);
	dlgEdit.m_strDetail = m_listData.GetItemText(iIndex,6);

	if(dlgEdit.DoModal() == IDOK)
	{
		for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
		{
			if (it->strDate == strDate)
			{
				it->strName = dlgEdit.m_strName;
				it->strTel = dlgEdit.m_strTel;
				it->strOffice = dlgEdit.m_strOffice;
				it->strOffice2 = dlgEdit.m_strOffice2;
				it->strType = dlgEdit.m_strType;
				it->strDetail = dlgEdit.m_strDetail;
				fRefreshData();
				break;
			}
		}
	}

}

void C洪毛毛信息管理Dlg::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}

void C洪毛毛信息管理Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	m_listData.MoveWindow(CRect(5,5,cx-5,cy-80));

	CRect rectTemp;
	m_listData.GetClientRect(&rectTemp);

	CRect rectBtn;
	m_btnAdd.GetClientRect(&rectBtn);

	m_btnAdd.MoveWindow(CRect(5,rectTemp.bottom+10,5+rectBtn.Width(),rectTemp.bottom+rectBtn.Height()));

	//resize();
	

}

void C洪毛毛信息管理Dlg::resize()
{
	float fsp[2]; //用于分别记录窗口发生变化的长宽新旧比
	CPoint Newp; //获取现在对话框的大小
	CRect recta;  
	GetClientRect(&recta);     //取客户区大小
	Newp.x=recta.right-recta.left;
	Newp.y=recta.bottom-recta.top;
	fsp[0]=(float)Newp.x/m_pointOld.x;//计算长度的新旧比
	fsp[1]=(float)Newp.y/m_pointOld.y;//计算高度的新旧比
	CRect rectb;
	int woc;
	CPoint OldTLPoint,TLPoint; //左上角
	CPoint OldBRPoint,BRPoint; //右下角
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //取得第一个控件的句柄,用于遍历所有控件
	while(hwndChild)  
	{  
		woc=::GetDlgCtrlID(hwndChild);//取得ID
		GetDlgItem(woc)->GetWindowRect(rectb); //获得相对于屏幕左上角的坐标
		ScreenToClient(rectb);//将屏幕坐标转换成相对客户窗口左上角的坐标
		OldTLPoint = rectb.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]); //用比例得出左上角的x坐标
		TLPoint.y = long(OldTLPoint.y*fsp[1]); //用比例得出左上角的y坐标
		OldBRPoint = rectb.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]); //用比例得出右下角的x坐标
		BRPoint.y = long(OldBRPoint.y *fsp[1]); //用比例得出右下角的y坐标
		rectb.SetRect(TLPoint,BRPoint); //设置最新的Rect
		GetDlgItem(woc)->MoveWindow(rectb,TRUE);
		hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);  //获得下一个控件的句柄
	}
	m_pointOld=Newp;

}
