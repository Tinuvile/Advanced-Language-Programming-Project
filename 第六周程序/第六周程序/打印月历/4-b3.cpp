/* ��16 2352495 �����*/
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************
  �������ƣ�zeller
  ��    �ܣ�����涨�����ն�Ӧ������
  ���������y,m,d
  �� �� ֵ��day_2
  ˵    ����
***************************************************************************/
int zeller(int y, int m, int d)
{
	//������ֵ
	int y_last2, cen_1, mon, day_1, w, day_2;
	if (m == 1 || m == 2) {
		mon = m + 12;
		cen_1 = int((y - 1) / 100);
		y_last2 = (y - 1) % 100;
	}
	else {
		mon = m;
		cen_1 = int(y / 100);
		y_last2 = y % 100;
	}
	day_1 = d;

	//��ʽ����
	w = y_last2 + int(y_last2 / 4) + int(cen_1 / 4) - 2 * cen_1 + int(26 * (mon + 1) / 10) + day_1 - 1;
	if (w >= 0)
		day_2 = w % 7;
	if (w < 0) {
		for (int i = 1; w < 0; i++) {
			w = w + 7 * i;
			day_2 = w % 7;
		}
	}
	return day_2;
}

/***************************************************************************
  �������ƣ�calender
  ��    �ܣ�����ʽ�������
  ���������year,month
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void calender(int year, int month)
{
	/* ������Ӵ��� */
	int day = 1;
	int day_3 = zeller(year, month, day);

	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	/* ������Ӵ��� */
	//��������ÿ����Ϊ4��Ĭ���Ҷ��룬��ÿ����ӡ�����ո�
	//�迼�������2���Լ�12���µ�����
	//�������������2��
	//����setw(0)�����һ���ַ�λ
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
			if (day_3 != 0)
				cout << setw(day_3 * 8) << " ";
			for (int i = 1; i <= 29; i++) {
				cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day_3) % 7 != 0) {
					cout << "  ";
				}
				if ((i + day_3) % 7 == 0) {
					cout << endl;
				}
			}
			if (day_3 != 6)
				cout << endl;
		}
		else {
			if (day_3 != 0)
				cout << setw(day_3 * 8) << " ";
			for (int i = 1; i <= 28; i++) {
				cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day_3) % 7 != 0) {
					cout << "  ";
				}
				if ((i + day_3) % 7 == 0) {
					cout << endl;
				}
			}
			if (day_3 != 0)
				cout << endl;
		}
	}
	//��������������
	//1,3,5,7,8,10,12��
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day_3 != 0)
			cout << setw(day_3 * 8) << " ";
		for (int i = 1; i <= 31; i++) {
			cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day_3) % 7 != 0) {
				cout << "  ";
			}
			if ((i + day_3) % 7 == 0) {
				cout << endl;
			}
		}
		if (day_3 != 4)
			cout << endl;
	}
	//4,6,9,11��
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day_3 != 0)
			cout << setw(day_3 * 8) << " ";
		for (int i = 1; i <= 30; i++) {
			cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day_3) % 7 != 0) {
				cout << "  ";
			}
			if ((i + day_3) % 7 == 0) {
				cout << endl;
			}
		}
		if (day_3 != 5)
			cout << endl;
	}
	
	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}

int main() {
	int year, month;
	//���봦��
	while (true) {
		cout << "��������[1900-2100]���£�" << endl;
		cin >> year >> month;
		if (cin.fail()) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 1900 || year>2100) {
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else if (month < 1 || month>12) {
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		else if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
	}
	cout << endl;

	calender(year, month);

	return 0;
}