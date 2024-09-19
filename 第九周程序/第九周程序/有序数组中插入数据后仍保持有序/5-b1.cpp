/* 2352495 信16 张竹和 */
#include <iostream>
using namespace std;

int main() {
	int i, n;
	int a[21] = { 0 };
	//原数组输入
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (i = 0; i <= 19; i++) {
		int input_number;
		cin >> input_number;
		if (input_number <= 0) {
			if (i == 0)
				cout << "无有效输入" << endl;
			break;
		}
		else
			a[i] = input_number;
	}
	if (i != 0) {
		cin.ignore(1024, '\n');
		//原数组输出
		cout << "原数组为:" << endl;
		for (i = 0; i <= 19; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
		//插入数据输入
		cout << "请输入要插入的正整数" << endl;
		cin >> n;
		//插入数据顺序解决及输出
		for (i = 0; i <= 20; i++) {
			if (a[i] >= n) {
				for (int t = 20; t > i; t--) {
					a[t] = a[t - 1];
				}
				a[i] = n;
				break;
			}
		}
		cout << "插入后的数组为:" << endl;
		for (i = 0; i <= 20; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
	}
	return 0;
}