/* 信16 2352495 张竹和*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int year, month, day;

	//输入年份及月份
	while (true) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail()) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 2000 || year>2030 || month < 1 || month>12) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
			//正确部分跳出循环
			break;
		}
	}
	//输入星期
	while (true) {
		cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
		cin >> day;
		if (cin.fail()) {
			cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (day < 0 || day>6) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else if (day >= 0 && day <= 6) {
			//正确部分跳出循环
			break;
		}
	}
	//输入流完成，进入打印部分

	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	//下面的输出每天宽度为6并居中，在每天后打印两个空格
	//需考虑闰年的2月以及12个月的天数
	//单独处理闰年的2月
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
	//其他均正常处理
	//1,3,5,7,8,10,12月
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
	//4,6,9,11月
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