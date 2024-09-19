#include <iostream>
using namespace std;
int main()
{
	//解法1
	cout << 0x7FFFFFFFFFFFFFFF << endl;

	//解法2
	unsigned long long x = -1LL;
	cout << x / 2 << endl;
	
	return 0;
}