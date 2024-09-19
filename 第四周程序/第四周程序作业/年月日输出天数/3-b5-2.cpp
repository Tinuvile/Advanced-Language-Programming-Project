/* 2352495 信16 张竹和 */
#include <iostream>
using namespace std;

int main()
{
	int year, month, day;
	cout << "请输入年，月，日" << endl;
	cin >> year >> month >> day;
	//判断是否是闰年
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
	{
		switch (month) {
			case 1:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 2:
				if (day >= 1 && day <= 29)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 3:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 60 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 4:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 91 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 5:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 121 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 6:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 152 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 7:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 182 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 8:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 213 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 9:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 244 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 10:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 274 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 11:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 305 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 12:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 335 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
		}
	}
	//不是闰年
	else
	{
		switch (month) {
			case 1:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 2:
				if (day >= 1 && day <= 28)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 31 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 3:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 59 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 4:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 90 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 5:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 120 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 6:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 151 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 7:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 181 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 8:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 212 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 9:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 243 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 10:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 273 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 11:
				if (day >= 1 && day <= 30)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 304 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			case 12:
				if (day >= 1 && day <= 31)
					cout << year << "-" << month << "-" << day << "是" << year << "年的第" << day + 334 << "天" << endl;
				else
					cout << "输入错误-日与月的关系非法" << endl;
				break;
			default:
				cout << "输入错误-月份不正确" << endl;
		}
		return 0;
	}
}