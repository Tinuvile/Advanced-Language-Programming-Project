/* 2352495 信16 张竹和 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 函数名称：print_char
	 功    能：按字母表顺序打印字母
	 输入参数：开头字母start_ch，结尾字母end_ch
	 返 回 值：
	 说    明：程序初始choice输入为1
   ***************************************************************************/
void print_char(char start_ch, char end_ch, int choice)
{
	int s_ch = start_ch;
	int e_ch = end_ch;
	if (s_ch <= e_ch && choice == 1) {
		cout << char(s_ch);
		print_char(char(s_ch + 1), end_ch, choice);
	}
	else {
		if (s_ch >= 67) {
			cout << char(s_ch - 2);
			print_char(char(s_ch - 1), end_ch, choice - 1);
		}
		else {
			return;
		}
	}
}


  /***************************************************************************
    函数名称：print_line
    功    能：打印字母塔的整行
    输入参数：最大字母end_ch，初始字母start_ch，当前行数
    返 回 值：
    说    明：
  ***************************************************************************/
void print_line(char start_ch, char end_ch, int line) {
	int Max_line = int(end_ch) - int(start_ch) + 1;
	if (line <= Max_line) {
		if ((Max_line - line) != 0) {
			cout << setw(Max_line - line) << ' ';
			print_char(start_ch, char(65 + line - 1), 1);
			cout << setw(Max_line - line) << ' ' << endl;
		}
		if (Max_line == line) {
			print_char(start_ch, char(65 + line - 1), 1);
			cout << endl;
		}
		else
			return;
	}
	else
		return;
}

   /***************************************************************************
	 函数名称：print_tower
	 功    能：打印字母塔
	 输入参数：结束字母end_ch，顺序选项order
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序1/倒序0
   ***************************************************************************/
void print_tower(char end_ch, int order, int line) {
	int Max_line = int(end_ch) - 65 + 1;
	if (order == 1) {
		if (line <= Max_line) {
			print_line('A', end_ch, line);
			print_tower(end_ch, order, line + 1);
		}
		else
			return;
	}
	if (order == 0) {
		if (line >= 1 && line <= Max_line) {
			print_line('A', end_ch, line);
			print_tower(end_ch, order, line - 1);
		}
		else
			return;
	}
	else
		return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(两边为A) */
	cout <<  setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ')<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 1, 1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 0, int(end_ch) - 65 + 1); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（外侧为A） */
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch, 1, 1);   //打印 A~结束字符的正三角 
	print_tower(end_ch, 0, int(end_ch) - 65);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}