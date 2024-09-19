/* 信16 2352495 张竹和 */
#include <iostream>
#include<cmath>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：根据利润计算奖金（四舍五入，精确到元）
  输入参数：
  返 回 值：
  说    明：只允许用 if-else语句，用switch-case语句则得分为0
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
  函数名称：
  功    能：
  输入参数：从键盘读取一个int型正整数，有错误则按错误处理逻辑的规则，给出输出提示后再次读
  返 回 值：
  说    明：
***************************************************************************/
int get_business_profit()
{
	int profit;
	while (true) {
		cout << "请输入利润" << endl;
		cin >> profit;
		if (cin.fail()) {
			//cout << "输入非法，请重新输入" << endl;
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int profit;

	profit = get_business_profit();
	cout << "应发奖金数 : " << calc_bonus(profit) << endl;

	return 0;
}