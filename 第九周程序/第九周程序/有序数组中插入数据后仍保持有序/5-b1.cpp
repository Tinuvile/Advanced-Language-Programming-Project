/* 2352495 ��16 ����� */
#include <iostream>
using namespace std;

int main() {
	int i, n;
	int a[21] = { 0 };
	//ԭ��������
	cout << "��������������������������20������0������������" << endl;
	for (i = 0; i <= 19; i++) {
		int input_number;
		cin >> input_number;
		if (input_number <= 0) {
			if (i == 0)
				cout << "����Ч����" << endl;
			break;
		}
		else
			a[i] = input_number;
	}
	if (i != 0) {
		cin.ignore(1024, '\n');
		//ԭ�������
		cout << "ԭ����Ϊ:" << endl;
		for (i = 0; i <= 19; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
		//������������
		cout << "������Ҫ�����������" << endl;
		cin >> n;
		//��������˳���������
		for (i = 0; i <= 20; i++) {
			if (a[i] >= n) {
				for (int t = 20; t > i; t--) {
					a[t] = a[t - 1];
				}
				a[i] = n;
				break;
			}
		}
		cout << "����������Ϊ:" << endl;
		for (i = 0; i <= 20; i++) {
			if (a[i] > 0)
				cout << a[i] << " ";
			else
				break;
		}
		cout << endl;
	}
	return 0;
}