#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	printf("请输入一个[1..30000]之间的整数:\n");
	scanf("%ld", &a);
	printf("万位 : %d\n", a / 10000 % 10);
	printf("千位 : %d\n", a / 1000 % 10);
	printf("百位 : %d\n", a / 100 % 10);
	printf("十位 : %d\n", a / 10 % 10);
	printf("个位 : %d\n", a / 1 % 10);

	return 0;
}