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
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> x;
	x1 = x * pi / 180;
	cout << setiosflags(ios::fixed);
	s = a * b * sin(x1) / 2;
	cout << "���������Ϊ : " <<setprecision(3)<< s << endl;

	return 0;
}