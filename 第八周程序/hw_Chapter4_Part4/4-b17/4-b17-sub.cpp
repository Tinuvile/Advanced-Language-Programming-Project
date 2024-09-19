/* 2352495 ����� ��16 */
#include <iostream>
#include <cmath>
using namespace std;

extern double a, b, c;

void f1()
{
	if (a == 0) {
		cout << "����һԪ���η���" << endl;
	}
}

void f2()
{
	double x1, x2;
	double delta = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "����������ʵ����" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}

void f3()
{
	double x;
	double delta;
	x = (-b) / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x << endl;
}

void f4()
{
	double delta;
	double imaginary, t;
	t = (-b) / (2 * a);
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	imaginary = sqrt(-delta);
	if (fabs(t) < 1e-6)
		t = 1;
	if (fabs(imaginary) < 1e-6)
		imaginary = 1;
	cout << "���������" << endl;
	if (imaginary == 1) {
		cout << "x1=" << t << "+i" << endl;
		cout << "x2=" << t << "-i" << endl;
	}
	else if (imaginary != 1) {
		cout << "x1=" << t << "+" << imaginary / (2 * a) << "i" << endl;
		cout << "x2=" << t << "-" << imaginary / (2 * a) << "i" << endl;
	}
}