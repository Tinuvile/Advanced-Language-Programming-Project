#include <iostream>
using namespace std;
int main()
{
	float f = 100.25;
	cout << f << endl;
	cout << typeid(f).name() << endl;

	return 0;
}