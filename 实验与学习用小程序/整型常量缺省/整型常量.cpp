#include <iostream>
using namespace std;

int main()
{
	cout << typeid(123).name()                 << endl;
	cout << typeid(123L).name()                << endl;
	cout << typeid(123U).name()                << endl;
	cout << typeid(123UL).name()               << endl;
	cout << typeid(123LU).name()               << endl;

	cout << typeid(bool).name()                << endl;
	cout << typeid(char).name()                << endl;
	cout << typeid(unsigned char).name()       << endl;
	cout << typeid(signed short).name()        << endl;
	cout << typeid(unsigned short).name()      << endl;
	cout << typeid(int).name()                 << endl;
	cout << typeid(unsigned).name()            << endl;
	cout << typeid(unsigned long).name()       << endl;
	cout << typeid(long long).name()           << endl;
	cout << typeid(unsigned long long).name()  << endl;
	cout << typeid(float).name()               << endl;
	cout << typeid(double).name()              << endl;
	cout << typeid(long double).name()         << endl;

	return 0;
}