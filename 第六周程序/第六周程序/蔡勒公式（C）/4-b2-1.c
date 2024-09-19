/* 2352495 ��16 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int zeller(int y, int m, int d)
{
	//������ֵ
	int y_last2, cen_1, mon, day_1, w, day_2;
	if (m == 1 || m == 2) {
		mon = m + 12;
		cen_1 = (int)((y - 1) / 100);
		y_last2 = (y - 1) % 100;
	}
	else {
		mon = m;
		cen_1 = (int)(y / 100);
		y_last2 = y % 100;
	}
	day_1 = d;

	//��ʽ����
	w = y_last2 + (int)(y_last2 / 4) + (int)(cen_1 / 4) - 2 * cen_1 + (int)(26 * (mon + 1) / 10) + day_1 - 1;
	if (w >= 0)
		day_2 = w % 7;
	if (w < 0) {
		for (int i = 1; w < 0; i++) {
			w = w + 7 * i;
			day_2 = w % 7;
		}
	}
	return day_2;
}

int main() {
	int year, month, day, ret;

	//���봦��
	while (true) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d %d %d", &year, &month, &day);
		if (ret != 3) {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
			continue;
		}
		else if (year < 1900 || year>2100) {
			printf( "��ݲ���ȷ������������" );
			continue;
		}
		else if (month < 1 || month>12) {
			printf( "�·ݲ���ȷ������������" );
			continue;
		}
		else if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12) {
			//��ȷ��������ѭ��
			//�������
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
				if (day >= 1 && day <= 29)
					break;
				else {
					printf( "�ղ���ȷ������������" );
					continue;
				}
			}
			//��������¾�һ��
			else {
				if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
					if (day >= 1 && day <= 31)
						break;
					else
						printf( "�ղ���ȷ������������" );
					continue;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11) {
					if (day >= 1 && day <= 30)
						break;
					else
						printf( "�ղ���ȷ������������" );
					continue;
				}
				else if (month == 2) {
					if (day >= 1 && day <= 28)
						break;
					else
						printf( "�ղ���ȷ������������" );
					continue;
				}
			}
		}
	}

	zeller(year, month, day);

	//�������
	if (zeller(year, month, day) == 0)
		printf("������");
	if (zeller(year, month, day) == 1)
		printf("����һ");
	if (zeller(year, month, day) == 2)
		printf("���ڶ�");
	if (zeller(year, month, day) == 3)
		printf("������");
	if (zeller(year, month, day) == 4)
		printf("������");
	if (zeller(year, month, day) == 5)
		printf("������");
	if (zeller(year, month, day) == 6)
		printf("������");

	return 0;
}