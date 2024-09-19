/* 2352495 张竹和 信16 */
#include <iostream>
#include <cmath>
using namespace std;

void f4(double a, double b, double c, double delta)
{
	double imaginary, t;
	t = (-b) / (2 * a);
	imaginary = sqrt(-delta);
	if (fabs(t) < 1e-6)
		t = 1;
	if (fabs(imaginary) < 1e-6)
		imaginary = 1;
	cout << "有两个虚根" << endl;
	if (imaginary == 1) {
		cout << "x1=" << t << "+i" << endl;
		cout << "x2=" << t << "-i" << endl;
	}
	else if (imaginary != 1) {
		cout << "x1=" << t << "+" << imaginary / (2 * a) << "i" << endl;
		cout << "x2=" << t << "-" << imaginary / (2 * a) << "i" << endl;
	}
}