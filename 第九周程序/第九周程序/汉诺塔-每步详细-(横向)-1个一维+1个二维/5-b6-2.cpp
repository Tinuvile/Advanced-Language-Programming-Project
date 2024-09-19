/* 2352495 ����� ��16 */
#include <iostream>
#include <iomanip>
using namespace std;

int i = 0;//���ڼ���
char tower[3];
int abc[3][10] = { 0 };//��ʾ��������

//��������
void update_abc(int n, char src, char dst);
void total_hanoi(int n, char src, char dst);
void output_number(int print_out[]);
void output_line(int a[10], int b[10], int c[10]);
void hanoi(int n, char src, char tmp, char dst);

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
	 �������ƣ�total_hanoi
	 ��    �ܣ�����ÿ��ÿ��Բ������Բ�̱�ŵ����
	 ���������int n������
	 �� �� ֵ��
	 ˵    ����
   ***************************************************************************/
void total_hanoi(int n, char src, char dst)
{
	update_abc(n, src, dst);
	cout << "��" << setw(4) << i++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
	//printf("��%4d ��(%2d): %c-->%c", i++, n, src, dst);
	output_line(abc[0], abc[1], abc[2]);
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
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		total_hanoi(n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
			2�������������ʱ������ʹ��ѭ��
			3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
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
	//�������������ʼ������
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
	//��ӡ��ʼ״̬���
	cout << "��ʼ:               ";
	output_line(abc[0], abc[1], abc[2]);
	//��������
	hanoi(num_floor, begin_p, between_p, end_p);

	return 0;
}