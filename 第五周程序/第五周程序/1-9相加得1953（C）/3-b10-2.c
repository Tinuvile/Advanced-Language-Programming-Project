
/* ��16 2352495 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	int i = 100, count = 0;
	int sum;
	
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	for (i; i <= 999; i++) {
		for (int j = i + 1; j <= 999; j++) {
			for (int k = j + 1; k <= 999; k++) {
				sum = i + j + k;

				if (sum == 1953) {
					//����һ��������i,j,k�ֱ����ڰ�λ��ʮλ����λ
					int n = i * 1000000 + j * 1000 + k;
					bool b = true;
					//ͨ��ͳ�������ÿ�����ֳ��ָ������ж��Ƿ��ظ�
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
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
