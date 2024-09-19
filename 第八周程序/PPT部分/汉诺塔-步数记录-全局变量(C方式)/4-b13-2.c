/* 2352495 张竹和 信16 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

int count = 1;

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		count++;
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		count++;
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int num_floor;
	char begin_p, between_p, end_p;
	int ret;
	//输入处理
	while (1) {
		printf("请输入汉诺塔的层数(1-16)\n");
		ret = scanf("%d", &num_floor);
		if (ret != 1) {
			//cout << "输入非法，请重新输入" << endl;
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor < 1 || num_floor>16) {
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor >= 1 && num_floor <= 16) {
			while (getchar() != '\n');
			break;
		}
	}
	while (1) {
		printf("请输入起始柱(A-C)\n");
		ret = scanf("%c", &begin_p);
		if (ret != 1) {
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
		ret = scanf("%c", &end_p);
		if (ret != 1) {
			//cout << "输入非法，请重新输入" << endl;
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
	//函数调用
	hanoi(num_floor, begin_p, between_p, end_p);

	return 0;
}