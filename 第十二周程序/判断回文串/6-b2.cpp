/* 2352495 ����� ��16 */
#include <iostream>
#include <cstring>
using namespace std;

int judge(char *str)
{
	int judge_str = 0;
	//���淴ת����ַ���
	char reversal_str[80];
	char* re_str = reversal_str;
	//���ַ���ת����
	char* str_s = str + strlen(str) - 1;
	while (str_s >= str) {
		*re_str = *str_s;
		str_s--;
		re_str++;
	}
	*re_str = '\0'; //����ַ���ֹ��
	re_str = reversal_str;
	//�Ƚ�
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
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
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