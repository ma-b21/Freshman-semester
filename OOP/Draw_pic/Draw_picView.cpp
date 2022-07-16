
// Draw_picView.cpp: CDrawpicView 类的实现
//
#include<cmath>
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw_pic.h"
#endif

#include "Draw_picDoc.h"
#include "Draw_picView.h"
#include"Six_star.h"
#include"Circle.h"
#include"Six_flower.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawpicView

IMPLEMENT_DYNCREATE(CDrawpicView, CView)

BEGIN_MESSAGE_MAP(CDrawpicView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDrawpicView 构造/析构

CDrawpicView::CDrawpicView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDrawpicView::~CDrawpicView()
{
}

BOOL CDrawpicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawpicView 绘图

void CDrawpicView::OnDraw(CDC* pDC)
{
	CDrawpicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	COLORREF color1 = RGB(0, 0, 255);
	COLORREF color2 = RGB(0, 225, 225);
	COLORREF color3 = RGB(255, 0, 0);
	COLORREF color4 = RGB(255, 255, 0);
	CPen pen1(PS_DASH, 3, color3);
	CPen pen2(PS_DASH, 3, color1);
	CBrush brush1(HS_DIAGCROSS, color2);
	CBrush brush2(HS_DIAGCROSS, color4);

	pDC->SelectObject(&brush2);
	pDC->SelectObject(&pen2);
	Circle d(600 / (2* sqrt(3)), 600, 300);
	d.Draw_circle(pDC);

	pDC->SelectObject(&pen1);
	Six_star b(200, 600, 300);
	b.Draw_star(pDC);
	flower c(200, 600, 300);
	c.Draw_flower(pDC);

	pDC->SelectObject(&brush1);
	pDC->SelectObject(&pen2);
	Circle a(200 / (2*sqrt(3)), 600, 300);
	a.Draw_circle(pDC);

}


// CDrawpicView 打印

BOOL CDrawpicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawpicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawpicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawpicView 诊断

#ifdef _DEBUG
void CDrawpicView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawpicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawpicDoc* CDrawpicView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawpicDoc)));
	return (CDrawpicDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawpicView 消息处理程序
