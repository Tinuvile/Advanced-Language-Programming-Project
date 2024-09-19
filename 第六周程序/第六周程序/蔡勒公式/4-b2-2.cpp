/* 2352495 信16 张竹和 */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	//变量赋值
	int y_last2, cen_1, mon, day_1, w, day_2;
	if (m == 1 || m == 2) {
		mon = m + 12;
		cen_1 = int((y-1) / 100);
		y_last2 = (y-1) % 100;
	}
	else {
		mon = m;
		cen_1 = int(y / 100);
		y_last2 = y % 100;
	}
	day_1 = d;

	//公式计算
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

int main() {
	int year, month, day;

	//输入处理
	while (true) {
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;
		if (cin.fail()) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 1900 || year>2100) {
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (month < 1 || month>12) {
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		else if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12) {
			//正确部分跳出循环
			//闰年二月
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
				if (day >= 1 && day <= 29)
					break;
				else {
					cout << "日不正确，请重新输入" << endl;
					continue;
				}
			}
			//非闰年二月均一致
			else {
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					if (day >= 1 && day <= 31)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
					    continue;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {
					if (day >= 1 && day <= 30)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
					continue;
				}
				else if (month == 2) {
					if (day >= 1 && day <= 28)
						break;
					else
						cout << "日不正确，请重新输入" << endl;
					continue;
				}
			}
		}
	}

	zeller(year, month, day);

	//输出处理
	if (zeller(year, month, day) == 0)
		cout << "星期日" << endl;
	if (zeller(year, month, day) == 1)
		cout << "星期一" << endl;
	if (zeller(year, month, day) == 2)
		cout << "星期二" << endl;
	if (zeller(year, month, day) == 3)
		cout << "星期三" << endl;
	if (zeller(year, month, day) == 4)
		cout << "星期四" << endl;
	if (zeller(year, month, day) == 5)
		cout << "星期五" << endl;
	if (zeller(year, month, day) == 6)
		cout << "星期六" << endl;

	return 0;
}