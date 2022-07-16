#include <iostream>
using namespace std;
#include "CP_UnionDOubleInt.h"

int main(int argc, char* args[])
{

    gb_testDoubleInt();
    double data(0);
    cout << "请输入浮点数：";
    cin >> data;
    U_DoubleInt u(data);
    gb_showDoubleIntBinMemory(u);
    return 0; // 返回0表明程序运行成功
} // main函数结束
