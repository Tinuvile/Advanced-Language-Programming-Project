/* 2352495 ����� ��16 */
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c;

void f1();
void f2();
void f3();
void f4();

int main() {
	double delta;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
	cin >> a >> b >> c;
	//��������
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	//�������
	if (a == 0) {
		f1();
	}
	else {
		if (delta > 0) {
			f2();
		}
		else if (delta == 0) {
			f3();
		}
		else if (delta < 0) {
			f4();
		}
	}
}