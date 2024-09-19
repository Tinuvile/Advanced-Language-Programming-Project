#include <iostream>
using namespace std;

extern int t;

int value()
{
	t = t + 1;
	return t;
}