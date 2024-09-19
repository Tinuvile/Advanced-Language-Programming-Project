/* –≈16 2352495 ’≈÷Ò∫Õ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j, result;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= i; j++) {
			result = i * j;
			/*
			if (j == 2) {
				if (i == 2 || i == 3 || i == 4) {
					printf("%-dx%-d=%-d   ", j, i, result);
				}
			}
			else {
				printf("%-dx%-d=%-d  ", j, i, result);
			}
			if (j == 1) {
				printf(" ");
			}
			*/
			printf("%-dx%-d=", j, i);
			printf("%-4d", result);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}