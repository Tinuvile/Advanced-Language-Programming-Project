/* 2352495 ����� ��16 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

int count = 1;

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
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		count++;
	}
	else {
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		count++;
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
	int ret;
	//���봦��
	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		ret = scanf("%d", &num_floor);
		if (ret != 1) {
			//cout << "����Ƿ�������������" << endl;
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor < 1 || num_floor>16) {
			while (getchar() != '\n');
			continue;
		}
		else if (num_floor >= 1 && num_floor <= 16) {
			while (getchar() != '\n');
			break;
		}
	}
	while (1) {
		printf("��������ʼ��(A-C)\n");
		ret = scanf("%c", &begin_p);
		if (ret != 1) {
			while (getchar() != '\n');
			continue;
		}
		else if (begin_p != 'A' && begin_p != 'B' && begin_p != 'C' && begin_p != 'a' && begin_p != 'b' && begin_p != 'c') {
			while (getchar() != '\n');
			continue;
		}
		else if (begin_p == 'A' || begin_p == 'B' || begin_p == 'C') {
			while (getchar() != '\n');
			break;
		}
		else if (begin_p == 'a' || begin_p == 'b' || begin_p == 'c') {
			begin_p = begin_p - 32;
			while (getchar() != '\n');
			break;
		}
	}
	while (1) {
		printf("������Ŀ����(A-C)\n");
		ret = scanf("%c", &end_p);
		if (ret != 1) {
			//cout << "����Ƿ�������������" << endl;
			while (getchar() != '\n');
			continue;
		}
		else if (end_p != 'A' && end_p != 'B' && end_p != 'C' && end_p != 'a' && end_p != 'b' && end_p != 'c') {
			while (getchar() != '\n');
			continue;
		}
		else
			if (((int)(end_p) - (int)(begin_p) != 32) && ((int)(end_p) - (int)(begin_p) != -32) && (end_p != begin_p)) {
				if (end_p == 'a' || end_p == 'b' || end_p == 'c') {
					end_p = end_p - 32;
				}
				while (getchar() != '\n');
				break;
			}
			else {
				printf("Ŀ����(%d)��������ʼ��(%d)��ͬ\n", end_p, begin_p);
				while (getchar() != '\n');
				continue;
			}
	}
	//ѡ���м�ѡ��
	if (((begin_p == 'A' || begin_p == 'a') && (end_p == 'B' || end_p == 'b')) || ((begin_p == 'B' || begin_p == 'b') && (end_p == 'A' || end_p == 'a'))) {
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