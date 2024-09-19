#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, x;
	float s;
	double x1;
	const double pi = 3.14159;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%ld %ld %ld", &a, &b, &x);
	x1 = x * pi / 180;
	s = (a * b * sin(x1) / 2);
	printf("三角形面积为 : %.3f", s);
	return 0;
}