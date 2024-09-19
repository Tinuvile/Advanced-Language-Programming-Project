/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int i = 1;//用于计数
char src, tmp, dst;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//数组表示三个柱子里的盘子数字

//函数声明
void update_abc(int n, char src, char dst);
void total_hanoi(int n, char src, char dst);
void output_number(int print_out[]);
void output_line(int a[10], int b[10], int c[10]);
void hanoi(int n, char src, char tmp, char dst);

/***************************************************************************
	 函数名称：update_abc
	 功    能：根据递归次数更新柱子数组a,b,c
	 输入参数：int n：盘号
			   char src：起始柱
			   char dst：目标柱
	 返 回 值：
	 说    明：
   ***************************************************************************/
void update_abc(int n, char src, char dst)
{
	if (src == 'A' || src == 'a') {
		a[n - 1] = 0;
		if (dst == 'B' || dst == 'b')
			b[n-1] = n;
		if (dst == 'C' || dst == 'c')
			c[n-1] = n;
	}
	else if (src == 'B' || src == 'b') {
		b[n - 1] = 0;
		if (dst == 'A' || dst == 'a')
			a[n - 1] = n;
		if (dst == 'C' || dst == 'c')
			c[n - 1] = n;
	}
	else if (src == 'C' || src == 'c') {
		c[n - 1] = 0;
		if (dst == 'A' || dst == 'a')
			a[n - 1] = n;
		if (dst == 'B' || dst == 'b')
			b[n - 1] = n;
	}
}

/***************************************************************************
	 函数名称：total_hanoi
	 功    能：管理每行每个圆柱现有圆盘编号的输出
	 输入参数：int n：层数
	 返 回 值：
	 说    明：
   ***************************************************************************/
void total_hanoi(int n, char src, char dst)
{
	update_abc(n, src, dst);
	printf("第%4d 步(%2d): %c-->%c", i++, n, src, dst);
	output_line(a, b, c);
}

/***************************************************************************
	 函数名称：output_number
	 功    能：管理每行每个圆柱现有圆盘编号的输出
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：
   ***************************************************************************/
void output_number(int print_out[])
{
	int m = 0;//处理两位数与个位数打印的区别
	for (int t = 9; t >= 0; t--) {
		if (print_out[t] != 0) {
			if (print_out[t] != 10)
				printf("%d ", print_out[t]);
			if (print_out[t] == 10) {
				printf("%d ", print_out[t]);
				m = 1;
			}
		}
	}
	for (int t = 0; t < 10; t++) {
		if (print_out[t] == 0)
			printf("  ");
	}
	if (m == 0)
		printf(" ");
}

/***************************************************************************
	 函数名称：output_line
	 功    能：管理每行字母整体的输出
	 输入参数：a[],b[],c[]
	 返 回 值：
	 说    明：
   ***************************************************************************/
void output_line(int a[10], int b[10], int c[10])
{
	printf(" A:");
	output_number(a);
	printf("B:");
	output_number(b);
	printf("C:");
	output_number(c);
	printf("\n");
}

/***************************************************************************
	 函数名称：hanoi
	 功    能：汉诺塔的递归函数
	 输入参数：int n：层数(这里也等同于盘号)
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		total_hanoi(n, src, dst);
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		total_hanoi(n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
}

int main() {
	//输入处理
	int ret1, ret2, ret3;
	int num_floor;
	char begin_p, end_p, between_p;
	while(1) {
		printf("请输入汉诺塔的层数(1-10)\n");
		ret1 = scanf("%d", &num_floor);
		if (ret1 != 1) {
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor < 1 || num_floor>10) {
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor >= 1 && num_floor <= 10) {
			while (getchar() != '\n');
			break;
		}
	}
	while (1) {
		printf("请输入起始柱(A-C)\n");
		ret2 = scanf("%c", &begin_p);
		if (ret2 != 1) {
			while (getchar() != '\n');
			continue;
		}
		else if (begin_p != 'A' && begin_p != 'B' && begin_p != 'C' && begin_p != 'a' && begin_p != 'b' && begin_p != 'c') {
			while (getchar() != '\n');
			continue;
		}
		else if (begin_p == 'A' || begin_p == 'B' || begin_p == 'C') {
			while (getchar() != '\n');
			break;
		}
		else if (begin_p == 'a' || begin_p == 'b' || begin_p == 'c') {
			begin_p = begin_p - 32;
			while (getchar() != '\n');
			break;
		}
	}
	while (1) {
		printf("请输入目标柱(A-C)\n");
		ret3 = scanf("%c", &end_p);
		if (ret3 != 1) {
			while (getchar() != '\n');
			continue;
		}
		else if (end_p != 'A' && end_p != 'B' && end_p != 'C' && end_p != 'a' && end_p != 'b' && end_p != 'c') {
			while (getchar() != '\n');
			continue;
		}
		else
			if (((int)(end_p) - (int)(begin_p) != 32) && ((int)(end_p) - (int)(begin_p) != -32) && (end_p != begin_p)) {
				if (end_p == 'a' || end_p == 'b' || end_p == 'c') {
					end_p = end_p - 32;
				}
				while (getchar() != '\n');
				break;
			}
			else {
				printf("目标柱(%d)不能与起始柱(%d)相同\n", end_p, begin_p);
				while (getchar() != '\n');
				continue;
			}
	}
	//根据输入情况初始化数组
	for (int n = 0; n < num_floor; n++) {
		if (begin_p == 'A' || begin_p == 'a') {
			a[n] = n + 1;
			b[n] = 0;
			c[n] = 0;
		}
		if (begin_p == 'B' || begin_p == 'b') {
			a[n] = 0;
			b[n] = n + 1;
			c[n] = 0;
		}
		if (begin_p == 'C' || begin_p == 'c') {
			a[n] = 0;
			b[n] = 0;
			c[n] = n + 1;
		}
	}
	//选择中间选项
	if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'B' || end_p == 'b')) || ((begin_p == 'B' || begin_p == 'b') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'C';
	}
	else if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'C' || end_p == 'c')) || ((begin_p == 'C' || begin_p == 'c') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'B';
	}
	else {
		between_p = 'A';
	}
	//打印初始状态情况
	printf("初始:               ");
	output_line(a, b, c);
	//函数调用
	hanoi(num_floor, begin_p, between_p, end_p);

	return 0;
}