/* 2352495 ��16 ����� */
#include <iostream>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";


void code_generate_output(const int length, const int uppercase, const int lowercase, const int digit_num, const int other_num)
{
	char code[16] = { '\0' };

	// ������������ַ���ASCII��ķ�Χ
	//int random = rand() % (max - min + 1) + min;
	int min_upper = 65;//min_upper='A'
	int max_upper = 90;
	int min_lower = 97;
	int max_lower = 122;
	int min_digit = 48;
	int max_digit = 57;

	//��д��ĸ
	for (int i = 0; i < uppercase; i++) {
		for (int judge = 0; judge == 0;) {
			int position = rand() % length;
			int random_upper = rand() % (max_upper - min_upper + 1) + min_upper;
			if (code[position] == '\0') {
				code[position] = char(random_upper);
				judge = 1;
			}
		}
	}
	//Сд��ĸ
	for (int i = 0; i < lowercase; i++) {
		for (int judge = 0; judge == 0;) {
			int position = rand() % length;
			int random_lower = rand() % (max_lower - min_lower + 1) + min_lower;
			if (code[position] == '\0') {
				code[position] = char(random_lower);
				judge = 1;
			}
		}
	}
	//����
	for (int i = 0; i < digit_num; i++) {
		for (int judge = 0; judge == 0;) {
			int position = rand() % length;
			int random_digit = rand() % (max_digit - min_digit + 1) + min_digit;
			if (code[position] == '\0') {
				code[position] = char(random_digit);
				judge = 1;
			}
		}
	}
	//�����ַ�
	for (int i = 0; i < other_num; i++) {
		for (int judge = 0; judge == 0;) {
			int position = rand() % length;
			int random_other = rand() % 15;
			if (code[position] == '\0') {
				code[position] = other[random_other];
				judge = 1;
			}
		}
	}
	//��С�������ַ��Ĳ���
	if (length > (uppercase + lowercase + digit_num + other_num)) {
		for (int i = 0; i < length - (uppercase + lowercase + digit_num + other_num); i++) {
			for (int judge = 0; judge == 0;) {
				int position = rand() % length;
				//���������ѡ�񲹳��ַ�������
				int choose = rand() % 4;
				//��д��ĸ
				if (choose == 0) {
					int random_add = rand() % (max_upper - min_upper + 1) + min_upper;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//Сд��ĸ
				else if (choose == 1) {
					int random_add = rand() % (max_lower - min_lower + 1) + min_lower;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//����
				else if (choose == 2) {
					int random_add = rand() % (max_digit - min_digit + 1) + min_digit;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//�����ַ�
				else if (choose == 3) {
					int random_add = rand() % 15;
					if (code[position] == '\0') {
						code[position] = other[random_add];
						judge = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < length; i++) {
		cout << code[i];
	}
	cout << endl;
}


int main() {
	//���봦��
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	int length, uppercase, lowercase, digit_num, other_num, sum_number;
	int input_judge = 0;
	cin >> length >> uppercase >> lowercase >> digit_num >> other_num;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "����Ƿ�" << endl;
		input_judge = 1;
	}
	else {
		sum_number = uppercase + lowercase + digit_num + other_num;
		if ((length >= 12) && (length <= 16)) {
			if (uppercase >= 2) {
				if (lowercase >= 2) {
					if (digit_num >= 2) {
						if (other_num >= 2) {
							if (length == sum_number) {
								input_judge = 0;
							}
							else {
								if (sum_number > length) {
									cout << "�����ַ�����֮��[" << uppercase << "+" << lowercase << "+" << digit_num << "+" << other_num << "]���������볤��[" << length << "]" << endl;
									input_judge=1;
								}
							}
						}
						else {
							cout << "�������Ÿ���[" << other_num << "]����ȷ" << endl;
							input_judge=1;
						}
					}
					else {
						cout << "���ָ���[" << digit_num << "]����ȷ" << endl;
						input_judge=1;
					}
				}
				else {
					cout << "Сд��ĸ����[" << lowercase << "]����ȷ" << endl;
					input_judge=1;
				}
			}
			else {
				cout << "��д��ĸ����[" << uppercase << "]����ȷ" << endl;
				input_judge=1;
			}

		}
		else {
			cout << "���볤�ȳ���[" << length << "]����ȷ" << endl;
			input_judge=1;
		}
	}

	if (input_judge == 0) {
		cout << length << " " << uppercase << " " << lowercase << " " << digit_num << " " << other_num << endl;

		// srand������������α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���
		srand((unsigned int)(time(0)));

		for (int i = 0; i < 10; i++) {
			code_generate_output(length, uppercase, lowercase, digit_num, other_num);
		}
	}

	return 0;
}