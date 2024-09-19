#include <iostream>
using namespace std;
int main()
{
	int a = 7, n = 11;
	a += a += a *= a;
	cout << a << ' ' << n << endl;

	return 0;
}