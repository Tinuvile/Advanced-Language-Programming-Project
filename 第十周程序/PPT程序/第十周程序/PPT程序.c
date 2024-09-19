#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double num;
    int width, precision;

    printf("请输入一个double型数据及显示总宽度、小数点后位数\n");
    scanf("%lf %d %d", &num, &width, &precision);

    printf("01234567890123456789\n"); //标尺

    char fmt[20];
    sprintf(fmt, "%%%d.%df*\n", width, precision); // 创建格式化字符串
    printf(fmt, num); // 使用格式化字符串输出

    return 0;
}