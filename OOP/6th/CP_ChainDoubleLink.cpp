#include <iostream>
using namespace std;
#include "CP_ChainDoubleLink.h"

CP_ChainDoubleLink::~CP_ChainDoubleLink()
{
	if (m_previous == NULL)
		return;
	m_previous->m_next = NULL;
	delete m_next;
}

CP_ChainDoubleLink* CP_ChainDoubleLink::mb_createNode()
{
	if (m_previous == NULL)
	{
		m_previous = this;
		m_next = this;
		return this;
	} // if结束
	CP_ChainDoubleLink* pNew = NULL;
	pNew = new(nothrow)CP_ChainDoubleLink;
	if (pNew == NULL) // 申请内存失败
		return NULL;
	CP_ChainDoubleLink* p = m_previous; // p指向尾结点
	m_previous = pNew;
	m_previous->m_next = this;  // this指向首结点
	p->m_next = m_previous;
	m_previous->m_previous = p;
	return pNew;
}

void CP_ChainDoubleLink::mb_deleteNode(CP_ChainDoubleLink* p)
{
	if (m_previous == NULL)
		return;
	CP_ChainDoubleLink* q;
	if (p == this) // 删除第1个记录
	{
		if (p->m_previous == this) // 单节点
		{
			p->m_previous = NULL;
			return;
		} // if结构结束
		m_data = p->m_next->m_data;
		p = p->m_next;
	} // if结构结束
	for (q = m_next; ((q != p) && (q != this));)
	{
		if (q != NULL)
			q = q->m_next;
		else break;
	} // for循环结束
	if (q == this)
		return;
	if (q != p)
		return;
	q = p->m_previous;
	q->m_next = p->m_next;
	q = p->m_next;
	q->m_previous = p->m_previous;
	p->m_previous = p;
	// p->m_next = NULL;
	delete p;
}

CP_ChainDoubleLink* CP_ChainDoubleLink::mb_findNodeById(int id)
{
	if (m_previous == NULL)
		return NULL;
	CP_ChainDoubleLink* p = this;
	do
	{
		if (p->m_data.m_ID == id)
			return p;
		p = p->m_next;
	} while (p != this);
	return NULL;
}

int CP_ChainDoubleLink::mb_getNodeNumber()
{
	if (m_previous == NULL)
		return 0;
	int n = 0;
	CP_ChainDoubleLink* p = this;
	do
	{
		n++;
		p = p->m_next;
	} while (p != this);
	return n;
}

void CP_ChainDoubleLink::mb_sortById()
{
	if (m_previous == NULL)
		return;
	if (m_previous == this)
		return;
	CP_ChainDoubleLink* p = this;
	CP_ChainDoubleLink* q, * q1;
	do
	{
		q = m_previous;
		do
		{
			q1 = q->m_previous;
			if (q1->m_data.m_ID > q->m_data.m_ID)
				gb_swapStudent(q1->m_data, q->m_data);
			q = q1;
		} while (q != p);
		p = p->m_next;
	} while (p != m_previous);
}

void CP_ChainDoubleLink::mb_sortByScore()
{
	if (m_previous == NULL)
		return;
	if (m_previous == this)
		return;
	CP_ChainDoubleLink* p = this;
	CP_ChainDoubleLink* q, * q1;
	do
	{
		q = m_previous;
		do
		{
			q1 = q->m_previous;
			if (q1->m_data.m_score > q->m_data.m_score)
				gb_swapStudent(q1->m_data, q->m_data);
			q = q1;
		} while (q != p);
		p = p->m_next;
	} while (p != m_previous);
}