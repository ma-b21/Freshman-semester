#include <iostream>
using namespace std;
#include "CP_IntByString.h"

CP_IntByString::CP_IntByString(const string& data, int flag)
{
    mb_setValue(flag, data);
} // CP_IntByString构造函数定义结束

void CP_IntByString::mb_getValue(int& flag, string& data) const
{
    flag = m_flag;
    data = m_data;
} // CP_IntByString的成员函数mb_getValue定义结束

void CP_IntByString::mb_setValue()
{
    m_flag = (m_flag == 1 ? -1 : 1);
}

void CP_IntByString::mb_setValue(const string& data)
{
    int i;
    int n = data.size();
    int s = 0; // 状态
    m_flag = 1;
    m_data = "";
    for (i = 0; i < n; i++)
    {
        switch (s)
        {
        case 0:
            if (data[i] == '+')
                s = 1;
            else if (data[i] == '-')
            {
                s = 1;
                m_flag = -1;
            }
            else if (data[i] == '0')
                s = 3;
            else if (('1' <= data[i]) && (data[i] <= '9'))
            {
                s = 2;
                m_data += data[i];
            } // if/else结束
            break;
        case 1:
            if (data[i] == '-')
                m_flag = (m_flag == 1 ? -1 : 1);
            else if (data[i] == '0')
                s = 3;
            else if (('1' <= data[i]) && (data[i] <= '9'))
            {
                s = 2;
                m_data += data[i];
            } // if/else结束
            break;
        case 2:
            if (('0' <= data[i]) && (data[i] <= '9'))
                m_data += data[i];
            break;
        case 3:
            if (('1' <= data[i]) && (data[i] <= '9'))
            {
                s = 2;
                m_data += data[i];
            } // if/else结束
            break;
        } // switch结束
    } // for循环结束
} // CP_IntByString的成员函数mb_setValue定义结束

void CP_IntByString::mb_setValue(int flag, const string& data)
{
    mb_setValue(data);
    if (flag == -1)
        m_flag = (m_flag == 1 ? -1 : 1);
} // CP_IntByString的成员函数mb_setValue定义结束

void CP_IntByString::mb_show(const char* s) const
{
    cout << s;
    if (m_data.size() <= 0)
    {
        cout << "0";
        return;
    } // if结束
    if (m_flag == -1)
        cout << "-";
    cout << m_data;
} // CP_IntByString的成员函数mb_show定义结束

bool CP_IntByString::mb_compare(const CP_IntByString& a)
{
    string m = a.mb_getData();
    string n = this->mb_getData();
    int msize = m.size();
    int nsize = n.size();
    if (msize > nsize) return true;
    if (msize < nsize) return false;
    for (int i = 0; i < nsize; i++)
    {
        if (m[i] > n[i]) return true;
        if (m[i] < n[i]) return false;
    }
}

bool CP_IntByString::mb_IsEqual(const CP_IntByString& a)
{
    string m = a.mb_getData();
    string n = this->mb_getData();
    int msize = m.size();
    int nsize = n.size();
    if (msize != nsize) return false;
    for (int i = 0; i < nsize; i++)
        if (m[i] != n[i]) return false;
    return true;
}

CP_IntByString CP_IntByString::operator+(const CP_IntByString& a)
{
    CP_IntByString c;
    string m = a.mb_getData();
    string n = this->mb_getData();
    string k;
    int msize = m.size();
    int nsize = n.size();
    int maxi = max(msize, nsize);
    k.resize(maxi);
    m.resize(maxi);
    n.resize(maxi);
    int* res = new int[maxi];
    for (int i = 0; i < maxi; i++)
        res[i] = 0;
    int limit{0};
    if (msize % 2 == 0)
        limit = msize / 2 ;
    else
        limit = (msize - 1) / 2;
    for (int i = 0; i < limit; i++)
        swap(m[i], m[msize - 1 - i]);

    if (nsize % 2 == 0)
        limit = nsize / 2;
    else
        limit = (nsize - 1) / 2;
    for (int i = 0; i < limit; i++)
        swap(n[i], n[nsize - 1 - i]);

    if (msize < nsize)
        for (int i = msize; i < nsize; i++)
            m[i] = '0';
    else if (msize > nsize)
        for (int i = nsize; i < msize; i++)
            n[i] = '0';
    if (maxi % 2 == 0)
        limit = maxi / 2;
    else
        limit = (maxi - 1) / 2;
    
    if (this->mb_getFlag() * a.mb_getFlag() > 0)
    {
        for (int i = 0; i < maxi; i++)
        {
            int tem1 = m[i] - '0';
            int tem2 = n[i] - '0';
            res[i] = tem1 + tem2;
        }
        for (int i = 0; i < maxi; i++)
        {
            if (res[i] >= 10)
            {
                res[i] %= 10;
                res[i + 1] += 1;
            }
            k[i] = res[i] + '0';
        }
        for (int i = 0; i < limit; i++)
            swap(k[i], k[maxi - 1 - i]);
        c.mb_setValue(a.mb_getFlag(), k);
    }
    else
    {
        CP_IntByString temp,temp1=a;
        if (this->mb_getFlag() < 0)
        {
            temp.mb_setValue(1, this->mb_getData());
            c = temp1 - temp;
        }
        else
        {
            temp.mb_setValue(1, a.mb_getData());
            c = *this - temp;
        }
    }
    delete[]res;
    return c;
}

CP_IntByString CP_IntByString::operator-(const CP_IntByString& a)
{
    CP_IntByString c;
    string m = a.mb_getData();
    string n = this->mb_getData();
    string k;
    int msize = m.size();
    int nsize = n.size();
    int maxi = max(msize, nsize);
    k.resize(maxi);
    m.resize(maxi);
    n.resize(maxi);
    int* res = new int[maxi];

    if (this->mb_getFlag() * a.mb_getFlag() > 0)
    {
        if (this->mb_IsEqual(a))
        {
            c.mb_setValue(1, "0");
            return c;
        }
        if (a.mb_getFlag() > 0)
        {
            if (this->mb_compare(a))
            {
                CP_IntByString tem = a;
                c = tem - *this;
                c.mb_setValue();
                return c;
            }
            else
            {
                int* res = new int[maxi];
                int limit{ 0 };
                if (msize % 2 == 0)
                    limit = msize / 2;
                else
                    limit = (msize - 1) / 2;
                for (int i = 0; i < limit; i++)
                    swap(m[i], m[msize - 1 - i]);

                if (nsize % 2 == 0)
                    limit = nsize / 2;
                else
                    limit = (nsize - 1) / 2;
                for (int i = 0; i < limit; i++)
                    swap(n[i], n[nsize - 1 - i]);

                if (msize < nsize)
                    for (int i = msize; i < nsize; i++)
                        m[i] = '0';
                else if (msize > nsize)
                    for (int i = nsize; i < msize; i++)
                        n[i] = '0';
                if (maxi % 2 == 0)
                    limit = maxi / 2;
                else
                    limit = (maxi - 1) / 2;
                for (int i = 0; i < maxi; i++)
                {
                    int tem1 = n[i] - '0';
                    int tem2 = m[i] - '0';
                    res[i] = tem1 - tem2;
                }
                for (int i = 0; i < maxi; i++)
                {
                    if (res[i] < 0)
                    {
                        res[i] += 10;
                        res[i + 1] -= 1;
                    }
                    k[i] = res[i] + '0';
                }
                delete[]res;
                for (int i = 0; i < limit; i++)
                    swap(k[i], k[maxi - 1 - i]);
                c.mb_setValue(a.mb_getFlag(), k);
                return c;
            }
        }
        else
        {
            CP_IntByString temp1 = a, temp2 = *this;
            temp1.mb_setValue();
            temp2.mb_setValue();
            c = temp1 - temp2;
            return c;
        }
    }
    
    else
    {
        if (this->mb_getFlag() > 0)
        {
            CP_IntByString tem = a;
            tem.mb_setValue();
            c = tem + *this;
        }
        else
        {
            CP_IntByString tem = *this;
            tem.mb_setValue();
            c = tem + a;
            c.mb_setValue();
        }
        return c;
    }
}
