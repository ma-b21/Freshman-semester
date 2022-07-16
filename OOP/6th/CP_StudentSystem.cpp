#include <iostream>
using namespace std;
#include "CP_StudentSystem.h"

void CP_StudentSystem::mb_printAllStudent()
{
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
    CP_ChainDoubleLink* p = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "]: ѧ��(" << p->m_data.m_ID
            << "), �ɼ�(" << p->m_data.m_score << ")" << endl;
        p = p->m_next;
        n++;
    } while (p != m_head);
}

void CP_StudentSystem::mb_printMainMenu()
{
    cout << "\n���˵�:\n";
    cout << "\t1: �������λѧ��(ѧ�� �ɼ�)����0������\n";
    cout << "\t2: ɾ����1λָ��ѧ�ŵ�ѧ����\n";
    cout << "\t3: ɾ������ָ���ɼ�ѧ����\n";
    cout << "\t4: ��ʾ��1λָ��ѧ�ŵ�ѧ���ĳɼ���\n";
    cout << "\t5: ��ʾ����ָ���ɼ���ѧ����ѧ�š�\n";
    cout << "\t6: ��ʾ����ѧ����Ϣ��\n";
    cout << "\t-1: �˳���\n";
    cout << "������1��2��3��4��5��6��-1:";
}

void CP_StudentSystem::mb_findIdbyScore(int Score)
{
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
    CP_ChainDoubleLink* p = m_head;
    int n = 1; bool check = false;
    cout << "�ɼ�Ϊ" << Score << "��ѧ��ѧ��Ϊ:" << endl;
    do
    {
        if (p->m_data.m_score == Score)
        {
            check = true;
            cout << "ѧ��[" << n << "]ѧ��:" << p->m_data.m_ID << endl;
        }
        p = p->m_next;
        n++;
    } while (p != m_head);
    if (!check) cout << "û��ѧ���ɼ�Ϊ" << Score << endl << "��ǰѧ������Ϊ��" << endl;
    mb_printAllStudent();
}

void CP_StudentSystem::mb_deletebyScore(int Score)
{
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
    CP_ChainDoubleLink* p = m_head;
    CP_ChainDoubleLink* q = m_head;
    int n = 1; bool check = false;
    do
    {
        if (q->m_data.m_score == Score)
        {
            p = q->m_next;
            m_head->mb_deleteNode(q);
            q = p;
            check = true;
        }
        else q = q->m_next;
        n++;
    } while (q != m_head);
    if (!check)  cout << "û��ѧ���ɼ�Ϊ" << Score << endl << "��ǰѧ������Ϊ��" << endl;
}

void CP_StudentSystem::mb_run()
{
    m_head = new CP_ChainDoubleLink;
    if (m_head == NULL)
        return;
    CP_Student s;
    CP_ChainDoubleLink* p;
    int c;
    do
    {
        c = 10;
        mb_printMainMenu();
        cin >> c;
        if (c > 9)
            cout << "����: �����ʽ����!\n";
        switch (c)
        {
        case 1: // �������λѧ��(ѧ�� �ɼ�)����0������
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
            break;
        case 2: // ɾ����1λָ��ѧ�ŵ�ѧ����
            cout << "ɾ��ѧ������������λѧ����ѧ��:";
            s.m_ID = -1;
            cin >> s.m_ID;
            if (s.m_ID <= 0)
                cout << "ѧ�ű���Ϊ������!" << endl;
            if (s.m_ID > 0)
            {
                p = m_head->mb_findNodeById(s.m_ID);
                if (p != NULL)
                    m_head->mb_deleteNode(p);
                else cout << "û���ҵ���ѧ�ŵ�ѧ����" << endl;
            } // if����
            break;
        case 3: // ɾ������ѧ����
            cout << "����������ɾ����ѧ���ɼ�:";
            cin >> s.m_score;
            mb_deletebyScore(s.m_score);
            mb_printAllStudent();
            break;
        case 4: // ��ʾ��һλָ��ѧ�ŵ�ѧ���ĳɼ�
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
            break;
        case 5: // ��ʾ����ָ���ɼ���ѧ����ѧ��
            cout << "�����������ѯ�ĳɼ�:";
            cin >> s.m_score;
            mb_findIdbyScore(s.m_score);
            break;
        case 6: // ��ʾ����ѧ����Ϣ��
            mb_printAllStudent();
            break;
        } // switch����
        cin.clear(); // ���������״̬
        cin.ignore(); // ������������
    } while (c >= 0);
    delete m_head;
    m_head = NULL;
} // ��CP_StudentSystem�ĳ�Ա����mb_run�������
