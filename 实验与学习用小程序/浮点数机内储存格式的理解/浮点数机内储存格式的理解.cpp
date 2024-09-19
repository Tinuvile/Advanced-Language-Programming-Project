#include <iostream>
using namespace std;
int main()
{
	double d = 4201234567;
	unsigned char* p1 = (unsigned char*)&d;
	cout << hex << (int)(*p1)       << endl;
	cout << hex << (int)(*(p1+1))   << endl;
	cout << hex << (int)(*(p1+2))   << endl;
	cout << hex << (int)(*(p1+3))   << endl;
	cout << hex << (int)(*(p1+4))   << endl;
	cout << hex << (int)(*(p1+5))   << endl;
	cout << hex << (int)(*(p1+6))   << endl;
	cout << hex << (int)(*(p1+7))   << endl;

	cout << "-----------" << endl;

	float f = -10;
	unsigned char* p2 = (unsigned char*)&f;
	cout << hex << (int)(*p2)       << endl;
	cout << hex << (int)(*(p2+1))   << endl;
	cout << hex << (int)(*(p2+2))   << endl;
	cout << hex << (int)(*(p2+3))   << endl;

	cout << "------------" << endl;

	short s = 65420;
	unsigned char* p3 = (unsigned char*)&s;
	cout << hex << (int)(*p3)       << endl;
	cout << hex << (int)(*(p3 + 1)) << endl;

	cout << "-------------" << endl;

	long l = -4201234567;
	unsigned char* p4 = (unsigned char*)&l;
	cout << hex << (int)(*p4) << endl;
	cout << hex << (int)(*(p4 + 1)) << endl;
	cout << hex << (int)(*(p4 + 2)) << endl;
	cout << hex << (int)(*(p4 + 3)) << endl;

	return 0;
}