#include<iostream>
#include "CP_Udata.h"
using namespace std;

void Udata::Add_Student(CP_Student s, CP_ChainDoubleLink* p)
{
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
}

void Udata::Delete_By_num(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec)
{
    cout << "删除学生，请输入这位学生的学号:";
    s.m_ID = -1;
    cin >> s.m_ID;
    if (s.m_ID <= 0)
        cout << "学号必须为正整数!" << endl;
    if (s.m_ID > 0)
    {
        p = m_head->mb_findNodeById(s.m_ID);
        if (p != NULL)
        {
            delec.push_back(p->m_data);
            m_head->mb_deleteNode(p);
        }
        else cout << "没有找到该学号的学生。" << endl;
    } // if结束
}

void Udata::Delete_By_score(CP_Student s, CP_ChainDoubleLink* p, vector<CP_Student> &delec)
{
    cout << "请输入你想删除的学生成绩:";
    cin >> s.m_score;
    //mb_deletebyScore(s.m_score);
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
    if (!check)  cout << "没有学生成绩为" << s.m_score << endl << "当前学生名单为：" << endl;
}

void Udata::Find_By_num(CP_Student s, CP_ChainDoubleLink* p)
{
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
}

void Udata::Show_all()
{
    cout << endl << "正式表单：" << endl;
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

void Udata::Show_By_score(CP_Student s, CP_ChainDoubleLink* p)
{
    cout << "请输入你想查询的成绩:";
    cin >> s.m_score;
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
    p = m_head;
    int n = 1; bool check = false;
    cout << "成绩为" << s.m_score << "的学生学号为:" << endl;
    do
    {
        if (p->m_data.m_score == s.m_score)
        {
            check = true;
            cout << "学生[" << n << "]学号:" << p->m_data.m_ID << endl;
        }
        p = p->m_next;
        n++;
    } while (p != m_head);
    if (!check) cout << "没有学生成绩为" << s.m_score << endl << "当前学生名单为：" << endl;
}
