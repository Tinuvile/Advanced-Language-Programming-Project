#include <iostream>
#include<climits>
using namespace std;

int min(int a, int b, int c = INT_MAX, int d = INT_MAX)
{
	if (a <= b && a <= c && a <= d)
		return a;
	else if (b <= a && b <= c && b <= d)
		return b;
	else if (c <= a && c <= b && c <= d)
		return c;
	else if (d <= a && d <= b && d <= c)
		return d;
	else
		return 0;
}

int main() {
	int n, a, b, c, d, MIN = 0;
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
				MIN = min(a, b);
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
				MIN = min(a, b, c);
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
				MIN = min(a, b, c, d);
			break;
		}
	}

	if (n > 4 || n < 2)
		cout << "个数输入错误" << endl;
	else
		cout << "min=" << MIN << endl;
	return 0;
}