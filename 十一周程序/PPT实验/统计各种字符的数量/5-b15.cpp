/* 2352495 ��16 ����� */
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int main() {
	char str[3][128] = { '\0' };
	for (int i = 0; i < 3; i++) {
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);
	}
	int uppercase = 0, lowercase = 0, digit_count = 0, space_count = 0, other_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 128; j++) {
			if (str[i][j] != '\0') {
				if ((str[i][j] >= 'A') && (str[i][j] <= 'Z')) {
					uppercase++;
				}
				else if ((str[i][j] >= 'a') && (str[i][j] <= 'z')) {
					lowercase++;
				}
				else if ((str[i][j] >= '0') && (str[i][j] <= '9')) {
					digit_count++;
				}
				else if (str[i][j] == ' ') {
					space_count++;
				}
				else {
					other_count++;
				}
			}
		}
	}

	cout << "��д : " << uppercase << endl;
	cout << "Сд : " << lowercase << endl;
	cout << "���� : " << digit_count << endl;
	cout << "�ո� : " << space_count << endl;
	cout << "���� : " << other_count << endl;

	return 0;
	/*��������
	Welcome to Tongji University.
    <Hello,world!> -> ��Hello��world����
    Name=���� and No=2359999 && Sex=��
	*/

}