/* 2352495 张竹和 信16 */
#include <iostream>
#include <cmath>
using namespace std;

void f1(double a, double b, double c)
{
	if (a == 0) {
		cout << "不是一元二次方程" << endl;
	}
}

void f2(double a, double b, double c, double delta)
{
	double x1, x2;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void f3(double a, double b, double c, double delta)
{
	double x;
	x = (-b) / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}

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