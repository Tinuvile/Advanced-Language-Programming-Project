
/* 信16 2352495 张竹和*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h> //取系统时间

int main()
{
	int i = 100, count = 0;
	int sum;
	
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	for (i; i <= 999; i++) {
		for (int j = i + 1; j <= 999; j++) {
			for (int k = j + 1; k <= 999; k++) {
				sum = i + j + k;

				if (sum == 1953) {
					//设置一个数，将i,j,k分别置于百位，十位，个位
					int n = i * 1000000 + j * 1000 + k;
					bool b = true;
					//通过统计这个数每个数字出现个数，判断是否重复
					for (int a = 1; a <= 9; a++) {
						int t = 0;
						int m = n;
						while (m > 0) {
							if (m % 10 == a) {
								t++;
							}
							m /= 10;
						}

						if (t != 1) {
							b = false;
							break;
						}
					}
					if (b) {
						count++;
						printf("No.%3d : %d+%d+%d=%d\n", count, i, j, k, sum);
					}
				}
			}
		}
	}
	printf("total=%d\n", count);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
