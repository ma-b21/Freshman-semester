#include <iostream>
using namespace std;
#include "CP_StudentSystem.h"

void CP_StudentSystem::mb_printAllStudent()
{
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
    CP_ChainDoubleLink* p = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "]: 学号(" << p->m_data.m_ID
            << "), 成绩(" << p->m_data.m_score << ")" << endl;
        p = p->m_next;
        n++;
    } while (p != m_head);
}

void CP_StudentSystem::mb_printMainMenu()
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

void CP_StudentSystem::mb_findIdbyScore(int Score)
{
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
    CP_ChainDoubleLink* p = m_head;
    int n = 1; bool check = false;
    cout << "成绩为" << Score << "的学生学号为:" << endl;
    do
    {
        if (p->m_data.m_score == Score)
        {
            check = true;
            cout << "学生[" << n << "]学号:" << p->m_data.m_ID << endl;
        }
        p = p->m_next;
        n++;
    } while (p != m_head);
    if (!check) cout << "没有学生成绩为" << Score << endl << "当前学生名单为：" << endl;
    mb_printAllStudent();
}

void CP_StudentSystem::mb_deletebyScore(int Score)
{
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
    if (!check)  cout << "没有学生成绩为" << Score << endl << "当前学生名单为：" << endl;
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
            cout << "错误: 输入格式有误!\n";
        switch (c)
        {
        case 1: // 添加若干位学生(学号 成绩)，以0结束。
            do
            {
                s.m_ID = 0;
                s.m_score = -1;
                cout << "添加学生的学号与成绩，以0结束:";
                cin >> s.m_ID;
                if (s.m_ID > 0)
                    cin >> s.m_score;
                if (s.m_ID < 0)
                    cout << "学号不能小于0" << endl;
                if ((s.m_ID > 0) && (s.m_score < 0))
                    cout << "成绩不能小于0" << endl;
                if ((s.m_ID > 0) && (s.m_score >= 0))
                {
                    p = m_head->mb_createNode();
                    if (p != NULL)
                        p->m_data = s;
                    else cout << "内存申请失败!" << endl;
                } // if结束
                if (m_head != NULL)
                    m_head->mb_sortById();//保证学号按升序排列

                
            } while (s.m_ID > 0);
            break;
        case 2: // 删除第1位指定学号的学生。
            cout << "删除学生，请输入这位学生的学号:";
            s.m_ID = -1;
            cin >> s.m_ID;
            if (s.m_ID <= 0)
                cout << "学号必须为正整数!" << endl;
            if (s.m_ID > 0)
            {
                p = m_head->mb_findNodeById(s.m_ID);
                if (p != NULL)
                    m_head->mb_deleteNode(p);
                else cout << "没有找到该学号的学生。" << endl;
            } // if结束
            break;
        case 3: // 删除所有学生。
            cout << "请输入你想删除的学生成绩:";
            cin >> s.m_score;
            mb_deletebyScore(s.m_score);
            mb_printAllStudent();
            break;
        case 4: // 显示第一位指定学号的学生的成绩
            cout << "请输入你想查询成绩的学生的学号:";
            s.m_ID = -1;
            cin >> s.m_ID;
            if (s.m_ID <= 0)
                cout << "学号必须为正整数!" << endl;
            if (s.m_ID > 0)
            {
                p = m_head->mb_findNodeById(s.m_ID);
                if (p != NULL)
                    cout << "他的成绩为:" << p->m_data.m_score << endl;
                else cout << "没有找到该学号的学生。" << endl;
            } // if结束
            break;
        case 5: // 显示所有指定成绩的学生的学号
            cout << "请输入你想查询的成绩:";
            cin >> s.m_score;
            mb_findIdbyScore(s.m_score);
            break;
        case 6: // 显示所有学生信息。
            mb_printAllStudent();
            break;
        } // switch结束
        cin.clear(); // 来清除错误状态
        cin.ignore(); // 跳过错误输入
    } while (c >= 0);
    delete m_head;
    m_head = NULL;
} // 类CP_StudentSystem的成员函数mb_run定义结束
