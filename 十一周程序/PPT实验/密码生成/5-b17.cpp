/* 2352495 信16 张竹和 */
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

	// 设置生成随机字符的ASCII码的范围
	//int random = rand() % (max - min + 1) + min;
	int min_upper = 65;//min_upper='A'
	int max_upper = 90;
	int min_lower = 97;
	int max_lower = 122;
	int min_digit = 48;
	int max_digit = 57;

	//大写字母
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
	//小写字母
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
	//数字
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
	//其他字符
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
	//若小于总体字符的补充
	if (length > (uppercase + lowercase + digit_num + other_num)) {
		for (int i = 0; i < length - (uppercase + lowercase + digit_num + other_num); i++) {
			for (int judge = 0; judge == 0;) {
				int position = rand() % length;
				//设置随机数选择补充字符的种类
				int choose = rand() % 4;
				//大写字母
				if (choose == 0) {
					int random_add = rand() % (max_upper - min_upper + 1) + min_upper;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//小写字母
				else if (choose == 1) {
					int random_add = rand() % (max_lower - min_lower + 1) + min_lower;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//数字
				else if (choose == 2) {
					int random_add = rand() % (max_digit - min_digit + 1) + min_digit;
					if (code[position] == '\0') {
						code[position] = char(random_add);
						judge = 1;
					}
				}
				//其他字符
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
	//输入处理
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int length, uppercase, lowercase, digit_num, other_num, sum_number;
	int input_judge = 0;
	cin >> length >> uppercase >> lowercase >> digit_num >> other_num;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "输入非法" << endl;
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
									cout << "所有字符类型之和[" << uppercase << "+" << lowercase << "+" << digit_num << "+" << other_num << "]大于总密码长度[" << length << "]" << endl;
									input_judge=1;
								}
							}
						}
						else {
							cout << "其他符号个数[" << other_num << "]不正确" << endl;
							input_judge=1;
						}
					}
					else {
						cout << "数字个数[" << digit_num << "]不正确" << endl;
						input_judge=1;
					}
				}
				else {
					cout << "小写字母个数[" << lowercase << "]不正确" << endl;
					input_judge=1;
				}
			}
			else {
				cout << "大写字母个数[" << uppercase << "]不正确" << endl;
				input_judge=1;
			}

		}
		else {
			cout << "密码长度长度[" << length << "]不正确" << endl;
			input_judge=1;
		}
	}

	if (input_judge == 0) {
		cout << length << " " << uppercase << " " << lowercase << " " << digit_num << " " << other_num << endl;

		// srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可
		srand((unsigned int)(time(0)));

		for (int i = 0; i < 10; i++) {
			code_generate_output(length, uppercase, lowercase, digit_num, other_num);
		}
	}

	return 0;
}