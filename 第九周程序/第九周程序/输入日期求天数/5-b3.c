/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int judge_leapyear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0)) {
		return 29;
	}
	else
		return 28;
}

int day_number(int year_day[], int month, int day)
{
	int total_day = 0;
	for (int i = 0; i < month - 1; i++) {
		total_day += year_day[i];
	}
	total_day += day;
	return total_day;
}

int main() {
	int year, month, day, day_2;
	int ret;
	int year_day[] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年，月，日\n");
	ret = scanf("%d %d %d", &year, &month, &day);
	if (ret != 3) {
		//while ((x = getchar()) != EOF && x != '\n');//清除缓冲区的语句1
		while (getchar() != '\n');//清除缓冲区的语句2
	}
	if (month < 1 || month>12) {
		printf("输入错误-月份不正确\n");
		while (getchar() != '\n');
	}
	day_2 = judge_leapyear(year);
	year_day[1] = day_2;
	if (day<1 || day>year_day[month - 1]) {
		printf("输入错误-日与月的关系非法\n");
	}
	int total_day = day_number(year_day, month, day);
	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, total_day);
	return 0;
}