/* 2352495 信16 张竹和 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>


const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */


/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	char number[3];
	number[2] = '\0';
	switch (num) {
		case 0:
			if (flag_of_zero) {
				strcat(result, chnstr, 2);
			}
			break;
		case 1:
			number[0] = chnstr[2];
			number[1] = chnstr[3];
			strncat(result, number, 2);
			break;
		case 2:
			number[0] = chnstr[4];
			number[1] = chnstr[5];
			strncat(result, number, 2);
			break;
		case 3:
			number[0] = chnstr[6];
			number[1] = chnstr[7];
			strncat(result, number, 2);
			break;
		case 4:
			number[0] = chnstr[8];
			number[1] = chnstr[9];
			strncat(result, number, 2);
			break;
		case 5:
			number[0] = chnstr[10];
			number[1] = chnstr[11];
			strncat(result, number, 2);
			break;
		case 6:
			number[0] = chnstr[12];
			number[1] = chnstr[13];
			strncat(result, number, 2);
			break;
		case 7:
			number[0] = chnstr[14];
			number[1] = chnstr[15];
			strncat(result, number, 2);
			break;
		case 8:
			number[0] = chnstr[16];
			number[1] = chnstr[17];
			strncat(result, number, 2);
			break;
		case 9:
			number[0] = chnstr[18];
			number[1] = chnstr[19];
			strncat(result, number, 2);
			break;
		default:
			break;
	}
}

int main()
{
	double x, y;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	int m;
	n1 = 1000000000, n2 = 100000000, n3 = 10000000, n4 = 1000000, n5 = 100000, n6 = 10000, n7 = 1000, n8 = 100, n9 = 10, n10 = 1;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf( "%lf", &x);
	a = (int)(x / n1);
	b = (int)((x - a * n1) / n2);
	c = (int)((x - a * n1 - b * n2) / n3);
	d = (int)((x - a * n1 - b * n2 - c * n3) / n4);
	e = (int)((x - a * n1 - b * n2 - c * n3 - d * n4) / n5);
	f = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5) / n6);
	g = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6) / n7);
	h = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7) / n8);
	i = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8) / n9);
	j = (int)((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8 - i * n9) / n10);

	y = a * n1 + b * n2 + c * n3 + d * n4 + e * n5 + f * n6 + g * n7 + h * n8 + i * n9 + j * n10;
	m = (int)(round(100 * (x - y)));
	l = m % 10;
	k = (m - l) / 10;

	char s[] = "大写结果是:\n";
	strcat(result, s);

	//十亿位及亿位输出
	daxie(a, 0);
	if (a != 0) {
		strcpy(s, "拾");
		strcat(result, s);
	}
	daxie(b, 0);
	if (a != 0 || b != 0) {
		strcpy(s, "亿");
		strcat(result, s);
	}

	//万位输出
	daxie(c, b != 0 && d != 0);
	if (c != 0) {
		strcpy(s, "仟");
		strcat(result, s);
	}
	daxie(d, e != 0 && x >= 1000000);
	if (d != 0) {
		strcpy(s, "佰");
		strcat(result, s);
	}
	daxie(e, f != 0 && x >= 100000);
	if (e != 0) {
		strcpy(s, "拾");
		strcat(result, s);
	}
	daxie(f, 0);
	if (c != 0 || d != 0 || e != 0 || f != 0) {
		strcpy(s, "万");
		strcat(result, s);
	}


	//个位输出
	daxie(g, h != 0 && x >= 1000);
	if (g != 0) {
		strcpy(s, "仟");
		strcat(result, s);
	}
	daxie(h, i != 0 && x >= 100);
	if (h != 0) {
		strcpy(s, "佰");
		strcat(result, s);
	}
	daxie(i, j != 0 && x >= 10);
	if (i != 0) {
		strcpy(s, "拾");
		strcat(result, s);
	}
	daxie(j, 0);
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		strcpy(s, "圆");
		strcat(result, s);
	}


	//处理小数点后两位
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0) {
			strcpy(s, "整");
			strcat(result, s);
		}
	}
	if (k != 0) {
		daxie(k, 0);
		strcpy(s, "角");
		strcat(result, s);
	}
	if (k != 0 && l == 0) {
		strcpy(s, "整");
		strcat(result, s);
	}

	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if (x >= 1.01)
				daxie(0, 1);
		}
	}

	if (l != 0) {
		daxie(l, 0);
		strcpy(s, "分");
		strcat(result, s);
	}
	if (x == 0) {
		daxie(0, 1);
		strcpy(s, "圆整");
		strcat(result, s);
	}


	printf("%s\n", result);  

	return 0;
}