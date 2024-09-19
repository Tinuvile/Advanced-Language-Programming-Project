/* 2352495 ����� ��16 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		cout << setw(2) << n << "# " << src << " --> " << dst << endl;
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		cout << setw(2) << n << "# " << src << " --> " << dst << endl;
		hanoi(n - 1, tmp, src, dst);
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int num_floor;
	char begin_p, between_p, end_p;
	//���봦��
	while (true) {
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
		cin >> num_floor;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (num_floor < 1 || num_floor>16) {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (num_floor >= 1 && num_floor <= 16) {
			cin.ignore(1024, '\n');
			break;
		}
	}
	while (true) {
		cout << "��������ʼ��(A-C)" << endl;
		cin >> begin_p;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (begin_p != 'A' && begin_p != 'B' && begin_p != 'C' && begin_p != 'a' && begin_p != 'b' && begin_p != 'c') {
			cin.ignore(1024, '\n');
			continue;
		}
		else if (begin_p == 'A' || begin_p == 'B' || begin_p == 'C') {
			cin.ignore(1024, '\n');
			break;
		}
		else if (begin_p == 'a' || begin_p == 'b' || begin_p == 'c') {
			begin_p = begin_p - 32;
			cin.ignore(1024, '\n');
			break;
		}
	}
	while (true) {
		cout << "������Ŀ����(A-C)" << endl;
		cin >> end_p;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (end_p != 'A' && end_p != 'B' && end_p != 'C' && end_p != 'a' && end_p != 'b' && end_p != 'c') {
			cin.ignore(1024, '\n');
			continue;
		}
		else
			if ((int(end_p) - int(begin_p) != 32) && (int(end_p) - int(begin_p) != -32) && (end_p != begin_p)) {
				if (end_p == 'a' || end_p == 'b' || end_p == 'c') {
					end_p = end_p - 32;
				}
				cin.ignore(1024, '\n');
				break;
			}
			else {
				cout << "Ŀ����(" << end_p << ")��������ʼ��(" << begin_p << ")��ͬ" << endl;
				cin.ignore(1024, '\n');
				continue;
			}
	}
	//ѡ���м�ѡ��
	if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'B' || end_p == 'b'))|| ((begin_p == 'B' || begin_p == 'b') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'C';
	}
	else if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'C' || end_p == 'c')) || ((begin_p == 'C' || begin_p == 'c') && (end_p == 'A' || end_p == 'a'))) {
		between_p = 'B';
	}
	else {
		between_p = 'A';
	}
	//��������
	hanoi(num_floor, begin_p, between_p, end_p);

	return 0;
}