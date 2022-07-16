#pragma once

union U_DoubleInt
{
    double m_double;
    long long m_LLong;
    U_DoubleInt(long long i = 0) : m_LLong(i) {}
    U_DoubleInt(double f) : m_double(f) {}
    U_DoubleInt(const U_DoubleInt& u) : m_LLong(u.m_LLong) {}
    ~U_DoubleInt() {}
}; // 共用体U_FloatInt定义结束

extern void gb_showDoubleIntBinMemory(const U_DoubleInt& u);
extern void gb_testDoubleInt();
extern void gb_binaryInt(unsigned long long n);
