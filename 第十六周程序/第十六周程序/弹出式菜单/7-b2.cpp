/* 2352495 信16 张竹和*/
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"

/* 1、按需加入头文件
   2、不允许定义全部变量，包括静态全局，但不显示const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */


   /* 四种线型的框架，每种11个元素，每个元素均为一个中文字符（2字节）
           双线框架："╔", "╚", "╗", "╝", "═", "║", "╦", "╩", "╠", "╣", "╬"
           单线框架："┏", "┗", "┓", "┛", "━", "┃", "┳", "┻", "┣", "┫", "╋"
           横双竖单: "╒", "╘", "╕", "╛", "═", "│", "╤", "╧", "╞", "╡", "╪"
           横单竖双："╓", "╙", "╖", "╜", "─", "║", "╥", "╨", "╟", "╢", "╫"
   */


/***************************************************************************
  函数名称：tj_strlen
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void draw(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    const char* title = original_para->title;
    int x = original_para->start_x;
    int y = original_para->start_y;
    int width = original_para->width;
    int high = original_para->high;
    int bg_color = original_para->bg_color;
    int fg_color = original_para->fg_color;

    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);


    //初始菜单的绘制
    int l = strlen(title);
    if (width < l)
        width = l;
    if (width % 2 == 1)
        width = width + 1;

    int judge1 = 0;
    if (l % 2 == 1) {
        judge1 = 1;
        l = l + 1;
    }
    cct_gotoxy(x, y);
    cct_setcolor(bg_color, fg_color);
    cout << "╔";
    int half = (width - l) / 4;
    for (int i = 1; i <= half; i++) {
        cout << "═";
    }
    cout << title;
    if (judge1 == 1)
        cout << " ";
    for (int i = 1; i <= (width - l) / 2 - half; i++) {
        cout << "═";
    }
    cout << "╗";
    int judge2 = 0;
    int j = 1;
    for (j; j <= high; j++) {
        int judge3 = 0;
        if (menu[j - 1][0] == '\0') {
            break;
        }
        else {
            cct_gotoxy(x, y + j);
            cout << "║";
            for (int i = 0; i < width; i++) {
                if (j == 1)
                    cct_setcolor(fg_color, bg_color);
                else
                    cct_setcolor(bg_color, fg_color);
                if (menu[j - 1][i] == '\0') {
                    if (judge3 == 0)
                        cout << setw(width - i) << " ";
                    else if (judge3 == 1)
                        cout << setw(width - i - 1) << " ";
                    break;
                }
                if ((unsigned int(menu[j - 1][i]) >= 0xA1) && unsigned int((menu[j - 1][i]) <= 0xFE)) {
                    if (i == width - 1) {
                        cout << " ";
                        break;
                    }
                    else if (((x + i + 3) == cols) && (x + i + 3) == buffer_cols) {
                        judge3 = 1;
                        cout << " " << menu[j - 1][i] << menu[j - 1][i + 1];
                        i = i + 1;
                    }
                    else {
                        cout << menu[j - 1][i] << menu[j - 1][i + 1];
                        i = i + 1;
                    }
                }
                else {
                    cout << menu[j - 1][i];
                }
            }
        }
        cct_setcolor(bg_color, fg_color);
        cout << "║";
    }
    cct_gotoxy(x, y + j);
    cout << "╚";
    for (int i = 1; i <= width / 2; i++) {
        cout << "═";
    }
    cout << "╝";
}


/***************************************************************************
  函数名称：tj_strlen
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static int tj_strlen(const char* str)
{
    if (str == NULL) {
        return 0;
    }
    const char* str_s = str;
    for (; *str != '\0'; str++) {
        if (*str == '\0')
            break;
        else
            continue;
    }
    return (str - str_s);
}


/***************************************************************************
  函数名称：tj_strlen
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
static void draw_tj(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para,int bound,int position)
{
    const char* title = original_para->title;
    int x = original_para->start_x;
    int y = original_para->start_y;
    int width = original_para->width;
    int high = original_para->high;
    int bg_color = original_para->bg_color;
    int fg_color = original_para->fg_color;

    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);

    int l = strlen(title);
    if (width < l)
        width = l;
    if (width % 2 == 1)
        width = width + 1;

    int j = 1;
    for (j; j <= high; j++, bound++) {
        int judge3 = 0;
        if (menu[bound - 1][0] == '\0') {
            break;
        }
        else {
            cct_gotoxy(x, y + j);
            cout << "║";
            for (int i = 0; i < width; i++) {
                if (j == position)
                    cct_setcolor(fg_color, bg_color);
                else
                    cct_setcolor(bg_color, fg_color);
                if (menu[bound - 1][i] == '\0') {
                    if (judge3 == 0)
                        cout << setw(width - i) << " ";
                    else if (judge3 == 1)
                        cout << setw(width - i - 1) << " ";
                    break;
                }
                if ((unsigned int(menu[bound - 1][i]) >= 0xA1) && unsigned int((menu[bound - 1][i]) <= 0xFE)) {
                    if (i == width - 1) {
                        cout << " ";
                        break;
                    }
                    else if (((x + i + 3) == cols) && (x + i + 3) == buffer_cols) {
                        judge3 = 1;
                        cout << " " << menu[bound - 1][i] << menu[bound - 1][i + 1];
                        i = i + 1;
                    }
                    else {
                        cout << menu[bound - 1][i] << menu[bound - 1][i + 1];
                        i = i + 1;
                    }
                }
                else {
                    cout << menu[bound - 1][i];
                }
            }
        }
        cct_setcolor(bg_color, fg_color);
        cout << "║";
    }
}


/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：const char* title;	    //标题
	        const int* start_x;	    //左上角x坐标
	        const int* start_y;	    //左上角y坐标
	        const int* width;		//菜单宽度，不含左右边框（+4是显示的实际列数），必须是偶数
	        const int* high;		//菜单高度，不含上下边框（+2是显示的实际行数），
	        const int* bg_color;	//所用背景色（注：选中项background/foreground为反显）
	        const int* fg_color;	//所用前景色
            const char menu[][];    //菜单内容
  返 回 值：
  说    明：1：在窗口中完整显示，宽度足够容纳最长的菜单项，高度足够容纳所有的菜单项
            2：在窗口中完整显示，宽度足够容纳最长的菜单项，但高度不足容纳所有的菜单项。菜单项需要上下滚屏
            3：在窗口中完整显示，宽度不足以容纳最长的菜单项，高度足够容纳所有的菜单项。超过宽度的菜单项需要截断，
            截断时需要考虑半个汉字问题，即如果最后只剩下一个字符位置，但需要打印一个汉字时，跳过该汉字，用空格填充。
            4：在窗口中完整显示，宽度不足以容纳title的长度，高度足够容纳所有的菜单项。最小宽度为完整显示title所需的宽度，
            超过宽度的菜单项需要截断，截断时需要考虑半个汉字问题，即如果最后只剩下一个字符位置，但需要打印一个汉字时，
            跳过该汉字，用空格填充。
            5：在窗口中完整显示，宽度不足以容纳最长的菜单项，高度不足以容纳所有的菜单项。超过宽度的菜单项需要截断，
            菜单项需要上下滚屏，截断时需要考虑半个汉字问题，即如果最后只剩下一个字符位置，但需要打印一个汉字时，跳过该汉字，
            用空格填充。
            6：菜单的显示宽度超过了窗口宽度，需要折返到下一行的起始位置（包括title）。菜单项需要上下滚屏且显示不乱，为了减负，
            本测试项不测试宽度不够的情况。
            7：菜单的显示宽度超过了窗口宽度，但是未超过缓冲区的宽度。不需要折返打印，但是后面的内容需要移动cmd窗口下方的水平
            滚动杆才能看到。超过宽度的菜单项需要截断，菜单项需要上下滚屏，截断时需要考虑半个汉字问题，即如果最后只剩下一个字符位置，
            但需要打印一个汉字时，跳过该汉字，用空格填充。

***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    const char* title = original_para->title;
    int x = original_para->start_x;
    int y = original_para->start_y;
    int width = original_para->width;
    int high = original_para->high;
    int bg_color = original_para->bg_color;
    int fg_color = original_para->fg_color;

    draw(menu, original_para);

    //选项移动的操作
    int t = 1;
    int upper_bound = 1;
    int lower_bound = high;
    int line_num = 0;//统计总行数
    for (int j = 0;; j++, line_num++) {
        if (menu[j][0] == '\0')
            break;
    }
    while (true) {
        cct_gotoxy(x, y + t);
        cct_setcursor(CURSOR_INVISIBLE);
        int input = 0;
        int input1 = _getch();
        if (input1 == '\r') {
            break;
        }
        if (input1 == 0 || input1 == 224) {
            input = _getch();
        }
        else
            input = input1;
        if (input1 != input) {
            switch (input) {
                case 72:
                    if (t > 1) {
                        if (t == upper_bound) {
                            upper_bound -= 1;
                            lower_bound -= 1;
                        }
                        t = t - 1;
                    }
                    break;
                case 80:
                    if (t < line_num) {
                        if (t == lower_bound) {
                            upper_bound += 1;
                            lower_bound += 1;
                        }
                        t = t + 1;
                    }
                    break;
            }
            cct_gotoxy(x, y + 1);
            draw_tj(menu, original_para, upper_bound, t - upper_bound + 1);
        }
    }


    return t; //按需返回
}