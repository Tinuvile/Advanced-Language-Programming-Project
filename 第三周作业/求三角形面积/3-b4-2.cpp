#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int a, b, x;
	float s;
	double x1;
	const double pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> x;
	x1 = x * pi / 180;
	cout << setiosflags(ios::fixed);
	s = a * b * sin(x1) / 2;
	cout << "三角形面积为 : " <<setprecision(3)<< s << endl;

	return 0;
}