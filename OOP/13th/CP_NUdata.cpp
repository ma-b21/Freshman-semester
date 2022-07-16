#include "CP_NUdata.h"

void NUdata::Add_Student(vector<CP_Student> &delec)
{
	CP_ChainDoubleLink* q;
	for (int i = 0; i < delec.size(); i++)
	{
		q = m_head->mb_createNode();
		if (q != NULL)
			q->m_data = delec[i];
		else cout << "�ڴ�����ʧ��!" << endl;
	}
	delec.clear();
}

void NUdata::Show_all()
{
    cout << endl << "���ñ���" << endl;
    if (m_head == NULL)
    {
        cout << "Ŀǰ��û��ѧ����" << endl;
        return;
    } // if����
    if (m_head->m_previous == NULL)
    {
        cout << "Ŀǰ��û��ѧ����" << endl;
        return;
    } // if����
    CP_ChainDoubleLink* h = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "]: ѧ��(" << h->m_data.m_ID
            << "), �ɼ�(" << h->m_data.m_score << ")" << endl;
        h = h->m_next;
        n++;
    } while (h != m_head);
    cout << endl;
}


