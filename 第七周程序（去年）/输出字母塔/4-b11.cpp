/* 2352495 ��16 ����� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */


   /***************************************************************************
	 �������ƣ�print_char
	 ��    �ܣ�����ĸ��˳���ӡ��ĸ
	 �����������ͷ��ĸstart_ch����β��ĸend_ch
	 �� �� ֵ��
	 ˵    ���������ʼchoice����Ϊ1
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
    �������ƣ�print_line
    ��    �ܣ���ӡ��ĸ��������
    ��������������ĸend_ch����ʼ��ĸstart_ch����ǰ����
    �� �� ֵ��
    ˵    ����
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
	 �������ƣ�print_tower
	 ��    �ܣ���ӡ��ĸ��
	 ���������������ĸend_ch��˳��ѡ��order
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������1/����0
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout <<  setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ')<< endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 1, 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 0, int(end_ch) - 65 + 1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setw((int(end_ch) - 65) * 2 + 1) << setfill('=') << '=' << setfill(' ') << endl;/* ����ĸ����������= */
	print_tower(end_ch, 1, 1);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch, 0, int(end_ch) - 65);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}