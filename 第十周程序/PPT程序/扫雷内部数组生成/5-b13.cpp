/* 2352495 信16 张竹和 */
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
using namespace std;

const int row = 10;
const int column = 26;
const int mine_number = 50;

int main() {
	char landmine[row][column] = { '0' };
	int mine_placed = 0;

	/* srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可
	   下面的两个srand，根据需要打开其中的一个，注释掉另一个，观察运行结果
	*/
	srand((unsigned int)(time(0)));
	//	srand(111); //可以替换为其它数字，自行替换并观察结果 

	//随机放置雷
	while (mine_placed < mine_number) {
		int x = rand() % row;
		int y = rand() % column;
		if (landmine[x][y] != '*') {
			landmine[x][y] = '*';
			mine_placed++;
		}
	}

	//计算周围雷数
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (landmine[i][j] != '*') {
				int count = 0;
				for (int m = -1; m <= 1; m++) {
					for (int n = -1; n <= 1; n++) {
						int near_x = i + m;
						int near_y = j + n;
						if (near_x >= 0 && near_x < row && near_y >= 0 && near_y < column && landmine[near_x][near_y] == '*') {
							count++;
						}
					}
				}
				landmine[i][j] = count + '0';
			}
		}
	}

	//打印
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << landmine[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}