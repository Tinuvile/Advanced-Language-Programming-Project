/* ��16 2352495 �����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main() {
	int year, month, day, ret;

	//������ݼ��·�
	while (true) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &year, &month);
		if (ret != 2) {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
			continue;
		}
		else if (year < 2000 || year>2030 || month < 1 || month>12) {
			printf("����Ƿ�������������\n");
			continue;
		}
		else if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
			//��ȷ��������ѭ��
			break;
		}
	}
	//��������
	while (true) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ",year,month);
		ret = scanf("%d", &day);
		if (ret != 1) {
			printf("����Ƿ�������������\n");
			while (getchar() != '\n');
			continue;
		}
		else if (day < 0 || day>6) {
			printf("����Ƿ�������������\n");
			continue;
		}
		else if (day >= 0 && day <= 6) {
			//��ȷ��������ѭ��
			break;
		}
	}
	//��������ɣ������ӡ����

	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	//��������ÿ����Ϊ8������
	//�迼�������2���Լ�12���µ�����
	//�������������2��
	if (month == 2) {
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) && (month == 2)) {
			printf("%*s", day * 8, " ");
			//cout << setw(day * 8) << " ";
			for (int i = 1; i <= 29; i++) {
				printf("%4d  ", i);
				//cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					printf("  ");
					//cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					printf("\n");
					//cout << endl;
				}
			}
		}
		else {
			printf("%*s", day * 8, " ");
			//cout << setw(day * 8) << " ";
			for (int i = 1; i <= 28; i++) {
				printf("%4d  ", i);
				//cout << setw(4) << setfill(' ') << i << "  ";
				if ((i + day) % 7 != 0) {
					printf("  ");
					//cout << "  ";
				}
				if ((i + day) % 7 == 0) {
					printf("\n");
					//cout << endl;
				}
			}
		}
	}
	//��������������
	//1,3,5,7,8,10,12��
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		printf("%*s", day * 8, " ");
		//cout << setw(day * 8) << " ";
		for (int i = 1; i <= 31; i++) {
			printf("%4d  ", i);
			//cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				printf("  ");
				//cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				printf("\n");
				//cout << endl;
			}
		}
	}
	//4,6,9,11��
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		printf("%*s", day * 8, " ");
		//cout << setw(day * 8) << " ";
		for (int i = 1; i <= 30; i++) {
			printf("%4d  ", i);
			//cout << setw(4) << setfill(' ') << i << "  ";
			if ((i + day) % 7 != 0) {
				printf("  ");
				//cout << "  ";
			}
			if ((i + day) % 7 == 0) {
				printf("\n");
				//cout << endl;
			}
		}
	}
	printf("\n");

	return 0;
}