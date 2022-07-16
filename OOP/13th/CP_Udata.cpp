#include<iostream>
#include "CP_Udata.h"
using namespace std;

void Udata::Add_Student(CP_Student s, CP_ChainDoubleLink* p)
{
    do
    {
        s.m_ID = 0;
        s.m_score = -1;
        cout << "���ѧ����ѧ����ɼ�����0����:";
        cin >> s.m_ID;
        if (s.m_ID > 0)
            cin >> s.m_score;
        if (s.m_ID < 0)
            cout << "ѧ�Ų���С��0" << endl;
        if ((s.m_ID > 0) && (s.m_score < 0))
            cout << "�ɼ�����С��0" << endl;
        if ((s.m_ID > 0) && (s.m_score >= 0))
        {
            p = m_head->mb_createNode();
            if (p != NULL)
                p->m_data = s;
            else cout << "�ڴ�����ʧ��!" << endl;
        } // if����
        if (m_head != NULL)
            m_head->mb_sortById();//��֤ѧ�Ű���������


    } while (s.m_ID > 0);
}

void Udata::Delete_By_num(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec)
{
    cout << "ɾ��ѧ������������λѧ����ѧ��:";
    s.m_ID = -1;
    cin >> s.m_ID;
    if (s.m_ID <= 0)
        cout << "ѧ�ű���Ϊ������!" << endl;
    if (s.m_ID > 0)
    {
        p = m_head->mb_findNodeById(s.m_ID);
        if (p != NULL)
        {
            delec.push_back(p->m_data);
            m_head->mb_deleteNode(p);
        }
        else cout << "û���ҵ���ѧ�ŵ�ѧ����" << endl;
    } // if����
}

void Udata::Delete_By_score(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec)
{
    cout << "����������ɾ����ѧ���ɼ�:";
    cin >> s.m_score;
    //mb_deletebyScore(s.m_score);
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
    p = m_head;
    CP_ChainDoubleLink* q = m_head;
    int n = 1; bool check = false;
    do
    {
        if (q->m_data.m_score == s.m_score)
        {
            p = q->m_next;
            delec.push_back(q->m_data);
            m_head->mb_deleteNode(q);
            q = p;
            check = true;
        }
        else q = q->m_next;
        n++;
    } while (q != m_head);
    if (!check)  cout << "û��ѧ���ɼ�Ϊ" << s.m_score << endl << "��ǰѧ������Ϊ��" << endl;
}

void Udata::Find_By_num(CP_Student s, CP_ChainDoubleLink* p)
{
    cout << "�����������ѯ�ɼ���ѧ����ѧ��:";
    s.m_ID = -1;
    cin >> s.m_ID;
    if (s.m_ID <= 0)
        cout << "ѧ�ű���Ϊ������!" << endl;
    if (s.m_ID > 0)
    {
        p = m_head->mb_findNodeById(s.m_ID);
        if (p != NULL)
            cout << "���ĳɼ�Ϊ:" << p->m_data.m_score << endl;
        else cout << "û���ҵ���ѧ�ŵ�ѧ����" << endl;
    } // if����
}

void Udata::Show_all()
{
    cout << endl << "��ʽ����" << endl;
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

void Udata::Show_By_score(CP_Student s, CP_ChainDoubleLink* p)
{
    cout << "�����������ѯ�ĳɼ�:";
    cin >> s.m_score;
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
    p = m_head;
    int n = 1; bool check = false;
    cout << "�ɼ�Ϊ" << s.m_score << "��ѧ��ѧ��Ϊ:" << endl;
    do
    {
        if (p->m_data.m_score == s.m_score)
        {
            check = true;
            cout << "ѧ��[" << n << "]ѧ��:" << p->m_data.m_ID << endl;
        }
        p = p->m_next;
        n++;
    } while (p != m_head);
    if (!check) cout << "û��ѧ���ɼ�Ϊ" << s.m_score << endl << "��ǰѧ������Ϊ��" << endl;
}
