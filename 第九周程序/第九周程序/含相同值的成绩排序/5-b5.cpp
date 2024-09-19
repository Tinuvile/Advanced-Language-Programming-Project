/* 2352495 信16 张竹和 */
#include <iostream>
using namespace std;

int main() {
	int grade_input[1000] = { 0 }, grade[101] = { 0 };
	int input = 0;
	int count = 0;
	int rank = 1;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (int i = 0; i < 1000; i++) {
		cin >> input;
		if (input < 0) {
			if (i == 0)
				cout << "无有效输入" << endl;
			break;
		}
		grade_input[i] = input;
		grade[input]++;
		count++;
	}
	cout << "输入的数组为:" << endl;
	for (int i = 0; i < count; i++) {
		cout << grade_input[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
	cout << "分数与名次的对应关系为:" << endl;
	for (int i = 100; i >= 0; i--) {
		if (grade[i] > 0) {
			for (int n = 0; n < grade[i]; n++) {
				cout << i << " " << rank << endl;
			}
			rank += grade[i];
		}
	}
	return 0;
}
//87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
//87 86 56 76 87 92 76 0 96 98 0 23 -1