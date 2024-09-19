#include <iostream>
using namespace std;
int main()
{
	cout << 119       << endl;
	cout << 0b1110111 << endl;
	cout << 0167      << endl;
	cout << 0x77      << endl;

	cout << hex << 119       << endl;
	cout << oct << 0b1110111 << endl;
	cout << dec << 0167      << endl;
	cout << hex << 0x77      << endl;

	cout << dec << 119 << endl;
	cout << "0x" << hex << 0b1110111 << endl;
	cout << "(" << oct << 0167 << ")8" << endl;

	return 0;
}