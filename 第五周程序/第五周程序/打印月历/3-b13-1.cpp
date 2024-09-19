/* ��16 2352495 �����*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int year, month, day;

	//������ݼ��·�
	while (true) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (cin.fail()) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 2000 || year>2030 || month < 1 || month>12) {
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
			//��ȷ��������ѭ��
			break;
		}
	}
	//��������
	while (true) {
		cout << "������" << year << "��" << month << "��" << "1�յ�����(0-6��ʾ������-������) : ";
		cin >> day;
		if (cin.fail()) {
			cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (day < 0 || day>6) {
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		else if (day >= 0 && day <= 6) {
			//��ȷ��������ѭ��
			break;
		}
	}
	//��������ɣ������ӡ����

	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	//��������ÿ����Ϊ6�����У���ÿ����ӡ�����ո�
	//�迼�������2���Լ�12���µ�����
	//�������������2��
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
			cout << setw(day * 8) << " ";
			for (int i = 1; i <= 29; i++) {
				cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					cout << endl;
				}
			}
		}
		else {
			cout << setw(day * 8) << " ";
			for (int i = 1; i <= 28; i++) {
				cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					cout << endl;
				}
			}
		}
	}
	//��������������
	//1,3,5,7,8,10,12��
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		cout << setw(day * 8) << " ";
		for (int i = 1; i <= 31; i++) {
			cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				cout << endl;
			}
		}
	}
	//4,6,9,11��
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		cout << setw(day * 8) << " ";
		for (int i = 1; i <= 30; i++) {
			cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;

	return 0;
}