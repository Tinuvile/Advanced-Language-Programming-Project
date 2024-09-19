/* 2352495 ��16 ����� */
#include <iostream>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";
const char check_char[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*-_=+,.?";

int main() {
	int input[5];
	char code[10][16] = { '\0' };
	int judge = 0;
	//����һ�в�����
	char ignore[120];
	cin.getline(ignore, 120);
	//������ַ�
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
	}
	//����ַ��Ƿ���ȷ
	if (input[0] > 16 || input[0] < 12 || input[1] < 2 || input[2] < 2 || input[3] < 2 || input[4] < 2) {
		judge = 1;
	}
	//�ַ���ȷ������ȡ
	if (judge == 0) {
		//��ȡ���������
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < input[0]; j++) {
				cin >> code[i][j];
			}
		}
		//��������ܳ�
		int length[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				if (code[i][j] != '\0') {
					length[i]++;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (length[i] != input[0])
				judge = 1;
		}
		//�����������ַ�������
		//��д��ĸ
		int upper_num[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				if ((code[i][j] >= 65) && (code[i][j] <= 90)) {
					upper_num[i]++;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (upper_num[i] < input[1])
				judge = 1;
		}
		//Сд��ĸ
		int lower_num[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				if ((code[i][j] >= 97) && (code[i][j] <= 122)) {
					lower_num[i]++;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (lower_num[i] < input[2])
				judge = 1;
		}
		//����
		int digit_num[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				if ((code[i][j] >= 48) && (code[i][j] <= 57)) {
					digit_num[i]++;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (digit_num[i] < input[3])
				judge = 1;
		}
		//����
		int other_num[10] = { 0 };
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				for (int n = 0; n < 15; n++) {
					if (code[i][j] == other[n]) {
						other_num[i]++;
						break;
					}
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			if (other_num[i] < input[4])
				judge = 1;
		}
		//����ַ�
		int check = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 16; j++) {
				for (int n = 0; n < 77; n++) {
					if ((code[i][j] != check_char[n]) && (code[i][j] != '\0')) {
						check++;
					}
				}
				if (check == 77) {
					judge = 1;
				}
				check = 0;
			}
		}
		//������峤��
		if (input[0] < input[1] + input[2] + input[3] + input[4])
			judge = 1;
	}

	//������
	if (judge == 0)
		cout << "��ȷ" << endl;
	else if (judge == 1)
		cout << "����" << endl;

	return 0;
}