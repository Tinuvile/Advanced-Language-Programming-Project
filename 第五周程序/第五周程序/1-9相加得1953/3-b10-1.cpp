/* 信16 2352495 张竹和*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

/* 信16 2352495 张竹和*/
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
						cout << "No." << setw(3) << setiosflags(ios::right) << count << " : " << i << "+" << j << "+" << k << "=" << sum << endl;
					}
				}
			}
		}
	}
	cout << "total=" << count << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}