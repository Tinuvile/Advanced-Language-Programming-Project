/* 信16 2352495 张竹和*/
#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************
  函数名称：zeller
  功    能：输出规定年月日对应的天数
  输入参数：y,m,d
  返 回 值：day_2
  说    明：
***************************************************************************/
int zeller(int y, int m, int d)
{
	//变量赋值
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

/***************************************************************************
  函数名称：calender
  功    能：按格式输出月历
  输入参数：year,month
  返 回 值：
  说    明：
***************************************************************************/
void calender(int year, int month)
{
	/* 按需添加代码 */
	int day = 1;
	int day_3 = zeller(year, month, day);

	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	//下面的输出每天宽度为4并默认右对齐，在每天后打印两个空格
	//需考虑闰年的2月以及12个月的天数
	//单独处理闰年的2月
	//发现setw(0)会填充一个字符位
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
	//其他均正常处理
	//1,3,5,7,8,10,12月
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
	//4,6,9,11月
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
	
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main() {
	int year, month;
	//输入处理
	while (true) {
		cout << "请输入年[1900-2100]、月：" << endl;
		cin >> year >> month;
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
		else if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12)
			break;
	}
	cout << endl;

	calender(year, month);

	return 0;
}