/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double money, x;
	double a = 50, b = 20, c = 10, d = 5, e = 1, f = 0.5, g = 0.1, h = 0.05, i = 0.02, j = 0.01;
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, y;
	printf( "请输入找零值：\n");
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

	printf( "共%d张找零，具体如下：\n",n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10);
	if (n1 != 0)
		printf( "50元 : %d张\n",n1 );
	if (n2 != 0)
		printf( "20元 : %d张\n",n2 );
	if (n3 != 0)
		printf( "10元 : %d张\n",n3 );
	if (n4 != 0)
		printf( "5元  : %d张\n",n4 );
	if (n5 != 0)
		printf( "1元  : %d张\n",n5 );
	if (n6 != 0)
		printf( "5角  : %d张\n",n6 );
	if (n7 != 0)
		printf( "1角  : %d张\n",n7 );
	if (n8 != 0)
		printf( "5分  : %d张\n",n8 );
	if (n9 != 0)
		printf( "2分  : %d张\n",n9 );
	if (n10 != 0)
		printf( "1分  : %d张\n",n10);

	return 0;
}