#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double num;
    int width, precision;

    printf("������һ��double�����ݼ���ʾ�ܿ�ȡ�С�����λ��\n");
    scanf("%lf %d %d", &num, &width, &precision);

    printf("01234567890123456789\n"); //���

    char fmt[20];
    sprintf(fmt, "%%%d.%df*\n", width, precision); // ������ʽ���ַ���
    printf(fmt, num); // ʹ�ø�ʽ���ַ������

    return 0;
}