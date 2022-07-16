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
            cout << "错误: 输入格式有误!\n";
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
    cout << "\n主菜单:\n";
    cout << "\t1: 添加若干位学生(学号 成绩)，以0结束。\n";
    cout << "\t2: 删除第1位指定学号的学生。\n";
    cout << "\t3: 删除所有指定成绩学生。\n";
    cout << "\t4: 显示第1位指定学号的学生的成绩。\n";
    cout << "\t5: 显示所有指定成绩的学生的学号。\n";
    cout << "\t6: 显示所有学生信息。\n";
    cout << "\t-1: 退出。\n";
    cout << "请输入1、2、3、4、5、6或-1:";
}
