/* ��16 2352495 �����*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int x;
	double n = 1, i = 1;
	double t = 1;
	double m = 0, m1 = 1, dm = 0, n1 = 1;
	do {
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if (x < -10 || x>65) {
			cout << "����Ƿ�������������" << endl;
		}
	} while (x < -10 || x>65);
	//cout << "x=" << x << endl;

	//m�����ս����dm�ǵ�ֵ��n1�ǽ׳�,m1��dm����ֵ

	do {
		/*n1 = 1;
		t = 1;
		for (i = 1; i <= n; ++i) {
			//n1 *= i;
			//pow *= x;
		}*/
		//cout << "i=" << i << " " << "n=" << n << endl;
		t = x / i;
		n1 *= t;
		//cout << "t=" << t << " ";
		//cout << "n1=" << n1 << endl;
		dm = n1;
		//cout << "dm=" << dm << " ";
		//dm = pow / n1;
		m += dm;
		//cout << "m=" << m << endl;
		m1 = abs(dm);
		n = n + 1;
		i = i + 1;
		//cout << "---------------" << endl;
	} while (m1 >= 1e-6);

	m = m - dm;

	cout << "e^" << x << "=" << setprecision(10) << m+1;

	return 0;
}