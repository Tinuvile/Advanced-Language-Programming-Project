/* 2352495 ��16 �����*/
#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"

/* 1���������ͷ�ļ�
   2����������ȫ��������������̬ȫ�֣�������ʾconst��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */


   /* �������͵Ŀ�ܣ�ÿ��11��Ԫ�أ�ÿ��Ԫ�ؾ�Ϊһ�������ַ���2�ֽڣ�
           ˫�߿�ܣ�"�X", "�^", "�[", "�a", "�T", "�U", "�j", "�m", "�d", "�g", "�p"
           ���߿�ܣ�"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��"
           ��˫����: "�V", "�\", "�Y", "�_", "�T", "��", "�h", "�k", "�b", "�e", "�n"
           �ᵥ��˫��"�W", "�]", "�Z", "�`", "��", "�U", "�i", "�l", "�c", "�f", "�o"
   */


/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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


    //��ʼ�˵��Ļ���
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
    cout << "�X";
    int half = (width - l) / 4;
    for (int i = 1; i <= half; i++) {
        cout << "�T";
    }
    cout << title;
    if (judge1 == 1)
        cout << " ";
    for (int i = 1; i <= (width - l) / 2 - half; i++) {
        cout << "�T";
    }
    cout << "�[";
    int judge2 = 0;
    int j = 1;
    for (j; j <= high; j++) {
        int judge3 = 0;
        if (menu[j - 1][0] == '\0') {
            break;
        }
        else {
            cct_gotoxy(x, y + j);
            cout << "�U";
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
        cout << "�U";
    }
    cct_gotoxy(x, y + j);
    cout << "�^";
    for (int i = 1; i <= width / 2; i++) {
        cout << "�T";
    }
    cout << "�a";
}


/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�tj_strlen
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
            cout << "�U";
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
        cout << "�U";
    }
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������const char* title;	    //����
	        const int* start_x;	    //���Ͻ�x����
	        const int* start_y;	    //���Ͻ�y����
	        const int* width;		//�˵���ȣ��������ұ߿�+4����ʾ��ʵ����������������ż��
	        const int* high;		//�˵��߶ȣ��������±߿�+2����ʾ��ʵ����������
	        const int* bg_color;	//���ñ���ɫ��ע��ѡ����background/foregroundΪ���ԣ�
	        const int* fg_color;	//����ǰ��ɫ
            const char menu[][];    //�˵�����
  �� �� ֵ��
  ˵    ����1���ڴ�����������ʾ������㹻������Ĳ˵���߶��㹻�������еĲ˵���
            2���ڴ�����������ʾ������㹻������Ĳ˵�����߶Ȳ����������еĲ˵���˵�����Ҫ���¹���
            3���ڴ�����������ʾ����Ȳ�����������Ĳ˵���߶��㹻�������еĲ˵��������ȵĲ˵�����Ҫ�ضϣ�
            �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո���䡣
            4���ڴ�����������ʾ����Ȳ���������title�ĳ��ȣ��߶��㹻�������еĲ˵����С���Ϊ������ʾtitle����Ŀ�ȣ�
            ������ȵĲ˵�����Ҫ�ضϣ��ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ��
            �����ú��֣��ÿո���䡣
            5���ڴ�����������ʾ����Ȳ�����������Ĳ˵���߶Ȳ������������еĲ˵��������ȵĲ˵�����Ҫ�ضϣ�
            �˵�����Ҫ���¹������ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣�
            �ÿո���䡣
            6���˵�����ʾ��ȳ����˴��ڿ�ȣ���Ҫ�۷�����һ�е���ʼλ�ã�����title�����˵�����Ҫ���¹�������ʾ���ң�Ϊ�˼�����
            ����������Կ�Ȳ����������
            7���˵�����ʾ��ȳ����˴��ڿ�ȣ�����δ�����������Ŀ�ȡ�����Ҫ�۷���ӡ�����Ǻ����������Ҫ�ƶ�cmd�����·���ˮƽ
            �����˲��ܿ�����������ȵĲ˵�����Ҫ�ضϣ��˵�����Ҫ���¹������ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�
            ����Ҫ��ӡһ������ʱ�������ú��֣��ÿո���䡣

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

    //ѡ���ƶ��Ĳ���
    int t = 1;
    int upper_bound = 1;
    int lower_bound = high;
    int line_num = 0;//ͳ��������
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


    return t; //���践��
}