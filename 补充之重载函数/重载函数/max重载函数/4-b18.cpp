#include <iostream>
using namespace std;

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int max(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else if (c > a && c > b)
		return c;
	else
		return 0;
}

int max(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d)
		return a;
	else if (b >= a && b >= c && b >= d)
		return b;
	else if (c >= a && c >= b && c >= d)
		return c;
	else if (d >= a && d >= b && d >= c)
		return d;
	else
		return 0;
}

int main() {
	int n, a, b, c, d, MAX = 0;
	while (true) {
		cout << "请输入个数num及num个正整数" << endl;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
		if (n > 4 || n < 2)
			break;
		if (n == 2) {
			cin >> a >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			else
				MAX = max(a, b);
			break;
		}
		if (n == 3) {
			cin >> a >> b >> c;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			else
				MAX = max(a, b, c);
			break;
		}
		if (n == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			else
				MAX = max(a, b, c, d);
			break;
		}
	}

	if (n > 4 || n < 2)
		cout << "个数输入错误" << endl;
	else
		cout << "max=" << MAX << endl;
	return 0;
}