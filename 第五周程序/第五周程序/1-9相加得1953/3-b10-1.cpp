/* ��16 2352495 �����*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

/* ��16 2352495 �����*/
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
						cout << "No." << setw(3) << setiosflags(ios::right) << count << " : " << i << "+" << j << "+" << k << "=" << sum << endl;
					}
				}
			}
		}
	}
	cout << "total=" << count << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}