/* 2352495 ��16 ����� */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double x, y;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	int m;
	n1 = 1000000000, n2 = 100000000, n3 = 10000000, n4 = 1000000, n5 = 100000, n6 = 10000, n7 = 1000, n8 = 100, n9 = 10, n10 = 1;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> x;
	a = int(x / n1);
	b = int((x - a * n1) / n2);
	c = int((x - a * n1 - b * n2) / n3);
	d = int((x - a * n1 - b * n2 - c * n3) / n4);
	e = int((x - a * n1 - b * n2 - c * n3 - d * n4) / n5);
	f = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5) / n6);
	g = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6) / n7);
	h = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7) / n8);
	i = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8) / n9);
	j = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8 - i * n9) / n10);

	y = a * n1 + b * n2 + c * n3 + d * n4 + e * n5 + f * n6 + g * n7 + h * n8 + i * n9 + j * n10;
	m = int(round(100 * (x - y)));
	l = m % 10;
	k = (m - l) / 10;
	
	//k=int(100*(x-y))

	cout << "��д�����:" << endl;

	//ʮ��λ����λ���
	daxie(a, 0);
	if (a != 0) {
		cout << "ʰ";
	}
	daxie(b, 0);
	if (a != 0 || b != 0)
		cout << "��";

	//��λ���
	daxie(c, b != 0 && d != 0);
	if (c != 0) {
		cout << "Ǫ";
	}
	daxie(d, e != 0 && x >= 1000000);
	if (d != 0) {
		cout << "��";
	}
	daxie(e, f != 0 && x >= 100000);
	if (e != 0) {
		cout << "ʰ";
	}
	daxie(f, 0);
	if (c != 0 || d != 0 || e != 0 || f != 0)
		cout << "��";

	//��λ���
	daxie(g, h != 0 && x >= 1000);
	if (g != 0) {
		cout << "Ǫ";
	}
	daxie(h, i != 0 && x >= 100);
	if (h != 0) {
		cout << "��";
	}
	daxie(i, j != 0 && x >= 10);
	if (i != 0) {
		cout << "ʰ";
	}
	daxie(j,0);
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0)
		cout << "Բ";

	//����С�������λ
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0)
			cout << "��" << endl;
	}
	if (k != 0) {
		daxie(k,0);
		cout << "��";
	}
	if (k != 0 && l == 0)
		cout << "��" << endl;
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if (x >= 1.01)
				daxie(0,1);
		}
	}

	if (l != 0) {
		daxie(l,0);
		cout << "��" << endl;
	}
	if (x == 0) {
		daxie(0,1);
		cout << "Բ��" << endl;
	}

	return 0;
}