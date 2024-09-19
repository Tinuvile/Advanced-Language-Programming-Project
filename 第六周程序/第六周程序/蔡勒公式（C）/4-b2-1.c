/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int zeller(int y, int m, int d)
{
	//变量赋值
	int y_last2, cen_1, mon, day_1, w, day_2;
	if (m == 1 || m == 2) {
		mon = m + 12;
		cen_1 = (int)((y - 1) / 100);
		y_last2 = (y - 1) % 100;
	}
	else {
		mon = m;
		cen_1 = (int)(y / 100);
		y_last2 = y % 100;
	}
	day_1 = d;

	//公式计算
	w = y_last2 + (int)(y_last2 / 4) + (int)(cen_1 / 4) - 2 * cen_1 + (int)(26 * (mon + 1) / 10) + day_1 - 1;
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
	int year, month, day, ret;

	//输入处理
	while (true) {
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d %d %d", &year, &month, &day);
		if (ret != 3) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n');
			continue;
		}
		else if (year < 1900 || year>2100) {
			printf( "年份不正确，请重新输入" );
			continue;
		}
		else if (month < 1 || month>12) {
			printf( "月份不正确，请重新输入" );
			continue;
		}
		else if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12) {
			//正确部分跳出循环
			//闰年二月
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
				if (day >= 1 && day <= 29)
					break;
				else {
					printf( "日不正确，请重新输入" );
					continue;
				}
			}
			//非闰年二月均一致
			else {
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					if (day >= 1 && day <= 31)
						break;
					else
						printf( "日不正确，请重新输入" );
					continue;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {
					if (day >= 1 && day <= 30)
						break;
					else
						printf( "日不正确，请重新输入" );
					continue;
				}
				else if (month == 2) {
					if (day >= 1 && day <= 28)
						break;
					else
						printf( "日不正确，请重新输入" );
					continue;
				}
			}
		}
	}

	zeller(year, month, day);

	//输出处理
	if (zeller(year, month, day) == 0)
		printf("星期日");
	if (zeller(year, month, day) == 1)
		printf("星期一");
	if (zeller(year, month, day) == 2)
		printf("星期二");
	if (zeller(year, month, day) == 3)
		printf("星期三");
	if (zeller(year, month, day) == 4)
		printf("星期四");
	if (zeller(year, month, day) == 5)
		printf("星期五");
	if (zeller(year, month, day) == 6)
		printf("星期六");

	return 0;
}