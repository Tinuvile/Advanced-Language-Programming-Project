#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double n,n1;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double k1 = 100000000, k2 = 10000000, k3 = 1000000, k4 = 100000, k5 = 10000, k6 = 1000, k7 = 100, k8 = 10;
	int flag1, flag2;
	cout << "请输入[0-100亿)之间的数字:" << endl;
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
    cout << "十亿位 : " << a << endl;
	cout << "亿位   : " << b << endl;
	cout << "千万位 : " << c << endl;
	cout << "百万位 : " << d << endl;
	cout << "十万位 : " << e << endl;
	cout << "万位   : " << f << endl;
	cout << "千位   : " << g << endl;
	cout << "百位   : " << h << endl;
	cout << "十位   : " << i << endl;
	cout << "圆     : " << j << endl;
	cout << "角     : " << k + flag2 << endl;
	cout << "分     : " << int(l + flag1 - 10 * flag2) << endl;

	return 0;
}