#include <iostream>
using namespace std;
#include "CP_UnionDOubleInt.h"

int main(int argc, char* args[])
{

    gb_testDoubleInt();
    double data(0);
    cout << "�����븡������";
    cin >> data;
    U_DoubleInt u(data);
    gb_showDoubleIntBinMemory(u);
    return 0; // ����0�����������гɹ�
} // main��������
