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
  �������ƣ�printMonthHeaders
  ��    �ܣ���ӡ���ڵ�Ӣ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void printMonthHeaders() {
	cout << "Sun Mon Tue Wed Thu Fri Sat";
}

/***************************************************************************
  �������ƣ�printQuarterHeaders
  ��    �ܣ���ӡ�����µ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void printQuarterHeader(int startMonth) {
	for (int i = 0; i < 3; i++) {
		cout << "           ";
		cout << right << setw(2) << setfill(' ') << startMonth + i << "��";
		if (i < 2)
			cout << "            ";
		if (i < 2) cout << "     ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++) {
		printMonthHeaders();
		if (i < 2)
			cout << "     ";
	}
	cout << endl;
}

/***************************************************************************
  �������ƣ�daysInMonth
  ��    �ܣ�����ÿ���µ�����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int daysInMonth(int year, int month) {
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
		return 29;
	}
	return days[month - 1];
}

/***************************************************************************
  �������ƣ�recordCalendar
  ��    �ܣ���ӡ3����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void recordCalendar(int year, int month1, int month2, int month3, int day1, int day2, int day3) {
	int n1 = daysInMonth(year, month1);
	int n2 = daysInMonth(year, month2);
	int n3 = daysInMonth(year, month3);

	int record[7][24] = { 0 }; 
	int offsets[3] = { 0, 8, 16 }; // ��¼ÿ���µ�ƫ����
	int days[3] = { day1, day2, day3 }; //ÿ���µ���ʼ����
	int months[3] = { n1, n2, n3 }; //ÿ���µ�����

	//���ÿ���µ�����
	for (int m = 0; m < 3; m++) {
		int r = 1;
		for (int i = 1; i < days[m] + 1; i++) {
			record[1][i + offsets[m]] = 666; //���ո�
		}
		for (int i = 1; i <= months[m]; i++) {
			record[r][days[m] + 1 + offsets[m]] = i; //���ÿ���µľ�������
			if (days[m] == 6) {
				record[r][days[m] + 2 + offsets[m]] = 666;
				r++;
			}
			days[m] = (days[m] + 1) % 7; //��������
		}
	}

	for (int i = 1; i <= 6; i++) {
		int judge = 0;
		for (int j = 1; j < 24; j++) {
			if (record[i][j] == 666 || record[i][j] == 0)
				cout << left << setw(4) << " ";
			else {
				cout << left << setw(4) << record[i][j];
				judge = 1;
			}
			if ((j == 23) && (judge == 1))
				cout << endl;
		}
	}
}

int main() {
	int year;
	//���봦��
	while (true) {
		cout << "���������[1900-2100]" << endl;
		cin >> year;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 1900 || year>2100) {
			continue;
		}
		else
			break;
	}
	
	cout << year << "�������:" << endl;
	cout << endl;

	int week[13] = { 0 };  // �洢ÿ�µ���ʼ����

	//ѭ���ĸ�����
	for (int quarter = 1; quarter <= 4; quarter++) {
		int startMonth = (quarter - 1) * 3 + 1;
		printQuarterHeader(startMonth);
		for (int i = 0; i < 3; i++) {
			week[startMonth + i] = zeller(year, startMonth + i, 1);
		}
		recordCalendar(year, startMonth, startMonth + 1, startMonth + 2, week[startMonth], week[startMonth + 1], week[startMonth + 2]);
		cout << endl;
	}
	cout << endl;

	return 0;
}