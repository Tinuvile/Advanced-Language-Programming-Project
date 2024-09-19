/* 2352495 张竹和 信16 */
#include <iostream>
#include <cstring>
using namespace std;

int judge(char *str)
{
	int judge_str = 0;
	//储存反转后的字符串
	char reversal_str[80];
	char* re_str = reversal_str;
	//将字符反转放入
	char* str_s = str + strlen(str) - 1;
	while (str_s >= str) {
		*re_str = *str_s;
		str_s--;
		re_str++;
	}
	*re_str = '\0'; //添加字符终止符
	re_str = reversal_str;
	//比较
	for (; *str != '\0'; str++, re_str++) {
		if (*str != *re_str) {
			judge_str = 1;
			break;
		}
	}
	return judge_str;
}

int main() {
	char str[80];
	char* p;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	if (fgets(str, 80, stdin) != NULL) {
		str[strcspn(str, "\n")] = '\0';
	}
	p = str;

	if (judge(p) == 0)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}