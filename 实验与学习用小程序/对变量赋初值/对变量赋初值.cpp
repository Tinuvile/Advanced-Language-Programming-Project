#include <iostream>
using namespace std;
int main()
{
	float a1, b1 = 5.78 * 3.5, c1 = 2 * sin(2.0);
	cout << a1 << endl;
	cout << b1 << endl;
	cout << c1 << endl;

	cout << "------" << endl;

	float b2 = 5.78F * 3.5F, c2 = 2 * sin(2.0);
	cout << b2 << endl;
	cout << c2 << endl;

	cout << "------" << endl;

	float a3 = 0, b3 = 5.78 * 3.5, c3 = 2 * sin(2.0);
	cout << a3 << endl;
	cout << b3 << endl;
	cout << c3 << endl;

	cout << "------" << endl;

	double b4 = 5.78 * 3.5, c4 = 2 * sin(2.0);
	cout << b4 << endl;
	cout << c4 << endl;

	cout << "------" << endl;

	float a5, b5 = 5.78 * 3.5, c5 = 2 * sin(2.0);
	cout << a5 << endl;
	cout << b5 << endl;
	cout << c5 << endl;

	cout << "------" << endl;

	double a6 = 0, b6 = 5.78 * 3.5, c6 = 2 * sin(2.0);
	cout << a6 << endl;
	cout << b6 << endl;
	cout << c6 << endl;

	int a, b;
	a = 2 * 4, a = b = 3 * 5;
	cout << a << endl;

	return 0;
}