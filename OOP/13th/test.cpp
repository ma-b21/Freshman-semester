#include "test.h"
#include<iostream>
using namespace std;

void test_method()
{
    Udata data1;
    NUdata data2;
    data1.m_head = new CP_ChainDoubleLink;
    data2.m_head = new CP_ChainDoubleLink;
    if (data1.m_head == NULL)
        return;
    vector<CP_Student> delec;
    CP_Student s{ 0, -1 };
    CP_ChainDoubleLink* p(NULL);
    int c(0);
    do
    {
        c = 10;
        print_menu();
        cin >> c;
        if (c > 9)
            cout << "����: �����ʽ����!\n";
        switch (c)
        {
        case 1:data1.Add_Student(s,p); break;
        case 2:data1.Delete_By_num(s,p,delec);
            data1.Show_all();
            data2.Add_Student(delec);
            data2.Show_all(); break;
        case 3:data1.Delete_By_score(s,p,delec);
            data1.Show_all();
            data2.Add_Student(delec);
            data2.Show_all(); break;
        case 4:data1.Find_By_num(s,p); break;
        case 5:data1.Show_By_score(s,p); break;
        case 6:data1.Show_all(); 
            data2.Show_all(); break;
        }
    } while (c >= 0);
    delete data1.m_head;
    data1.m_head = NULL;

}

void print_menu()
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
