/* 2352495 ��16 ����� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

//�˵���ʾ��ѡ����
//�˴����ص������ֵ�ASCII��ֵ,1��Ӧ49
//1,2��ͷ��ĸ������3,4ֻ�����ͷ��5,6ֻ������ĸ
int menu()
{
	int choice;
	cout << "1.��I��J��K��L��������������(�������ͷʱ�����ƶ�)���߽�ֹͣ" << endl;
	cout << "2.��I��J��K��L��������������(�������ͷʱ�����ƶ�)���߽����" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(���������ͷʱ�����ƶ�)���߽�ֹͣ" << endl;
	cout << "6.��I��J��K��L��������������(���������ͷʱ�����ƶ�)���߽����" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";
	choice = _getch();
	return choice;
}

//����ƶ�����
//a�����ж��Ƿ���ƣ�b�жϼ�ͷ���ƻ�����ĸ����
void move_by(const HANDLE hout, int a, int b)
{
	int x = 35;
	int y = 9;
	while (true) {
		//���λ�ø���
		gotoxy(hout, x, y);
		//cout << x << y << endl;

		//������
		int input = 0;
		int input1 = _getch();
		if (input1 == 0 || input1 == 224) {
			input = _getch();
		}
		//�ո�
		else if (input1 == 32)
			cout << " ";
		//�˳�����ƶ�
		else if (input1 == 113 || input1 == 81) {
			cls(hout);
			break;
		}
		else
			input = input1;

		//cout << input << input1 << endl;

		//�߽�ֹͣ
		if ((a == 49) || (a == 51) || (a == 53)) {
			//ijkl������(��Сд����)
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
			//��ͷ����
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
			//ijkl+��ͷ����
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
		//�߽����
		else if (a == 50 || a == 52 || a == 54) {
			//ijkl������(��Сд����)
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
			//��ͷ����
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
			//ijkl+��ͷ����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	while (true) {

		//���벿��
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
			/* �˾�������ǵ���ϵͳ��cls�������� */
			cls(hout);

			/* ��ʾ��ʼ�ı߿����е�����ַ� */
			init_border(hout);

			//�ƶ����
			//���ù���ƶ�����

			move_by(hout, a, b);
		}
		else
			cls(hout);
			continue;

		//��ͣ
		//getchar();

		gotoxy(hout, 0, 23);
		cout << "��Ϸ���������س����˳�." << endl;

		//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
		while (_getch() != 13)
		{
			// ��ѭ���壬�ȴ��û����»س���
		}

		cls(hout);
	}

	return 0;
}

/*ԭ����ͣ�
* �ڱ������в���int�Ͷ�ȡ��������ʵ���϶�ȡ����ASCII�룬�����ܼ�ʵ�ʻ������ASCII���ڻ�������
* ���ͷ������ASCII��ֱ���224��75������дK��ASCII����75����������������ְ����ͷ���µ������
* �������ַ����ɣ�������ɵ������ظ������ܵ������ɵ��ַ�����20����
*/