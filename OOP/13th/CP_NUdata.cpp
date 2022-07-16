#include "CP_NUdata.h"

void NUdata::Add_Student(vector<CP_Student> &delec)
{
	CP_ChainDoubleLink* q;
	for (int i = 0; i < delec.size(); i++)
	{
		q = m_head->mb_createNode();
		if (q != NULL)
			q->m_data = delec[i];
		else cout << "内存申请失败!" << endl;
	}
	delec.clear();
}

void NUdata::Show_all()
{
    cout << endl << "备用表单：" << endl;
    if (m_head == NULL)
    {
        cout << "目前还没有学生。" << endl;
        return;
    } // if结束
    if (m_head->m_previous == NULL)
    {
        cout << "目前还没有学生。" << endl;
        return;
    } // if结束
    CP_ChainDoubleLink* h = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "]: 学号(" << h->m_data.m_ID
            << "), 成绩(" << h->m_data.m_score << ")" << endl;
        h = h->m_next;
        n++;
    } while (h != m_head);
    cout << endl;
}


