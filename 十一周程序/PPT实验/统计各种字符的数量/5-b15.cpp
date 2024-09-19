/* 2352495 信16 张竹和 */
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int main() {
	char str[3][128] = { '\0' };
	for (int i = 0; i < 3; i++) {
		cout << "请输入第" << i + 1 << "行" << endl;
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

	cout << "大写 : " << uppercase << endl;
	cout << "小写 : " << lowercase << endl;
	cout << "数字 : " << digit_count << endl;
	cout << "空格 : " << space_count << endl;
	cout << "其他 : " << other_count << endl;

	return 0;
	/*测试用例
	Welcome to Tongji University.
    <Hello,world!> -> 《Hello，world！》
    Name=张三 and No=2359999 && Sex=男
	*/

}