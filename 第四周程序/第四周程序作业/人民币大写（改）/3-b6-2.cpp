/* 2352495 ��16 ����� */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

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
	if (a != 0) {
		switch (a) {
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			default:
				break;
		}
	}
	if (b != 0) {
		switch (b) {
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
				break;
		}
	}
	if (a!=0||b!=0)
		cout << "��";

	//��λ���
	if (c != 0) {
		switch (c) {
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
			default:
				break;
		}
	}
	if (c == 0 && d != 0 && x >= 10100000)
		cout << "��";
	if (d != 0) {
		switch (d) {
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (d == 0 && e != 0 && x >= 1010000)
		cout << "��";
	if (e != 0) {
		switch (e) {
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			default:
				break;
		}
	}
	if (e == 0 && f != 0 && x >= 101000)
		cout << "��";
	if (f != 0) {
		switch (f) {
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
				break;
		}
	}
	if (c != 0 || d != 0 || e != 0 || f != 0)
		cout << "��";

	//��λ���
	if (g != 0) {
		switch (g) {
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
			default:
				break;
		}
	}
	if (g == 0 && h != 0 && x >= 10100)
		cout << "��";
	if (h != 0) {
		switch (h) {
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (h == 0 && i != 0 && x >= 1010)
		cout << "��";
	if (i != 0) {
		switch (i) {
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			default:
				break;
		}
	}
	if (i == 0 && j != 0 && x >= 101)
		cout << "��";
	if (j != 0) {
		switch (j) {
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
				break;
		}
	}
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0)
		cout << "Բ";

	//����С�������λ
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0)
			cout << "��" << endl;
	}
	if (k != 0) {
		switch (k) {
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}

	if (k != 0 && l == 0) {
		cout << "��" << endl;
	}

	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if(x>=1.01)
				cout << "��";
		}
	}

	if (l != 0) {
		switch (l) {
			case 1:
				cout << "Ҽ��" << endl;
				break;
			case 2:
				cout << "����" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "����" << endl;
				break;
			case 5:
				cout << "���" << endl;
				break;
			case 6:
				cout << "½��" << endl;
				break;
			case 7:
				cout << "���" << endl;
				break;
			case 8:
				cout << "�Ʒ�" << endl;
				break;
			case 9:
				cout << "����" << endl;
				break;
			default:
				break;
		}
	}
	if (x == 0)
		cout << "��Բ��" << endl;

	return 0;
}