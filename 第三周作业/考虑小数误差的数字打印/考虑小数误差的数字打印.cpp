#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n,n1;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double k1 = 100000000, k2 = 10000000, k3 = 1000000, k4 = 100000, k5 = 10000, k6 = 1000, k7 = 100, k8 = 10;
	int flag1, flag2;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> n;
	a = int(n / 1000000000.0);
	b = int((n - a * 1000000000.0) / k1);
	c = int((n - a * 1000000000.0 - b * k1) / k2);
	d = int((n - a * 1000000000.0 - b * k1 - c * k2) / k3);
	e = int((n - a * 1000000000.0 - b * k1 - c * k2 - d * k3) / k4);
	f = int((n - a * 1000000000.0 - b * k1 - c * k2 - d * k3 - e * k4) / k5);
	g = int((n - a * 1000000000.0 - b * k1 - c * k2 - d * k3 - e * k4 - f * k5) / k6);
	h = int((n - a * 1000000000.0 - b * k1 - c * k2 - d * k3 - e * k4 - f * k5 - g * k6) / k7);
	i = int((n - a * 1000000000.0 - b * k1 - c * k2 - d * k3 - e * k4 - f * k5 - g * k6 - h * k7) / k8);
	j = int(n - a * 1000000000.0 - b * k1 - c * k2 - d * k3 - e * k4 - f * k5 - g * k6 - h * k7 - i * k8);
	n1 = a * 1000000000.0 + b * k1 + c * k2 + d * k3 + e * k4 + f * k5 + g * k6 + h * k7 + i * k8 + j;
	k = int((n - n1) / 0.1);
	l = int((n - n1 - 0.1 * k) / 0.01);
	flag1 = int(((100 * (n - n1) - 10 * k) - l) + 0.1);
	flag2 = int((flag1 + l) / 10);
    cout << "ʮ��λ : " << a << endl;
	cout << "��λ   : " << b << endl;
	cout << "ǧ��λ : " << c << endl;
	cout << "����λ : " << d << endl;
	cout << "ʮ��λ : " << e << endl;
	cout << "��λ   : " << f << endl;
	cout << "ǧλ   : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ʮλ   : " << i << endl;
	cout << "Բ     : " << j << endl;
	cout << "��     : " << k + flag2 << endl;
	cout << "��     : " << int(l + flag1 - 10 * flag2) << endl;

	return 0;
}