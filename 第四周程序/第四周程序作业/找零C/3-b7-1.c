/* 2352495 ��16 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double money, x;
	double a = 50, b = 20, c = 10, d = 5, e = 1, f = 0.5, g = 0.1, h = 0.05, i = 0.02, j = 0.01;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, y;
	printf( "����������ֵ��\n");
	scanf("%lf", &money);
	n1 = (int)(money / a);
	n2 = (int)((money - a * n1) / b);
	n3 = (int)((money - a * n1 - b * n2) / c);
	n4 = (int)((money - a * n1 - b * n2 - c * n3) / d);
	n5 = (int)((money - a * n1 - b * n2 - c * n3 - d * n4) / e);
	
	x = a * n1 + b * n2 + c * n3 + d * n4 + e * n5;
	y = (int)(round(100 * (money - x)));
	n6 = (int)(y / 50);
	n7 = (int)((y - 50 * n6) / 10);
	n8 = (int)((y - 50 * n6 - 10 * n7) / 5);
	n9 = (int)((y - 50 * n6 - 10 * n7 - 5 * n8) / 2);
	n10 = (int)((y - 50 * n6 - 10 * n7 - 5 * n8 - 2 * n9) / 1);

	printf( "��%d�����㣬�������£�\n",n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10);
	if (n1 != 0)
		printf( "50Ԫ : %d��\n",n1 );
	if (n2 != 0)
		printf( "20Ԫ : %d��\n",n2 );
	if (n3 != 0)
		printf( "10Ԫ : %d��\n",n3 );
	if (n4 != 0)
		printf( "5Ԫ  : %d��\n",n4 );
	if (n5 != 0)
		printf( "1Ԫ  : %d��\n",n5 );
	if (n6 != 0)
		printf( "5��  : %d��\n",n6 );
	if (n7 != 0)
		printf( "1��  : %d��\n",n7 );
	if (n8 != 0)
		printf( "5��  : %d��\n",n8 );
	if (n9 != 0)
		printf( "2��  : %d��\n",n9 );
	if (n10 != 0)
		printf( "1��  : %d��\n",n10);

	return 0;
}