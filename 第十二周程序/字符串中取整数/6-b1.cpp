/* 2352495 ����� ��16 */
#include <iostream>
#include <cstdio>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);

	p = str;
	pa = a;
	pnum = a;
	is_num = false;

	while (*p != '\0') {
		if (pa - a < 10) {
			if ((*p >= '0') && (*p <= '9')) {
				is_num = true;
			}
			else {
				is_num = false;
			}
			if (is_num) {
				//������һλ�����ֵĽ�λ
				*pa = *pa * 10 + (*p - '0');
				//�����һλ�Ƿ�������
				p++;
				if ((*p < '0') || (*p > '9')) {
					pa++;
					p++;
				}
			}
			else
				p++;
		}
		else
			break;
	}

	cout << "����" << pa - a << "������" << endl;

	while (pnum < pa) {
		cout << *pnum << " ";
		pnum++;
	}


	return 0;
}
//hello -123w xyz k456.78 kjd 98
//a1b2c3d4e5f6g7h8i9j10k11