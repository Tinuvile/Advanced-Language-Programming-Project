/* 2352495 ����� ��16 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	int status1;  //ѡ��״̬
	int status2;  //0��ʾ����δѡ��1��ʾ������ѡ
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend class stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void merge();
	void sort();
};


char* tj_strcpy(char* s1, const char* s2)
{
	/* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
	if (s1 == NULL) {
		return s1;
	}
	if (s2 == NULL) {
		*s1 = '\0';
		return s1;
	}
	int n = strlen(s2);
	char* s1_1 = s1;
	for (; *s2 != '\0'; s1_1++, s2++) {
		*s1_1 = *s2;
	}
	*s1_1 = '\0';
	return s1;
}


/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���list_round_1/2�еķ��ظ�������list_merge����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void stu_list::merge()
{
	//�ȷֱ�ȥ�������ļ������е��ظ���
	for (int i = 0; i < list_num_1; i++) {
		if (list_round_1[i].no != 0) {
			for (int j = i + 1; j < list_num_1; j++) {
				if (list_round_1[i].no == list_round_1[j].no) {
					list_round_1[j].no = 0;
				}
			}
		}
	}
	for (int i = 0; i < list_num_2; i++) {
		if (list_round_2[i].no != 0) {
			for (int j = i + 1; j < list_num_2; j++) {
				if (list_round_2[i].no == list_round_2[j].no) {
					list_round_2[j].no = 0;
				}
			}
		}
	}
	int mergeIndex = 0;
	//���ļ�1��δ�ظ���ֱ�Ӽ�������
	for (int i = 0; i < list_num_1; i++) {
		if (list_round_1[i].no != 0) {
			list_merge[mergeIndex].stu_no = list_round_1[i].no;
			tj_strcpy(list_merge[mergeIndex].stu_name, list_round_1[i].name);
			list_merge[mergeIndex].status1 = 1;
			list_merge[mergeIndex].status2 = 0;
			mergeIndex++;
		}
	}
	int T = mergeIndex;
	for (int j = 0; j < list_num_2; j++) {
		if (list_round_2[j].no != 0) {
			int judge = 0;
			//�ļ�2�����ļ�1�ظ���
			for (int i = 0; i < T; i++) {
				if (list_round_2[j].no == list_merge[i].stu_no) {
					judge = 1;
					list_merge[i].status2 = 1;
					break;
				}
			}
			//δ�ظ���
			if (judge == 0) {
				list_merge[mergeIndex].stu_no = list_round_2[j].no;
				tj_strcpy(list_merge[mergeIndex].stu_name, list_round_2[j].name);
				list_merge[mergeIndex].status1 = 0;
				list_merge[mergeIndex].status2 = 1;
				mergeIndex++;
			}
		}
	}
	list_merge_num = mergeIndex;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ������鰴ѧ�Ŵ�С��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void stu_list::sort()
{
	for (int i = 0; i < list_merge_num - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				// ����Ԫ��
				int temp_no = list_merge[j].stu_no;
				char temp_name[MAX_NAME_LEN];
				int temp_1 = list_merge[j].status1;
				int temp_2 = list_merge[j].status2;
				tj_strcpy(temp_name, list_merge[j].stu_name);
				list_merge[j].stu_no = list_merge[j + 1].stu_no;
				list_merge[j].status1 = list_merge[j + 1].status1;
				list_merge[j].status2 = list_merge[j + 1].status2;
				tj_strcpy(list_merge[j].stu_name, list_merge[j + 1].stu_name);
				list_merge[j + 1].stu_no = temp_no;
				list_merge[j + 1].status1 = temp_1;
				list_merge[j + 1].status2 = temp_2;
				tj_strcpy(list_merge[j + 1].stu_name, temp_name);

				swapped = true;
			}
		}
		if (!swapped) {
			break; // �������û�з���������˵���Ѿ�������ǰ����
		}
	}
}


/*
void stu_list::sort()
{
	for (int i = 0; i < list_merge_num - 1; i++) {
		if (list_merge[i].stu_no > list_merge[i + 1].stu_no) {
			int temp_no = list_merge[i].stu_no;
			char temp_name[MAX_NAME_LEN];
			int temp_1 = list_merge[i].status1;
			int temp_2 = list_merge[i].status2;
			tj_strcpy(temp_name, list_merge[i].stu_name);
			list_merge[i].stu_no = list_merge[i + 1].stu_no;
			list_merge[i].status1 = list_merge[i + 1].status1;
			list_merge[i].status2 = list_merge[i + 1].status2;
			list_merge[i + 1].status1 = temp_1;
			list_merge[i + 1].status2 = temp_2;
			tj_strcpy(list_merge[i].stu_name, list_merge[i + 1].stu_name);
			list_merge[i + 1].stu_no = temp_no;
			tj_strcpy(list_merge[i + 1].stu_name, temp_name);
			i = -1;
		}
	}
}
*/


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;

	for (int i = 0; i < list_merge_num; i++) {
		cout << left << setw(4) << i + 1 << " " << setw(7) << list_merge[i].stu_no << "  " << setw(32) << list_merge[i].stu_name;
		if (list_merge[i].status1 == 1) {
			cout << left << "Y";
			cout << "      ";
			if (list_merge[i].status2 == 1)
				cout << left << "Y" << endl;
			else if (list_merge[i].status2 == 0)
				cout << left << "�˿�" << endl;
		}
		if (list_merge[i].status1 == 0) {
			cout << left << "/";
			cout << "      ";
			if (list_merge[i].status2 == 1)
				cout << left << "��ѡ" << endl;
			else if (list_merge[i].status2 == 0)
				cout << left << "/" << endl;
		}
	}

	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge();
	list.sort();

	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

