/* 2352495 ��16 ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int grade_input[1000] = { 0 }, grade[101] = { 0 };
	int input = 0;
	int count = 0;
	printf("������ɼ������1000������������������\n");
	for (int i = 0; i < 1000; i++) {
		scanf("%d", &input);
		if (input < 0) {
			if (i == 0)
				printf("����Ч����\n");
			break;
		}
		grade_input[i] = input;
		grade[input]++;
		count++;
	}
	printf("���������Ϊ:\n");
	for (int i = 0; i < count; i++) {
		printf("%d ", grade_input[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for (int i = 100; i >= 0; i--) {
		if (grade[i] > 0) {
			printf("%d %d\n", i, grade[i]);
		}
	}
	return 0;
}
//87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1