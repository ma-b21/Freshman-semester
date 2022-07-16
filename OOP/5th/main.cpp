#include<iostream>
#include"Complex.h"
using namespace std;
int main()
{
	C_complex test,oop,test1(0,2), test2(1,1), test3(2,0), test4(1,-1);
	cout << "test=" << test <<"test1="<< test1 
		<<"test2="<< test2 <<"test3="<< test3 <<"test4="<< test4 << endl;
	oop = test * test1; cout <<"test * test1=" << oop;
	oop = test1 * test2; cout <<"test1 * test2=" << oop;
	oop = test2 * test3; cout <<"test2 * test3=" << oop;
	oop = test3 * test4; cout <<"test3 * test4=" << oop;
	oop = test4 * test; cout << "test4 * test=" << oop << endl;

	oop = test / test1; cout << "test / test1=" << oop;
	oop = test1 / test2; cout << "test1 / test2=" << oop;
	oop = test2 / test3; cout << "test2 / test3=" << oop;
	oop = test3 / test4; cout << "test3 / test4=" << oop;
	oop = test4 / test; cout << "test4 / test=" << oop << endl;

	oop = test + test1; cout << "test + test1=" << oop;
	oop = test1 + test2; cout << "test1 + test2=" << oop;
	oop = test2 + test3; cout << "test2 + test3=" << oop;
	oop = test3 + test4; cout << "test3 + test4=" << oop;
	oop = test4 + test; cout << "test4 + test=" << oop << endl;

	oop = test - test1; cout << "test - test1=" << oop;
	oop = test1 - test2; cout << "test1 - test2=" << oop;
	oop = test2 - test3; cout << "test2 - test3=" << oop;
	oop = test3 - test4; cout << "test3 - test4=" << oop;
	oop = test4 - test; cout << "test4 - test=" << oop << endl;
	
	oop.real = 10; oop.imaginary = 5;
	cout << "oop =" << oop;
	oop += test; cout << "oop + test =" << oop;
	oop += test1; cout <<"oop + test1 ="<< oop;
	oop += test2; cout <<"oop + test2 ="<< oop;
	oop += test3; cout <<"oop + test3 ="<< oop;
	oop += test4; cout <<"oop + test4 ="<< oop << endl;

	oop.real = 10; oop.imaginary = 5;
	cout << "oop =" << oop;
	oop -= test; cout << "oop - test =" << oop;
	oop -= test1; cout << "oop - test1 =" << oop;
	oop -= test2; cout << "oop - test2 =" << oop;
	oop -= test3; cout << "oop - test3 =" << oop;
	oop -= test4; cout << "oop - test4 =" << oop << endl;

	oop.real = 10; oop.imaginary = 5;
	cout << "oop =" << oop;
	oop *= test1; cout << "oop * test1 =" << oop;
	oop *= test2; cout << "oop * test2 =" << oop;
	oop *= test3; cout << "oop * test3 =" << oop;
	oop *= test4; cout << "oop * test4 =" << oop;
	oop *= test; cout << "oop * test =" << oop << endl;

	oop.real = 10; oop.imaginary = 5;
	cout << "oop =" << oop;
	oop /= test1; cout << "oop / test1 =" << oop;
	oop /= test2; cout << "oop / test2 =" << oop;
	oop /= test3; cout << "oop / test3 =" << oop;
	oop /= test4; cout << "oop / test4 =" << oop;
	oop /= test; cout << "oop / test =" << oop << endl;

	oop.real = 10; oop.imaginary = 5;
	cout << "oop =" << oop;
	oop++; cout << "oop++ =" << oop;
	++oop; cout << "++oop =" << oop;
	oop--; cout << "oop-- =" << oop;
	--oop; cout << "--oop =" << oop;


	
	
	return 0;
}