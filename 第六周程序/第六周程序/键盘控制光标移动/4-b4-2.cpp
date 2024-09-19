/* 2352495 信16 张竹和 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

//菜单显示及选择函数
//此处返回的是数字的ASCII码值,1对应49
//1,2箭头字母均允许；3,4只允许箭头；5,6只允许字母
int menu()
{
	int choice;
	cout << "1.用I、J、K、L键控制上下左右(允许按左箭头时向下移动)，边界停止" << endl;
	cout << "2.用I、J、K、L键控制上下左右(允许按左箭头时向下移动)，边界回绕" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(不允许按左箭头时向下移动)，边界停止" << endl;
	cout << "6.用I、J、K、L键控制上下左右(不允许按左箭头时向下移动)，边界回绕" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	choice = _getch();
	return choice;
}

//光标移动函数
//a用于判断是否回绕，b判断箭头控制或是字母控制
void move_by(const HANDLE hout, int a, int b)
{
	int x = 35;
	int y = 9;
	while (true) {
		//光标位置更新
		gotoxy(hout, x, y);
		//cout << x << y << endl;

		//读键盘
		int input = 0;
		int input1 = _getch();
		if (input1 == 0 || input1 == 224) {
			input = _getch();
		}
		//空格
		else if (input1 == 32)
			cout << " ";
		//退出光标移动
		else if (input1 == 113 || input1 == 81) {
			cls(hout);
			break;
		}
		else
			input = input1;

		//cout << input << input1 << endl;

		//边界停止
		if ((a == 49) || (a == 51) || (a == 53)) {
			//ijkl键控制(大小写均可)
			if (b == 3) {
				if (input == input1) {
					switch (input) {
						case 73:
						case 105:
							if (y > 1) {
								y = y - 1;
							}
							break;
						case 74:
						case 106:
							if (x > 1)
								x = x - 1;
							break;
						case 75:
						case 107:
							if (y < MAX_Y)
								y = y + 1;
							break;
						case 76:
						case 108:
							if (x < MAX_X)
								x = x + 1;
							break;
					}
				}
			}
			//箭头控制
			else if (b == 2) {
				if (input1 != input) {
					switch (input) {
						case 72:
							if (y > 1)
								y=y-1;
							break;
						case 75:
							if (x > 1)
								x=x-1;
							break;
						case 80:
							if (y < MAX_Y)
								y=y+1;
							break;
						case 77:
							if (x < MAX_X)
								x=x+1;
							break;
					}
				}
			}
			//ijkl+箭头均可
			else if (b == 1) {
				if (input == input1) {
					switch (input) {
						case 73:
						case 105:
							if (y > 1) {
								y = y - 1;
							}
							break;
						case 74:
						case 106:
							if (x > 1)
								x = x - 1;
							break;
						case 75:
						case 107:
							if (y < MAX_Y)
								y = y + 1;
							break;
						case 76:
						case 108:
							if (x < MAX_X)
								x = x + 1;
							break;
					}
				}
				if (input1 != input) {
					switch (input) {
						case 75:
							if (y < MAX_Y)
								y = y + 1;
							break;
					}
				}
			}
		}
		//边界回绕
		else if (a == 50 || a == 52 || a == 54) {
			//ijkl键控制(大小写均可)
			if (b == 3) {
				if (input == input1) {
					switch (input) {
						case 73:
						case 105:
							if (y > 1)
								y = y - 1;
							else if (y == 1)
								y = 17;
							break;
						case 74:
						case 106:
							if (x > 1)
								x = x - 1;
							else if (x == 1)
								x = 69;
							break;
						case 75:
						case 107:
							if (y < MAX_Y)
								y = y + 1;
							else if (y == 17)
								y = 1;
							break;
						case 76:
						case 108:
							if (x < MAX_X)
								x = x + 1;
							else if (x == 69)
								x = 1;
							break;
					}
				}
			}
			//箭头控制
			else if (b == 2) {
				if (input1 != input) {
					switch (input) {
						case 72:
							if (y > 1)
								y = y - 1;
							else if (y == 1)
								y = 17;
							break;
						case 75:
							if (x > 1)
								x = x - 1;
							else if (x == 1)
								x = 69;
							break;
						case 80:
							if (y < MAX_Y)
								y = y + 1;
							else if (y == 17)
								y = 1;
							break;
						case 77:
							if (x < MAX_X)
								x = x + 1;
							else if (x == 69)
								x = 1;
							break;
					}
				}
			}
			//ijkl+箭头均可
			else if (b == 1) {
				if (input == input1) {
					switch (input) {
						case 73:
						case 105:
							if (y > 1)
								y = y - 1;
							else if (y == 1)
								y = 17;
							break;
						case 74:
						case 106:
							if (x > 1)
								x = x - 1;
							else if (x == 1)
								x = 69;
							break;
						case 75:
						case 107:
							if (y < MAX_Y)
								y = y + 1;
							else if (y == 17)
								y = 1;
							break;
						case 76:
						case 108:
							if (x < MAX_X)
								x = x + 1;
							else if (x == 69)
								x = 1;
							break;
					}
				}
				if (input1 != input) {
					switch (input) {
						case 75:
							if (y < MAX_Y)
								y = y + 1;
							break;
					}
				}
			}
		}
		

	}
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (true) {

		//输入部分
		int a = menu();
		int b = 0;
		if (a == 49 || a == 50) {
			b = 1;
		}
		else if (a == 51 || a == 52) {
		    b = 2;
		}
		else if (a == 53 || a == 54) {
			b = 3;
		}
		else if (a == 48) {
			break;
		}

		if (a == 49 || a == 50 || a == 51 || a == 52 || a == 53 || a == 54) {
			/* 此句的作用是调用系统的cls命令清屏 */
			cls(hout);

			/* 显示初始的边框及其中的随机字符 */
			init_border(hout);

			//移动光标
			//调用光标移动函数

			move_by(hout, a, b);
		}
		else
			cls(hout);
			continue;

		//暂停
		//getchar();

		gotoxy(hout, 0, 23);
		cout << "游戏结束，按回车键退出." << endl;

		//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
		while (_getch() != 13)
		{
			// 空循环体，等待用户按下回车键
		}

		cls(hout);
	}

	return 0;
}

/*原因解释：
* 在本程序中采用int型读取键盘输入实际上读取的是ASCII码，而功能键实际会放两个ASCII码在缓冲区，
* 左箭头的两个ASCII码分别是224，75；而大写K的ASCII码是75，故如果不处理会出现按左箭头向下的情况。
* 而对于字符生成，如果生成的坐标重复，可能导致生成的字符不到20个。
*/