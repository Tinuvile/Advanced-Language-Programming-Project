/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int input(char input_number[], char input_name[],int n)
{
	int grade = 0;
	printf("请输入第%d个人的学号、姓名、成绩\n", n);
	scanf("%s %s %d", input_number, input_name, &grade);
	return grade;
}

void sort(char student_number[][8], char student_name[][8], int student_grade[], int n)
{
	int i,j;
	char temp[8];
	int temp_grade;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++) {
			if (strcmp(student_number[j], student_number[j + 1]) < 0) {
				strcpy(temp, student_number[j]);
				strcpy(student_number[j], student_number[j + 1]);
				strcpy(student_number[j + 1], temp);

				strcpy(temp, student_name[j]);
				strcpy(student_name[j], student_name[j + 1]);
				strcpy(student_name[j + 1], temp);

				temp_grade = student_grade[j];
				student_grade[j] = student_grade[j + 1];
				student_grade[j + 1] = temp_grade;
			}
		}
	}
}

void output(char student_number[][8], char student_name[][8], int student_grade[])
{
	printf("\n及格名单(学号降序)\n");
	for (int i = 1; i <= 10; i++) {
		if (student_grade[i] >= 60) {
			printf("%s %s %d\n", student_name[i], student_number[i], student_grade[i]);
		}
	}
}

int main() {
	char student_number[11][8] = { '\0' };
	char student_name[11][8] = { '\0' };
	int student_grade[11] = { 0 };
	//输入处理
	for (int i = 1; i <= 10; i++) {
		student_grade[i] = input(student_number[i], student_name[i], i);
	}
	//排序
    sort(student_number, student_name, student_grade, 10);

    //输出
    output(student_number, student_name, student_grade);

    return 0;
}

/*
2352031 古振 76
2251989 徐奕栋 54
2352731 毛韩宇 82
2353914 韩一墨 71
2353250 罗力 49
2253797 黄艺鑫 87
2353237 赵昱翔 82
2351454 黄文 34
2353367 肖家余 53
2354367 何勿思 71
*/