#pragma once
#include<string>
using namespace std;

class CP_IntByString
{
private:
    int m_flag;    // 1: 普通正整数或0; -1: 普通负整数
    string m_data; //全部字符由'0'~'9'组成，而且不以'0'开头。m_data=""表示0。
public:
    CP_IntByString() : m_flag(1) { }
    CP_IntByString(const string& data, int flag = 1);

    int mb_getFlag() const { return m_flag; }
    string mb_getData() const { return m_data; }
    void mb_getValue(int& flag, string& data) const;
    void mb_setValue();
    void mb_setValue(const string& data);
    void mb_setValue(int flag, const string& data);
    void mb_show(const char* s) const;
    bool mb_compare(const CP_IntByString& a);
    bool mb_IsEqual(const CP_IntByString& a);
    CP_IntByString operator+(const CP_IntByString& a);
    CP_IntByString operator-(const CP_IntByString& a);
};

