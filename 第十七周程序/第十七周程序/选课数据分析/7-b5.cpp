/* 2352495 张竹和 信16 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名
	int status1;  //选课状态
	int status2;  //0表示该轮未选，1表示该轮已选
	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	friend class stu_list;
public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单
	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	void merge();
	void sort();
};


char* tj_strcpy(char* s1, const char* s2)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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


/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */

/***************************************************************************
  函数名称：
  功    能：将list_round_1/2中的非重复量输入list_merge数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void stu_list::merge()
{
	//先分别去除两个文件各自中的重复项
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
	//将文件1中未重复的直接加入数组
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
			//文件2中与文件1重复的
			for (int i = 0; i < T; i++) {
				if (list_round_2[j].no == list_merge[i].stu_no) {
					judge = 1;
					list_merge[i].status2 = 1;
					break;
				}
			}
			//未重复的
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
  函数名称：
  功    能：将数组按学号大小重新排序
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void stu_list::sort()
{
	for (int i = 0; i < list_merge_num - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				// 交换元素
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
			break; // 如果本轮没有发生交换，说明已经有序，提前结束
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
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{

}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << "最终选课名单" << endl;
	cout << "============================================================" << endl;
	cout << "序号 学号     姓名                            第一轮 第二轮" << endl;

	for (int i = 0; i < list_merge_num; i++) {
		cout << left << setw(4) << i + 1 << " " << setw(7) << list_merge[i].stu_no << "  " << setw(32) << list_merge[i].stu_name;
		if (list_merge[i].status1 == 1) {
			cout << left << "Y";
			cout << "      ";
			if (list_merge[i].status2 == 1)
				cout << left << "Y" << endl;
			else if (list_merge[i].status2 == 0)
				cout << left << "退课" << endl;
		}
		if (list_merge[i].status1 == 0) {
			cout << left << "/";
			cout << "      ";
			if (list_merge[i].status2 == 1)
				cout << left << "补选" << endl;
			else if (list_merge[i].status2 == 0)
				cout << left << "/" << endl;
		}
	}

	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */
	list.merge();
	list.sort();

	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

