#include <iostream>
using namespace std;

class base {
public:
	virtual void fun1();
	virtual void fun2() {
		cout << "base::fun2" << endl;
	}
};

void base::fun1() {
	cout << "base::fun1" << endl;
}

class derive :public base {
public:
	void fun1() { base::fun1(); };
	void fun2() { base::fun2(); };
};

int main() {
	derive d;
	d.fun1();
	d.fun2();
	return 0;
}