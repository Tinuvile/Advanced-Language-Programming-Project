#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int main() {
	//int input1 = _getch();
	//int input2 = _getch();
	//int i = getchar();
	//char input3 = _getch();
	//char input4 = _getch();
	//int input3 = _getch();
	//int input4 = _getch();
	//cout << i << endl;
	//cout << "input1=" << input1 << endl;
	//cout << "input2=" << input2 << endl;
	//cout << "input3=" << input2 << endl;
	//cout << "input4=" << input2 << endl;
	//cout << "input3=" << input3 << endl;
	//cout << "input4=" << input3 << endl;
	//cout << setw(0) << ' ' << endl;

	/* srand������������α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���
	   ���������srand��������Ҫ�����е�һ����ע�͵���һ�����۲����н��
	*/
	srand((unsigned int)(time(0)));
	//	srand(111); //�����滻Ϊ�������֣������滻���۲��� 

		/*����10��α����� */
	for (int i = 0; i < 10; i++)
		cout << rand() << endl;

	return 0;
}