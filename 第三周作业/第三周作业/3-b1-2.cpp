#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double r, h;
	const double pi = 3.14159;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h ;
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << "Բ�ܳ�     : " << 2 * pi * r << endl;
	cout << "Բ���     : " << pi * r * r << endl;
	cout << "Բ������ : " << 4 * pi * r * r << endl;
	cout << "Բ�����   : " << 4 * pi * r * r * r / 3 << endl;
	cout << "Բ�����   : " << pi * r * r * h << endl;

	return 0;
}