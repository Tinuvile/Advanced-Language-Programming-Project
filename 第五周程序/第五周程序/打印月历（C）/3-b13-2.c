/* 信16 2352495 张竹和*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
	int year, month, day, ret;

	//输入年份及月份
	while (true) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret != 2) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n');
			continue;
		}
		else if (year < 2000 || year>2030 || month < 1 || month>12) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
			//正确部分跳出循环
			break;
		}
	}
	//输入星期
	while (true) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",year,month);
		ret = scanf("%d", &day);
		if (ret != 1) {
			printf("输入非法，请重新输入\n");
			while (getchar() != '\n');
			continue;
		}
		else if (day < 0 || day>6) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		else if (day >= 0 && day <= 6) {
			//正确部分跳出循环
			break;
		}
	}
	//输入流完成，进入打印部分

	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	//下面的输出每天宽度为8并居中
	//需考虑闰年的2月以及12个月的天数
	//单独处理闰年的2月
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
			printf("%*s", day * 8, " ");
			//cout << setw(day * 8) << " ";
			for (int i = 1; i <= 29; i++) {
				printf("%4d  ", i);
				//cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					printf("  ");
					//cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					printf("\n");
					//cout << endl;
				}
			}
		}
		else {
			printf("%*s", day * 8, " ");
			//cout << setw(day * 8) << " ";
			for (int i = 1; i <= 28; i++) {
				printf("%4d  ", i);
				//cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					printf("  ");
					//cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					printf("\n");
					//cout << endl;
				}
			}
		}
	}
	//其他均正常处理
	//1,3,5,7,8,10,12月
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		printf("%*s", day * 8, " ");
		//cout << setw(day * 8) << " ";
		for (int i = 1; i <= 31; i++) {
			printf("%4d  ", i);
			//cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				printf("  ");
				//cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				printf("\n");
				//cout << endl;
			}
		}
	}
	//4,6,9,11月
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		printf("%*s", day * 8, " ");
		//cout << setw(day * 8) << " ";
		for (int i = 1; i <= 30; i++) {
			printf("%4d  ", i);
			//cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				printf("  ");
				//cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				printf("\n");
				//cout << endl;
			}
		}
	}
	printf("\n");

	return 0;
}