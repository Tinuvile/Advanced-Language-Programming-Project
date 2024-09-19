#include <iostream>
#include <cstring>
using namespace std;

/***************************************************************************
  �������ƣ�calender
  ��    �ܣ���ӡÿ���µ�ÿ��
  ���������year,month
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void calender(int year, int month)
{
	/* ������Ӵ��� */
	int day = 1;
	int day_3 = zeller(year, month, day);

	/* ������Ӵ��� */
	//��������ÿ����Ϊ2��Ĭ���Ҷ��룬��ÿ����ӡ�ո�
	//�迼�������2���Լ�12���µ�����
	//�������������2��
	//����setw(0)�����һ���ַ�λ
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
			if (day_3 != 0)
				cout << setw(day_3 * 4) << " ";
			for (int i = 1; i <= 29; i++) {
				cout << left << setw(2) << setfill(' ') << i << " ";
				if ((i + day_3) % 7 != 0) {
					cout << " ";
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
				cout << setw(day_3 * 4) << " ";
			for (int i = 1; i <= 28; i++) {
				cout << left << setw(2) << setfill(' ') << i << " ";
				if ((i + day_3) % 7 != 0) {
					cout << " ";
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
			cout << setw(day_3 * 4) << " ";
		for (int i = 1; i <= 31; i++) {
			cout << left << setw(2) << setfill(' ') << i << " ";
			if ((i + day_3) % 7 != 0) {
				cout << " ";
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
			cout << setw(day_3 * 4) << " ";
		for (int i = 1; i <= 30; i++) {
			cout << left << setw(2) << setfill(' ') << i << " ";
			if ((i + day_3) % 7 != 0) {
				cout << " ";
			}
			if ((i + day_3) % 7 == 0) {
				cout << endl;
			}
		}
		if (day_3 != 5)
			cout << endl;
	}
}

int main()
{
	for (int month = 1; month <= 12; month++) {
		calender(year, month);
	}

    char i;
    //char n = char(i);
    i = cin.get();
    //char i = 1011;
    //char str1[] = "abcd", str2[] = "abcd";

    //cout << strncmp(str1, str2, 3) << endl;
    //cout << strncmp(str1, str2, 4) << endl;
    //cout << strncmp(str1, str2, 5) << endl;
    //cout << strncmp(str1, str2, 100) << endl;
    //cout << int(char(i)) << endl;
    //cout << int(i) << endl;
    cout << i << endl;
    return 0;
}