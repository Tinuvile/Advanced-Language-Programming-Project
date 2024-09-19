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
  函数名称：printMonthHeaders
  功    能：打印星期的英文
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void printMonthHeaders() {
	cout << "Sun Mon Tue Wed Thu Fri Sat";
}

/***************************************************************************
  函数名称：printQuarterHeaders
  功    能：打印三个月的名称
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void printQuarterHeader(int startMonth) {
	for (int i = 0; i < 3; i++) {
		cout << "           ";
		cout << right << setw(2) << setfill(' ') << startMonth + i << "月";
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
  函数名称：daysInMonth
  功    能：处理每个月的天数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int daysInMonth(int year, int month) {
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
		return 29;
	}
	return days[month - 1];
}

/***************************************************************************
  函数名称：recordCalendar
  功    能：打印3个月
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void recordCalendar(int year, int month1, int month2, int month3, int day1, int day2, int day3) {
	int n1 = daysInMonth(year, month1);
	int n2 = daysInMonth(year, month2);
	int n3 = daysInMonth(year, month3);

	int record[7][24] = { 0 }; 
	int offsets[3] = { 0, 8, 16 }; // 记录每个月的偏移量
	int days[3] = { day1, day2, day3 }; //每个月的起始星期
	int months[3] = { n1, n2, n3 }; //每个月的天数

	//填充每个月的日历
	for (int m = 0; m < 3; m++) {
		int r = 1;
		for (int i = 1; i < days[m] + 1; i++) {
			record[1][i + offsets[m]] = 666; //填充空格
		}
		for (int i = 1; i <= months[m]; i++) {
			record[r][days[m] + 1 + offsets[m]] = i; //填充每个月的具体日期
			if (days[m] == 6) {
				record[r][days[m] + 2 + offsets[m]] = 666;
				r++;
			}
			days[m] = (days[m] + 1) % 7; //更新星期
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
	//输入处理
	while (true) {
		cout << "请输入年份[1900-2100]" << endl;
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
	
	cout << year << "年的日历:" << endl;
	cout << endl;

	int week[13] = { 0 };  // 存储每月的起始星期

	//循环四个季度
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