
// CalculateDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculate.h"
#include "CalculateDlg.h"
#include "afxdialogex.h"
#include"Cpublic.h"

Cpublic Public(0);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculateDlg 对话框



CCalculateDlg::CCalculateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATE_DIALOG, pParent)
	, a(_T("\0"))
	, b("\0")
	, sum(0)
	, remind(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	DDX_Text(pDX, IDC_EDIT3, sum);
	DDX_Text(pDX, IDC_EDIT4, remind);
}

BEGIN_MESSAGE_MAP(CCalculateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CCalculateDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCalculateDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculateDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CCalculateDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculateDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculateDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculateDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculateDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculateDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT4, &CCalculateDlg::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CCalculateDlg 消息处理程序

BOOL CCalculateDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculateDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculateDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculateDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true); bool check = true;
	for (int i = 0; i < a.GetLength(); i++)
	{
		if ((a[i] > '9' || a[i] < '0') && a[i] != '-')
			check = false;
	}
	for (int i = 0; i < b.GetLength(); i++)
	{
		if ((b[i] > '9' || b[i] < '0') && b[i] != '-')
			check = false;
	}
	if (check) 
	{
		switch (Public.lable)
		{
		case 1: remind = "加运算结果为："; sum = (long long)_wtoi(a) + (long long)_wtoi(b); break;
		case 2: remind = "减运算结果为："; sum = (long long)_wtoi(a) - (long long)_wtoi(b); break;
		case 3: remind = "乘运算结果为："; sum = (long long)_wtoi(a) * (long long)_wtoi(b); break;
		case 4: remind = "除运算结果为："; sum = (double)(_wtoi(a)) / _wtoi(b); break;
		default:remind = "请选择运算符"; break;
		}
		Public.lable = 0;
	}
	else 
	{
		remind = "请输入正确的数字！";
	}
	UpdateData(false);
}


void CCalculateDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CCalculateDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculateDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCalculateDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Public.lable = 2;
}


void CCalculateDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	Public.lable = 3;
}


void CCalculateDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Public.lable = 1;
}


void CCalculateDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	Public.lable = 4;
}


void CCalculateDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	a = "\0";
	b = "\0";
	sum = 0;
	UpdateData(false);
}


void CCalculateDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
