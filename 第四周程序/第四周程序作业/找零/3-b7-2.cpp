/* 2352495 ��16 ����� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double money, x;
	double a = 50, b = 20, c = 10, d = 5, e = 1, f = 0.5, g = 0.1, h = 0.05, i = 0.02, j = 0.01;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, y;
	cout << "����������ֵ��" << endl;
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

	cout << "��" << n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10 << "�����㣬�������£�" << endl;
	if (n1!=0)
		cout << "50Ԫ : " << n1  << "��" << endl;
	if (n2!=0)
		cout << "20Ԫ : " << n2  << "��" << endl;
	if (n3!=0)
		cout << "10Ԫ : " << n3  << "��" << endl;
	if (n4!=0)
		cout << "5Ԫ  : " << n4  << "��" << endl;
	if (n5!=0)
		cout << "1Ԫ  : " << n5  << "��" << endl;
	if (n6!=0)
		cout << "5��  : " << n6  << "��" << endl;
	if (n7!=0)
		cout << "1��  : " << n7  << "��" << endl;
	if (n8!=0)
		cout << "5��  : " << n8  << "��" << endl;
	if (n9!=0)
		cout << "2��  : " << n9  << "��" << endl;
	if (n10!=0)
		cout << "1��  : " << n10 << "��" << endl;

	return 0;
}