/* 2352495 ��16 ����� */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�";
string result;

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	switch (num) {
		case 0:
			if (flag_of_zero) {
				result = result + chnstr[0] + chnstr[1];
			}
			break;
		case 1:
			result = result + chnstr[2] + chnstr[3];
			break;
		case 2:
			result = result + chnstr[4] + chnstr[5];
			break;
		case 3:
			result = result + chnstr[6] + chnstr[7];
			break;
		case 4:
			result = result + chnstr[8] + chnstr[9];
			break;
		case 5:
			result = result + chnstr[10] + chnstr[11];
			break;
		case 6:
			result = result + chnstr[12] + chnstr[13];
			break;
		case 7:
			result = result + chnstr[14] + chnstr[15];
			break;
		case 8:
			result = result + chnstr[16] + chnstr[17];
			break;
		case 9:
			result = result + chnstr[18] + chnstr[19];
			break;
		default:
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

	string s= "��д�����:\n";
	result = result + s;

	//ʮ��λ����λ���
	daxie(a, 0);
	if (a != 0) {
		s = "ʰ";
		result = result + s;
	}
	daxie(b, 0);
	if (a != 0 || b != 0) {
		s = "��";
		result = result + s;
	}
		
	//��λ���
	daxie(c, b != 0 && d != 0);
	if (c != 0) {
		s = "Ǫ";
		result = result + s;
	}
	daxie(d, e != 0 && x >= 1000000);
	if (d != 0) {
		s = "��";
		result = result + s;
	}
	daxie(e, f != 0 && x >= 100000);
	if (e != 0) {
		s = "ʰ";
		result = result + s;
	}
	daxie(f, 0);
	if (c != 0 || d != 0 || e != 0 || f != 0) {
		s = "��";
		result = result + s;
	}
		

	//��λ���
	daxie(g, h != 0 && x >= 1000);
	if (g != 0) {
		s = "Ǫ";
		result = result + s;
	}
	daxie(h, i != 0 && x >= 100);
	if (h != 0) {
		s = "��";
		result = result + s;
	}
	daxie(i, j != 0 && x >= 10);
	if (i != 0) {
		s = "ʰ";
		result = result + s;
	}
	daxie(j, 0);
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		s = "Բ";
		result = result + s;
	}
		

	//����С�������λ
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0) {
			s = "��";
			result = result + s;
		}
	}
	if (k != 0) {
		daxie(k, 0);
		s = "��";
		result = result + s;
	}
	if (k != 0 && l == 0) {
		s = "��";
		result = result + s;
	}
		
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if (x >= 1.01)
				daxie(0, 1);
		}
	}

	if (l != 0) {
		daxie(l, 0);
		s = "��";
		result = result + s;
	}
	if (x == 0) {
		daxie(0, 1);
		s = "Բ��";
		result = result + s;
	}


	cout << result << endl;
	return 0;
}