#include <iostream>
#include <cstring>
using namespace std;

/***************************************************************************
  函数名称：calender
  功    能：打印每个月的每行
  输入参数：year,month
  返 回 值：
  说    明：
***************************************************************************/
void calender(int year, int month)
{
	/* 按需添加代码 */
	int day = 1;
	int day_3 = zeller(year, month, day);

	/* 按需添加代码 */
	//下面的输出每天宽度为2并默认右对齐，在每天后打印空格
	//需考虑闰年的2月以及12个月的天数
	//单独处理闰年的2月
	//发现setw(0)会填充一个字符位
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
	//其他均正常处理
	//1,3,5,7,8,10,12月
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
	//4,6,9,11月
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