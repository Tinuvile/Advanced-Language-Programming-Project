/* 2352495 张竹和 信16 */
#include <iostream>
#include <iomanip>
using namespace std;

int i = 0;//用于计数
char tower[3];
int abc[3][10] = { 0 };//表示盘子数字

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
		abc[0][n - 1] = 0;
		if (dst == 'B' || dst == 'b')
			abc[1][n - 1] = n;
		if (dst == 'C' || dst == 'c')
			abc[2][n - 1] = n;
	}
	else if (src == 'B' || src == 'b') {
		abc[1][n - 1] = 0;
		if (dst == 'A' || dst == 'a')
			abc[0][n - 1] = n;
		if (dst == 'C' || dst == 'c')
			abc[2][n - 1] = n;
	}
	else if (src == 'C' || src == 'c') {
		abc[2][n - 1] = 0;
		if (dst == 'A' || dst == 'a')
			abc[0][n - 1] = n;
		if (dst == 'B' || dst == 'b')
			abc[1][n - 1] = n;
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
	cout << "第" << setw(4) << i++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
	//printf("第%4d 步(%2d): %c-->%c", i++, n, src, dst);
	output_line(abc[0], abc[1], abc[2]);
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
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		total_hanoi(n, src, dst);
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
	//根据输入情况初始化数组
	for (int n = 0; n < num_floor; n++) {
		if (begin_p == 'A' || begin_p == 'a') {
			abc[0][n] = n + 1;
			abc[1][n] = 0;
			abc[2][n] = 0;
		}
		if (begin_p == 'B' || begin_p == 'b') {
			abc[0][n] = 0;
			abc[1][n] = n + 1;
			abc[2][n] = 0;
		}
		if (begin_p == 'C' || begin_p == 'c') {
			abc[0][n] = 0;
			abc[1][n] = 0;
			abc[2][n] = n + 1;
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
	cout << "初始:               ";
	output_line(abc[0], abc[1], abc[2]);
	//函数调用
	hanoi(num_floor, begin_p, between_p, end_p);

	return 0;
}