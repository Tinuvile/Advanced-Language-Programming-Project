/* 2352495 张竹和 信16 */
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double turn2to10(char* input, int len)
{
	double num10 = 0;
	for (; *input != '\0'; input++, len--) {
		num10 = num10 + (*input - '0') * pow(2, len - 1);
	}

	return num10;
}

int main() {
	char input[33];

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin.getline(input, 33);
	int len = strlen(input);

	cout << unsigned int(turn2to10(input, len)) << endl;

	return 0;
}
//11111111111111111111111111111111