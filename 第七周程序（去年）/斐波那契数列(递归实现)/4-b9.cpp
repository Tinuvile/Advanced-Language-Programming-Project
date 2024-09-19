/* 2352495 ��16 �����*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������
  �� �� ֵ��
  ˵    �����������κ���ʽ��ѭ������
***************************************************************************/
int fibonacci(int n, double& x)
{
	/* ��Ҫ����ɱ����� */
	int F = 0;
	if (n == 1) {
		F = 1;
		return F;
	}
	if (n == 2) {
		F = 1;
		return F;
	}
	if (n >= 3) {
		F = fibonacci(n - 1,x) + fibonacci(n - 2,x);
		x = x + 2;
		return F;
	}
	else
		return F;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	int n, f;
	double x = 1;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n,x);
	cout << "ִ�д���" << x << endl;
	cout << fibonacci(n,x) << "=" << fibonacci(n - 1, x) << "+" << fibonacci(n - 2, x) << endl;
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;

	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}