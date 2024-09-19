/* 2352495 ��16 ����� */
#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�input
  ��    �ܣ����봦��(����)
  ����������е��������飬����
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
void input(int input_sudoku[][10], int n)
{
	int input_try = 0;
	int judge = 0;
	while (true) {
		input_try = 0;
		judge = 0;
		for (int i = 1; i < 10; i++) {
			cin >> input_try;
			if (cin.fail()) {
				judge = 1;
				cout << "�����������" << n << "��" << i << "��(���о���1��ʼ����)��ֵ" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			else if (input_try < 1 || input_try>9) {
				judge = 1;
				cout << "�����������" << n << "��" << i << "��(���о���1��ʼ����)��ֵ" << endl;
				break;
			}
			else {
				input_sudoku[n][i] = input_try;
				continue;
			}
		}
		if (judge == 1) {
			continue;
		}
		else
			break;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж�һ�������ǲ��������Ľ�
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int workout_sudoku(int in[])
{
	int judge = 0;
	int standard[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 1; i < 10; i++) {
		for (int n = 0; n < 9; n++) {
			if (in[i] == standard[n]) {
				judge += 1;
				standard[n] = 10;
				break;
			}
			else
				continue;
		}
	}
	if (judge == 9)
		return 1;
	else
		return 0;
}


int main() {
	//���õ�0�к͵�0��
	//���벿��
	int input_sudoku[10][10] = { 0 };
	cout << "������9*9�ľ���ֵ��1-9֮��" << endl;
	for (int i = 1; i < 10; i++) {
		input(input_sudoku, i);
	}
	//�����жϲ��֣����������жϺ���
	//��Ҫ�ֱ�����С����Լ�3*3���ж�
	//��
	int judge_line = 0;
	for (int i = 1; i < 10; i++) {
		judge_line += workout_sudoku(input_sudoku[i]);
	}
	//��
	int judge_column = 0;
	int into[10][10] = { 0 };
	for (int i = 1; i < 10; i++) {
		for (int n = 1; n < 10; n++) {
			into[i][n] = input_sudoku[n][i];
		}
	}
	for (int i = 1; i < 10; i++) {
		judge_column += workout_sudoku(into[i]);
	}
	//3*3
	int judge_3 = 0;
	int in_3[10][10] = {0};
	int number_x = 1;
	int number_y = 1;
	for (int p = 1; p < 10; p += 3) {
		for (int q = 1; q < 10; q += 3) {
			for (int m = p; m < p + 3; m++) {
				for (int n = q; n < q + 3; n++) {
					in_3[number_x][number_y] = input_sudoku[m][n];
					number_y += 1;
				}
			}
			number_x += 1;
			number_y = 1;
		}
	}
	for (int i = 1; i < 10; i++) {
		judge_3 += workout_sudoku(in_3[i]);
	}
	//���
	if ((judge_line == 9) && (judge_column == 9) && (judge_3 == 9))
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;

	return 0;
}
/*
7 9 3 4 8 6 9 3 1 
4 2 7 4 5 6 7 2 2
6 3 3 1 1 8 7 1 4
8 2 7 8 5 2 3 9 5
7 4 1 4 5 6 6 3 4
2 2 3 9 4 5 8 4 6
1 2 8 2 6 6 8 3 6
7 5 1 5 9 5 9 8 7
7 9 3 8 1 5 1 9 9
����
5 1 6 2 7 4 3 9 8
7 9 3 5 6 8 4 1 2
8 2 4 3 9 1 7 6 5
4 5 1 6 3 7 2 8 9
3 7 2 1 8 9 6 5 4
9 6 8 4 5 2 1 3 7
2 3 5 8 4 6 9 7 1
6 4 9 7 1 5 8 2 3
1 8 7 9 2 3 5 4 6
��
*/