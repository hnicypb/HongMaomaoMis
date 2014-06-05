
// ��ëë��Ϣ����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ëë��Ϣ����.h"
#include "��ëë��Ϣ����Dlg.h"
#include "Markup.h"
#include "EditData.h"
#include "CountData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C��ëë��Ϣ����Dlg �Ի���

//************************************************************************************
//��    ����fGetAppPath()      
//��    �ܣ���ǰӦ������·��
//��    ����
//��    ��: ��ǰӦ������·��
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


// ����ļ��Ƿ����
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


C��ëë��Ϣ����Dlg::C��ëë��Ϣ����Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(C��ëë��Ϣ����Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ëë��Ϣ����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listData);
	DDX_Control(pDX, IDOK, m_btnAdd);
	DDX_Control(pDX, ID_DEL, m_btnDel);
	DDX_Control(pDX, ID_COUNT, m_btnCount);
	DDX_Control(pDX, IDCANCEL, m_btnExit);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_timeEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_timeBegin);
	DDX_Control(pDX, IDC_EDIT1, m_editQueryText);
}

BEGIN_MESSAGE_MAP(C��ëë��Ϣ����Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &C��ëë��Ϣ����Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &C��ëë��Ϣ����Dlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &C��ëë��Ϣ����Dlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(ID_COUNT, &C��ëë��Ϣ����Dlg::OnBnClickedCount)
	ON_BN_CLICKED(ID_DEL, &C��ëë��Ϣ����Dlg::OnBnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &C��ëë��Ϣ����Dlg::OnNMDblclkList1)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &C��ëë��Ϣ����Dlg::OnHdnItemdblclickList1)
	ON_WM_SIZE()
	ON_BN_CLICKED(ID_QUERY, &C��ëë��Ϣ����Dlg::OnBnClickedQuery)
END_MESSAGE_MAP()


// C��ëë��Ϣ����Dlg ��Ϣ�������

BOOL C��ëë��Ϣ����Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_listData.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_listData.InsertColumn(0,_T(""),LVCFMT_LEFT,50);
	m_listData.InsertColumn(1,_T("����"),LVCFMT_LEFT,170);
	m_listData.InsertColumn(2,_T("����"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(3,_T("�칫��"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(4,_T("����"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(5,_T("�绰"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(6,_T("��������"),LVCFMT_LEFT,100);
	m_listData.InsertColumn(7,_T("��������"),LVCFMT_LEFT,500);
	m_listData.SetFocus();

	m_timeEnd = CTime::GetCurrentTime();
	m_timeBegin = CTime(2013,1,1,0,0,0);
	UpdateData(FALSE);

	m_strXmlFile = fCommGetAppPath() + _T("\\database.xml");
	m_strSqliteDbFile = fCommGetAppPath() + _T("\\database.db");

	GetClientRect(&m_rect);
	m_pointOld.x = m_rect.right - m_rect.left;
	m_pointOld.y = m_rect.bottom - m_rect.top;

	m_btnAdd.GetClientRect(&m_rectBtn);

	CMarkup xml;
	if (!fCommIsExistFile(m_strXmlFile))
	{
		//if(MessageBox(_T("δ�ҵ����ݣ��Ƿ��ʼ����"),_T("��ʾ"),MB_YESNO) == IDYES)
		//{
			xml.ResetMainPos();
			xml.AddElem(_T("ROOT"));

			xml.AddChildElem(_T("��������"));
			xml.IntoElem();
			xml.AddChildElem(_T("����"));
			xml.AddChildAttrib(_T("����"),_T("�ճ�ά��"));
			xml.OutOfElem();

			xml.AddChildElem(_T("�����б�"));

			xml.Save(m_strXmlFile);

		//}
		//else
		//	CDialog::OnCancel();

	}

	if (xml.Load(m_strXmlFile))
	{		
		xml.ResetMainPos();
		xml.FindElem();	
		if(xml.FindChildElem(_T("��������")))
		{
			xml.IntoElem();
			while (xml.FindChildElem(_T("����")))
			{
				m_vecDataType.push_back(xml.GetChildAttrib(_T("����")));
			}
			xml.OutOfElem();
		}

		if(xml.FindChildElem(_T("�����б�")))
		{
			xml.IntoElem();
			
			while (xml.FindChildElem(_T("����")))
			{
				tagDataDetail tagData;
				tagData.strDate = xml.GetChildAttrib(_T("����"));
				tagData.strName = xml.GetChildAttrib(_T("����"));
				tagData.strOffice = xml.GetChildAttrib(_T("�칫��"));
				tagData.strOffice2 = xml.GetChildAttrib(_T("����"));
				tagData.strTel = xml.GetChildAttrib(_T("�绰"));
				tagData.strType = xml.GetChildAttrib(_T("��������"));
				tagData.strDetail = xml.GetChildAttrib(_T("��������"));
				tagData.iStatus = DATA_OLD;

				m_vecData.push_back(tagData);					
			}
			xml.OutOfElem();
		}

		fRefreshData();
	}

	m_pDlgCount = new CCountData();
	m_pDlgCount->Create(IDD_DIALOG_COUNT);
	m_pDlgCount->ShowWindow(SW_HIDE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ëë��Ϣ����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��ëë��Ϣ����Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C��ëë��Ϣ����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void C��ëë��Ϣ����Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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

void C��ëë��Ϣ����Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	fSaveData();

	OnCancel();
}
// ��һ���ַ�����Ϊvector����bSplitChar�ָ���
vector<CString> fCommStrSplit(CString str, BYTE bSplitChar)
{
	vector<CString> vecList;

	CString strTemp = str; //�˸�ֵ������
	CString strText = _T("");
	int nIndex = 0; //  
	while( 1 )  
	{  
		nIndex = strTemp.Find( bSplitChar );  
		if( nIndex >= 0 )  
		{  
			strText = strTemp.Left( nIndex );
			vecList.push_back(strText);
			strTemp = strTemp.Right( strTemp.GetLength() - nIndex - 1 );  		
		}  
		else 
		{
			//strText = strTemp;
			//vecList.push_back(strText);
			break;  
		}
	}  

	return vecList ;
}

void C��ëë��Ϣ����Dlg::fRefreshData()
{
	m_listData.DeleteAllItems();

	CString strTimeBegin;
	CString strTimeEnd;
	CString strQueryText;
	strTimeBegin.Format(_T("%04d%02d%02d %02d:%02d:%02d"),m_timeBegin.GetYear(),m_timeBegin.GetMonth(),m_timeBegin.GetDay(),m_timeBegin.GetHour(),m_timeBegin.GetMinute(),m_timeBegin.GetSecond());
	strTimeEnd.Format(_T("%04d%02d%02d %02d:%02d:%02d"),m_timeEnd.GetYear(),m_timeEnd.GetMonth(),m_timeEnd.GetDay(),m_timeEnd.GetHour(),m_timeEnd.GetMinute(),m_timeEnd.GetSecond());
	m_editQueryText.GetWindowText(strQueryText);
	strQueryText = strQueryText.TrimLeft(_T(" ")).TrimRight(_T(" "));

	vector<CString> vecQueryText = fCommStrSplit(strQueryText,';');

	CString strIndex;
	BOOL bFind = TRUE;
	for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
	{
		if (it->strDate >= strTimeBegin && it->strDate <= strTimeEnd && it->iStatus != DATA_DEL)
		{
			if (vecQueryText.size()>0)
			{
				for (vector<CString>::iterator it_query=vecQueryText.begin();it_query!=vecQueryText.end();it_query++)
				{
					strQueryText = *it_query;
					if (it->strName.Find(strQueryText,0)>=0 ||
						it->strOffice.Find(strQueryText,0)>=0 ||
						it->strOffice2.Find(strQueryText,0)>=0 ||
						it->strTel.Find(strQueryText,0)>=0 ||
						it->strType.Find(strQueryText,0)>=0 )
					{
						strIndex.Format(_T("%d"),m_listData.GetItemCount()+1);
						int iRow = m_listData.InsertItem(0,strIndex);
						m_listData.SetItemText(iRow,1,it->strDate);
						m_listData.SetItemText(iRow,2,it->strName);
						m_listData.SetItemText(iRow,3,it->strOffice);
						m_listData.SetItemText(iRow,4,it->strOffice2);
						m_listData.SetItemText(iRow,5,it->strTel);
						m_listData.SetItemText(iRow,6,it->strType);
						m_listData.SetItemText(iRow,7,it->strDetail);

						break;
						
					}
				}
			}
			else
			{
				strIndex.Format(_T("%d"),m_listData.GetItemCount()+1);
				int iRow = m_listData.InsertItem(0,strIndex);
				m_listData.SetItemText(iRow,1,it->strDate);
				m_listData.SetItemText(iRow,2,it->strName);
				m_listData.SetItemText(iRow,3,it->strOffice);
				m_listData.SetItemText(iRow,4,it->strOffice2);
				m_listData.SetItemText(iRow,5,it->strTel);
				m_listData.SetItemText(iRow,6,it->strType);
				m_listData.SetItemText(iRow,7,it->strDetail);
			}
		}
	}
}

void C��ëë��Ϣ����Dlg::fSaveData()
{
	
	CMarkup xml;
	if (fCommIsExistFile(m_strXmlFile))
	{
		if (xml.Load(m_strXmlFile))
		{		
			xml.ResetMainPos();
			xml.FindElem();				
			if(xml.FindChildElem(_T("�����б�")))
			{
				xml.IntoElem();

				while(xml.FindChildElem(_T("����")))
					xml.RemoveChildElem();

				xml.OutOfElem();
			}

			xml.ResetMainPos();
			xml.FindElem();	
			if(xml.FindChildElem(_T("�����б�")))
			{
				xml.IntoElem();

				for (vector<tagDataDetail>::iterator it = m_vecData.begin();it!=m_vecData.end();it++)
				{
					if (it->iStatus != DATA_DEL)
					{
						xml.AddChildElem(_T("����"));
						xml.AddChildAttrib(_T("����"),it->strDate);
						xml.AddChildAttrib(_T("����"),it->strName);
						xml.AddChildAttrib(_T("�칫��"),it->strOffice);
						xml.AddChildAttrib(_T("����"),it->strOffice2);
						xml.AddChildAttrib(_T("�绰"),it->strTel);
						xml.AddChildAttrib(_T("��������"),it->strType);
						xml.AddChildAttrib(_T("��������"),it->strDetail);
					}
				}

				xml.OutOfElem();
			}
			
			xml.Save(m_strXmlFile);
		}
	}

}
void C��ëë��Ϣ����Dlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(pNMLV->uChanged == LVIF_STATE)
	{
		if(pNMLV->uNewState)
		{
			int nIndex = pNMLV->iItem;
			
			m_listData.SetItemState(nIndex, LVIS_FOCUSED | LVIS_SELECTED,LVIS_FOCUSED | LVIS_SELECTED);   //ѡ����
			m_listData.SetSelectionMark(nIndex);
		}

	}
	*pResult = 0;
}

void C��ëë��Ϣ����Dlg::OnBnClickedCount()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CCountData dlgCount;
	//dlgCount.DoModal();

	m_pDlgCount->ShowWindow(SW_SHOW);
}

void C��ëë��Ϣ����Dlg::OnBnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strDate = m_listData.GetItemText(m_listData.GetSelectionMark(),1);

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

void C��ëë��Ϣ����Dlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	int iIndex = m_listData.GetSelectionMark();
	CString strDate = m_listData.GetItemText(iIndex,1);
	CEditData dlgEdit;
	dlgEdit.m_strName = m_listData.GetItemText(iIndex,2);
	dlgEdit.m_strTel = m_listData.GetItemText(iIndex,3);
	dlgEdit.m_strOffice = m_listData.GetItemText(iIndex,4);
	dlgEdit.m_strOffice2 = m_listData.GetItemText(iIndex,5);
	dlgEdit.m_strType = m_listData.GetItemText(iIndex,6);
	dlgEdit.m_strDetail = m_listData.GetItemText(iIndex,7);

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

void C��ëë��Ϣ����Dlg::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	*pResult = 0;
}

void C��ëë��Ϣ����Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	CRect rectWin;
	this->GetWindowRect(&rectWin);
	ScreenToClient(&rectWin);
	CRect rectList = CRect(rectWin.left+10,rectWin.top+80,rectWin.right-10,rectWin.bottom-80);
	m_listData.MoveWindow(rectList);

	CRect rectBtnNew = CRect(rectList.left,rectList.bottom+5,rectList.left+m_rectBtn.Width(),rectList.bottom+m_rectBtn.Height()+5);
	m_btnAdd.MoveWindow(rectBtnNew);

	CRect rectBtn;
	m_btnDel.GetWindowRect(&rectBtn);
	ScreenToClient(&rectBtn);
	m_btnDel.MoveWindow(CRect(rectBtn.left,rectBtnNew.top,rectBtn.right,rectBtnNew.bottom));

	m_btnCount.GetWindowRect(&rectBtn);
	ScreenToClient(&rectBtn);
	m_btnCount.MoveWindow(CRect(rectBtn.left,rectBtnNew.top,rectBtn.right,rectBtnNew.bottom));

	m_btnExit.GetWindowRect(&rectBtn);
	ScreenToClient(&rectBtn);
	m_btnExit.MoveWindow(CRect(rectList.right - m_rectBtn.Width(),rectBtnNew.top,rectList.right,rectBtnNew.bottom));



	//resize();
	

}

void C��ëë��Ϣ����Dlg::resize()
{
	float fsp[2]; //���ڷֱ��¼���ڷ����仯�ĳ����¾ɱ�
	CPoint Newp; //��ȡ���ڶԻ���Ĵ�С
	CRect recta;  
	GetClientRect(&recta);     //ȡ�ͻ�����С
	Newp.x=recta.right-recta.left;
	Newp.y=recta.bottom-recta.top;
	fsp[0]=(float)Newp.x/m_pointOld.x;//���㳤�ȵ��¾ɱ�
	fsp[1]=(float)Newp.y/m_pointOld.y;//����߶ȵ��¾ɱ�
	CRect rectb;
	int woc;
	CPoint OldTLPoint,TLPoint; //���Ͻ�
	CPoint OldBRPoint,BRPoint; //���½�
	HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //ȡ�õ�һ���ؼ��ľ��,���ڱ������пؼ�
	while(hwndChild)  
	{  
		woc=::GetDlgCtrlID(hwndChild);//ȡ��ID
		GetDlgItem(woc)->GetWindowRect(rectb); //����������Ļ���Ͻǵ�����
		ScreenToClient(rectb);//����Ļ����ת������Կͻ��������Ͻǵ�����
		OldTLPoint = rectb.TopLeft();
		TLPoint.x = long(OldTLPoint.x*fsp[0]); //�ñ����ó����Ͻǵ�x����
		TLPoint.y = long(OldTLPoint.y*fsp[1]); //�ñ����ó����Ͻǵ�y����
		OldBRPoint = rectb.BottomRight();
		BRPoint.x = long(OldBRPoint.x *fsp[0]); //�ñ����ó����½ǵ�x����
		BRPoint.y = long(OldBRPoint.y *fsp[1]); //�ñ����ó����½ǵ�y����
		rectb.SetRect(TLPoint,BRPoint); //�������µ�Rect
		GetDlgItem(woc)->MoveWindow(rectb,TRUE);
		hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);  //�����һ���ؼ��ľ��
	}
	m_pointOld=Newp;

}

void C��ëë��Ϣ����Dlg::OnBnClickedQuery()
{	
	UpdateData();
	fRefreshData();
}


void C��ëë��Ϣ����Dlg::fAddQueryText(CString strQueryText)
{
	CString strCurrQuery;
	m_editQueryText.GetWindowText(strCurrQuery);
	if (strQueryText!=_T(""))
	{
		if (strCurrQuery.Find(strQueryText)>=0)
			strCurrQuery.Replace(strQueryText+_T(";"),_T(""));
		else
			strCurrQuery = strCurrQuery + strQueryText + _T(";");

		m_editQueryText.SetWindowText(strCurrQuery );
	}

	OnBnClickedQuery();
}

void C��ëë��Ϣ����Dlg::fSetQueryTime(CTime timeBegin,CTime timeEnd)
{
	m_timeEnd = timeEnd;
	m_timeBegin = timeBegin;
	UpdateData(FALSE);

	OnBnClickedQuery();
}