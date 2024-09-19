/* ��16 2352495 ����� */
#include <iostream>
#include<cmath>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����������㽱���������룬��ȷ��Ԫ��
  ���������
  �� �� ֵ��
  ˵    ����ֻ������ if-else��䣬��switch-case�����÷�Ϊ0
***************************************************************************/
int calc_bonus(int profit)
{
	double bonus;
	if (profit >= 1 && profit <= 100000) {
		bonus = 0.1 * profit;
		return int(round(bonus));
	}
	else if (profit > 100000 && profit <= 200000) {
		bonus = (profit - 100000) * 0.075 + calc_bonus(100000);
		return int(round(bonus));
	}
	else if (profit > 200000 && profit <= 400000) {
		bonus = (profit - 200000) * 0.05 + calc_bonus(200000);
		return int(round(bonus));
	}
	else if (profit > 400000 && profit <= 600000) {
		bonus = (profit - 400000) * 0.03 + calc_bonus(400000);
		return int(round(bonus));
	}
	else if (profit > 600000 && profit <= 1000000) {
		bonus = (profit - 600000) * 0.015 + calc_bonus(600000);
		return int(round(bonus));
	}
	else if (profit > 1000000) {
		bonus = (profit - 1000000) * 0.01 + calc_bonus(1000000);
		return int(round(bonus));
	}
	else
		return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ����������Ӽ��̶�ȡһ��int�����������д����򰴴������߼��Ĺ��򣬸��������ʾ���ٴζ�
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int get_business_profit()
{
	int profit;
	while (true) {
		cout << "����������" << endl;
		cin >> profit;
		if (cin.fail()) {
			//cout << "����Ƿ�������������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (profit < 1) {
			continue;
		}
		else if (profit >= 1) {
			break;
		}
	}
	return profit;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int profit;

	profit = get_business_profit();
	cout << "Ӧ�������� : " << calc_bonus(profit) << endl;

	return 0;
}