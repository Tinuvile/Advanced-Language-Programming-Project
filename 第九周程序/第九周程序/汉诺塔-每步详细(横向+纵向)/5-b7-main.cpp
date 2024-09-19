/* 2352495 ����� ��16 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
using namespace std;

int i = 1;//���ڼ���
static int speed;//����ѡ���ƶ���ʱ
static int choose_abc;//����ѡ���Ƿ���ʾ�ڲ�����
char src, tmp, dst;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };//�����ʾ�������������������

//��������
void update_abc(int n, char src, char dst);
void total_hanoi(int n, char src, char dst);
void output_number(int print_out[]);
void output_line(int a[10], int b[10], int c[10]);
void hanoi(int n, char src, char tmp, char dst);
void time_delay();

/***************************************************************************
	 �������ƣ�time_delay
	 ��    �ܣ�������ʱ����ѡ�������ʱʱ��
	 ���������
	 �� �� ֵ��
	 ˵    ��������ֵ��Χ0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���
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
	 �������ƣ�vertical_output
	 ��    �ܣ���������̺�
	 ���������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void vertical_output(int output1[], int output2[], int output3[])
{
	int x, y;
	//���ԭ���Ĵ�ӡ
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
	//�ȴ�ӡA��
	x = 19;
	y = 11;
	for (int t = 9; t >= 0; t--) {
		if (output1[t] != 0) {
			cct_gotoxy(y, x);
			cout << output1[t] << " ";
			x--;
		}
	}
	//�ٴ�ӡB��
	x = 19;
	y = 21;
	for (int t = 9; t >= 0; t--) {
		if (output2[t] != 0) {
			cct_gotoxy(y, x);
			cout << output2[t] << " ";
			x--;
		}
	}
	//��ӡC��
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
	 �������ƣ�update_abc
	 ��    �ܣ����ݵݹ����������������a,b,c
	 ���������int n���̺�
			   char src����ʼ��
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����
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
	 �������ƣ�total_hanoi
	 ��    �ܣ�����ÿ��ÿ��Բ������Բ�̱�ŵ����
	 ���������int n������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void total_hanoi(int n, char src, char dst)
{
	update_abc(n, src, dst);
	cct_gotoxy(20, 25);
	cout << "��" << setw(4) << i++ << " ��(" << setw(2) << n << ": " << src << "-->" << dst << ") ";
	if (choose_abc==1)
		output_line(a, b, c);
	if (speed == 0)
		cin.ignore(63353, '\n');
	vertical_output(a, b, c);
	//vertical_output(a, b, c);
	//vertical_output(a, b, c);
}

/***************************************************************************
	 �������ƣ�output_number
	 ��    �ܣ�����ÿ��ÿ��Բ������Բ�̱�ŵ����
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void output_number(int print_out[])
{
	int m = 0;//������λ�����λ����ӡ������
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
	 �������ƣ�output_line
	 ��    �ܣ�����ÿ����ĸ��������
	 ���������a[],b[],c[]
	 �� �� ֵ��
	 ˵    ����
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
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2������������������κ���ʽ��ѭ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int num_floor;
	char begin_p, between_p, end_p;
	//���봦��
	while (true) {
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
		cin >> num_floor;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
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
		cout << "��������ʼ��(A-C)" << endl;
		cin >> begin_p;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
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
		cout << "������Ŀ����(A-C)" << endl;
		cin >> end_p;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
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
				cout << "Ŀ����(" << end_p << ")��������ʼ��(" << begin_p << ")��ͬ" << endl;
				cin.ignore(1024, '\n');
				continue;
			}
	}
	while (true) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> speed;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
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
		cout << "�������Ƿ���ʾ�ڲ�����(0-����ʾ 1-��ʾ)" << endl;
		cin >> choose_abc;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
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
	//�������������ʼ������
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
	//ѡ���м�ѡ��
	if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'B' || end_p == 'b')) || ((begin_p == 'B' || begin_p == 'b') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'C';
	}
	else if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'C' || end_p == 'c')) || ((begin_p == 'C' || begin_p == 'c') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'B';
	}
	else {
		between_p = 'A';
	}
	//������
	cct_cls();
	//��ӡ��ʼ���
	cout << "�� " << begin_p << " �ƶ��� " << end_p << "���� " << num_floor << " �㣬��ʱ����Ϊ " << speed << "��";
	if (choose_abc == 0)
		cout << "����ʾ�ڲ�����ֵ";
	else if (choose_abc == 1)
		cout << "��ʾ�ڲ�����ֵ";
	//��ӡ��������
	cct_gotoxy(9, 20);
	cout << "=========================" << endl;
	cct_gotoxy(11, 21);
	cout << "A";
	cct_gotoxy(21, 21);
	cout << "B";
	cct_gotoxy(31, 21);
	cout << "C";
	//���ú�ŵ������
	hanoi(num_floor, begin_p, between_p, end_p);

	cct_gotoxy(20, 30);

	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}