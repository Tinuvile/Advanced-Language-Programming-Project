/* 2352495 张竹和 信16 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
using namespace std;

int i = 1;//用于计数
static int speed;//用于选择移动延时
static int choose_abc;//用于选择是否显示内部数组
char src, tmp, dst;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//数组表示三个柱子里的盘子数字

//函数声明
void update_abc(int n, char src, char dst);
void total_hanoi(int n, char src, char dst);
void output_number(int print_out[]);
void output_line(int a[10], int b[10], int c[10]);
void hanoi(int n, char src, char tmp, char dst);
void time_delay();

/***************************************************************************
	 函数名称：time_delay
	 功    能：根据延时输入选项控制延时时间
	 输入参数：
	 返 回 值：
	 说    明：输入值范围0-5: 0-按回车单步演示 1-延时最长 5-延时最短
   ***************************************************************************/
void time_delay()
{
	if (speed == 0)
		cin.ignore(63353, '\n');
	else if (speed == 1)
		Sleep(2000);
	else if (speed == 2)
		Sleep(1500);
	else if (speed == 3)
		Sleep(1000);
	else if (speed == 4)
		Sleep(500);
	else if (speed == 5)
		Sleep(100);
}

/***************************************************************************
	 函数名称：vertical_output
	 功    能：输出竖排盘号
	 输入参数：
	 返 回 值：
	 说    明：
   ***************************************************************************/
void vertical_output(int output1[], int output2[], int output3[])
{
	int x, y;
	//清除原来的打印
	x = 19;
	y = 11;
	for (int t = 9; t >= 0; t--) {
		cct_gotoxy(y, x);
		cout << " ";
		x--;
	}
	x = 19;
	y = 21;
	for (int t = 9; t >= 0; t--) {
		cct_gotoxy(y, x);
		cout << " ";
		x--;
	}
	x = 19;
	y = 31;
	for (int t = 9; t >= 0; t--) {
		cct_gotoxy(y, x);
		cout << " ";
		x--;
	}
	//先打印A柱
	x = 19;
	y = 11;
	for (int t = 9; t >= 0; t--) {
		if (output1[t] != 0) {
			cct_gotoxy(y, x);
			cout << output1[t] << " ";
			x--;
		}
	}
	//再打印B柱
	x = 19;
	y = 21;
	for (int t = 9; t >= 0; t--) {
		if (output2[t] != 0) {
			cct_gotoxy(y, x);
			cout << output2[t] << " ";
			x--;
		}
	}
	//打印C柱
	x = 19;
	y = 31;
	for (int t = 9; t >= 0; t--) {
		if (output3[t] != 0) {
			cct_gotoxy(y, x);
			cout << output3[t] << " ";
			x--;
		}
	}
}

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
			b[n - 1] = n;
		if (dst == 'C' || dst == 'c')
			c[n - 1] = n;
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
	cct_gotoxy(20, 25);
	cout << "第" << setw(4) << i++ << " 步(" << setw(2) << n << ": " << src << "-->" << dst << ") ";
	if (choose_abc==1)
		output_line(a, b, c);
	if (speed == 0)
		cin.ignore(63353, '\n');
	vertical_output(a, b, c);
	//vertical_output(a, b, c);
	//vertical_output(a, b, c);
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
				cout << print_out[t] << " ";
			if (print_out[t] == 10) {
				cout << print_out[t] << " ";
				m = 1;
			}
		}
	}
	for (int t = 0; t < 10; t++) {
		if (print_out[t] == 0)
			cout << "  ";
	}
	if (m == 0)
		cout << " ";
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
	cout << " A:";
	output_number(a);
	cout << "B:";
	output_number(b);
	cout << "C:";
	output_number(c);
	cout << endl;
}

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
		total_hanoi(n, src, dst);
		time_delay();
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		total_hanoi(n, src, dst);
		time_delay();
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int num_floor;
	char begin_p, between_p, end_p;
	//输入处理
	while (true) {
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> num_floor;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (num_floor < 1 || num_floor>16) {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (num_floor >= 1 && num_floor <= 16) {
			cin.ignore(1024, '\n');
			break;
		}
	}
	while (true) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> begin_p;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (begin_p != 'A' && begin_p != 'B' && begin_p != 'C' && begin_p != 'a' && begin_p != 'b' && begin_p != 'c') {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (begin_p == 'A' || begin_p == 'B' || begin_p == 'C') {
			cin.ignore(1024, '\n');
			break;
		}
		else if (begin_p == 'a' || begin_p == 'b' || begin_p == 'c') {
			begin_p = begin_p - 32;
			cin.ignore(1024, '\n');
			break;
		}
	}
	while (true) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> end_p;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (end_p != 'A' && end_p != 'B' && end_p != 'C' && end_p != 'a' && end_p != 'b' && end_p != 'c') {
			cin.ignore(1024, '\n');
			continue;
		}
		else
			if ((int(end_p) - int(begin_p) != 32) && (int(end_p) - int(begin_p) != -32) && (end_p != begin_p)) {
				if (end_p == 'a' || end_p == 'b' || end_p == 'c') {
					end_p = end_p - 32;
				}
				cin.ignore(1024, '\n');
				break;
			}
			else {
				cout << "目标柱(" << end_p << ")不能与起始柱(" << begin_p << ")相同" << endl;
				cin.ignore(1024, '\n');
				continue;
			}
	}
	while (true) {
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> speed;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (speed < 0 || speed>5) {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (speed >= 0 && speed <= 5) {
			cin.ignore(1024, '\n');
			break;
		}
	}
	while (true) {
		cout << "请输入是否显示内部数组(0-不显示 1-显示)" << endl;
		cin >> choose_abc;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (choose_abc != 0 && choose_abc != 1) {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (choose_abc == 0 || choose_abc == 1) {
			cin.ignore(1024, '\n');
			break;
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
	//先清屏
	cct_cls();
	//打印初始情况
	cout << "从 " << begin_p << " 移动到 " << end_p << "，共 " << num_floor << " 层，延时设置为 " << speed << "，";
	if (choose_abc == 0)
		cout << "不显示内部数组值";
	else if (choose_abc == 1)
		cout << "显示内部数组值";
	//打印柱子坐标
	cct_gotoxy(9, 20);
	cout << "=========================" << endl;
	cct_gotoxy(11, 21);
	cout << "A";
	cct_gotoxy(21, 21);
	cout << "B";
	cct_gotoxy(31, 21);
	cout << "C";
	//调用汉诺塔函数
	hanoi(num_floor, begin_p, between_p, end_p);

	cct_gotoxy(20, 30);

	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}