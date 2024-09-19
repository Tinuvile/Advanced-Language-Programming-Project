#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r, h;
	const double pi = 3.14159;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h ;
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << "圆周长     : " << 2 * pi * r << endl;
	cout << "圆面积     : " << pi * r * r << endl;
	cout << "圆球表面积 : " << 4 * pi * r * r << endl;
	cout << "圆球体积   : " << 4 * pi * r * r * r / 3 << endl;
	cout << "圆柱体积   : " << pi * r * r * h << endl;

	return 0;
}