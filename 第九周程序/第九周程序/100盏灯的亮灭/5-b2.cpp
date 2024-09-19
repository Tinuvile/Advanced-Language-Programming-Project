/* 2352495 信16 张竹和 */
#include <iostream>
using namespace std;

int main() {
	//初始化灯的序号和状态，假设0灭灯，1亮灯
	int light_number[100];
	int light_on_off[100];
	for (int i = 0; i <= 99; i++) {
		light_number[i] = i + 1;
		light_on_off[i] = 0;
	}
	//灯的动态变化
	for (int i = 0; i <= 99; i++) {
		for (int n = i; n <= 99; n++) {
			if (light_number[n] % (i + 1) == 0) {
				if (light_on_off[n] == 0)
					light_on_off[n] = 1;
				else if (light_on_off[n] == 1)
					light_on_off[n] = 0;
			}
			else
				continue;
		}
	}
	//结果输出
	for (int i = 0; i <= 99; i++) {
		if (light_on_off[i] == 1)
			cout << light_number[i] << " ";
	}
	cout << endl;
	return 0;
}