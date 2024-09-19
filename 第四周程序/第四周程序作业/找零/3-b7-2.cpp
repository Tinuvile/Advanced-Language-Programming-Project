/* 2352495 信16 张竹和 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double money, x;
	double a = 50, b = 20, c = 10, d = 5, e = 1, f = 0.5, g = 0.1, h = 0.05, i = 0.02, j = 0.01;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, y;
	cout << "请输入找零值：" << endl;
	cin >> money;
	n1 = int(money / a);
	n2 = int((money - a * n1) / b);
	n3 = int((money - a * n1 - b * n2) / c);
	n4 = int((money - a * n1 - b * n2 - c * n3) / d);
	n5 = int((money - a * n1 - b * n2 - c * n3 - d * n4) / e);

	x = a * n1 + b * n2 + c * n3 + d * n4 + e * n5;
	y = int(round(100 * (money - x)));
	n6 = int(y / 50);
	n7 = int((y - 50 * n6) / 10);
	n8 = int((y - 50 * n6 - 10 * n7) / 5);
	n9 = int((y - 50 * n6 - 10 * n7 - 5 * n8) / 2);
	n10 = int((y - 50 * n6 - 10 * n7 - 5 * n8 - 2 * n9) / 1);

	cout << "共" << n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 << "张找零，具体如下：" << endl;
	if (n1!=0)
		cout << "50元 : " << n1  << "张" << endl;
	if (n2!=0)
		cout << "20元 : " << n2  << "张" << endl;
	if (n3!=0)
		cout << "10元 : " << n3  << "张" << endl;
	if (n4!=0)
		cout << "5元  : " << n4  << "张" << endl;
	if (n5!=0)
		cout << "1元  : " << n5  << "张" << endl;
	if (n6!=0)
		cout << "5角  : " << n6  << "张" << endl;
	if (n7!=0)
		cout << "1角  : " << n7  << "张" << endl;
	if (n8!=0)
		cout << "5分  : " << n8  << "张" << endl;
	if (n9!=0)
		cout << "2分  : " << n9  << "张" << endl;
	if (n10!=0)
		cout << "1分  : " << n10 << "张" << endl;

	return 0;
}