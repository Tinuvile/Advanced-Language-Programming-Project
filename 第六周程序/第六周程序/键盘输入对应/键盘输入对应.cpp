#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {
	//int input1 = _getch();
	//int input2 = _getch();
	//int i = getchar();
	//char input3 = _getch();
	//char input4 = _getch();
	//int input3 = _getch();
	//int input4 = _getch();
	//cout << i << endl;
	//cout << "input1=" << input1 << endl;
	//cout << "input2=" << input2 << endl;
	//cout << "input3=" << input2 << endl;
	//cout << "input4=" << input2 << endl;
	//cout << "input3=" << input3 << endl;
	//cout << "input4=" << input3 << endl;
	//cout << setw(0) << ' ' << endl;

	/* srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可
	   下面的两个srand，根据需要打开其中的一个，注释掉另一个，观察运行结果
	*/
	srand((unsigned int)(time(0)));
	//	srand(111); //可以替换为其它数字，自行替换并观察结果 

		/*生成10个伪随机数 */
	for (int i = 0; i < 10; i++)
		cout << rand() << endl;

	return 0;
}