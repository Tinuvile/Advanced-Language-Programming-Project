/* 2352495 ��16 ����� */
#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> day;
	//�ж��Ƿ�������
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
	{
		switch (month) {
			case 1:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 2:
				if (day >= 1 && day <= 29)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 3:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 60 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 4:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 91 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 5:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 121 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 6:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 152 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 7:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 182 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 8:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 213 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 9:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 244 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 10:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 274 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 11:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 305 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 12:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 335 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			default:
				cout << "�������-�·ݲ���ȷ" << endl;
		}
	}
	//��������
	else
	{
		switch (month) {
			case 1:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 2:
				if (day >= 1 && day <= 28)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 3:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 59 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 4:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 90 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 5:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 120 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 6:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 151 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 7:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 181 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 8:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 212 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 9:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 243 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 10:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 273 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 11:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 304 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			case 12:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 334 << "��" << endl;
				else
					cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			default:
				cout << "�������-�·ݲ���ȷ" << endl;
		}
		return 0;
	}
}