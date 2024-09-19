/* 2352495 信16 张竹和 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	double x, y;
	int a, b, c, d, e, f, g, h, i, j, k, l;
	double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	int m;
	n1 = 1000000000, n2 = 100000000, n3 = 10000000, n4 = 1000000, n5 = 100000, n6 = 10000, n7 = 1000, n8 = 100, n9 = 10, n10 = 1;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> x;
	a = int(x / n1);
	b = int((x - a * n1) / n2);
	c = int((x - a * n1 - b * n2) / n3);
	d = int((x - a * n1 - b * n2 - c * n3) / n4);
	e = int((x - a * n1 - b * n2 - c * n3 - d * n4) / n5);
	f = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5) / n6);
	g = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6) / n7);
	h = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7) / n8);
	i = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8) / n9);
	j = int((x - a * n1 - b * n2 - c * n3 - d * n4 - e * n5 - f * n6 - g * n7 - h * n8 - i * n9) / n10);

	y = a * n1 + b * n2 + c * n3 + d * n4 + e * n5 + f * n6 + g * n7 + h * n8 + i * n9 + j * n10;
	m = int(round(100 * (x - y)));
	l = m % 10;
	k = (m - l) / 10;
	
	//k=int(100*(x-y))

	cout << "大写结果是:" << endl;

	//十亿位及亿位输出
	daxie(a, 0);
	if (a != 0) {
		cout << "拾";
	}
	daxie(b, 0);
	if (a != 0 || b != 0)
		cout << "亿";

	//万位输出
	daxie(c, b != 0 && d != 0);
	if (c != 0) {
		cout << "仟";
	}
	daxie(d, e != 0 && x >= 1000000);
	if (d != 0) {
		cout << "佰";
	}
	daxie(e, f != 0 && x >= 100000);
	if (e != 0) {
		cout << "拾";
	}
	daxie(f, 0);
	if (c != 0 || d != 0 || e != 0 || f != 0)
		cout << "万";

	//个位输出
	daxie(g, h != 0 && x >= 1000);
	if (g != 0) {
		cout << "仟";
	}
	daxie(h, i != 0 && x >= 100);
	if (h != 0) {
		cout << "佰";
	}
	daxie(i, j != 0 && x >= 10);
	if (i != 0) {
		cout << "拾";
	}
	daxie(j,0);
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0)
		cout << "圆";

	//处理小数点后两位
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l == 0)
			cout << "整" << endl;
	}
	if (k != 0) {
		daxie(k,0);
		cout << "角";
	}
	if (k != 0 && l == 0)
		cout << "整" << endl;
	if (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0) {
		if (k == 0 && l != 0) {
			if (x >= 1.01)
				daxie(0,1);
		}
	}

	if (l != 0) {
		daxie(l,0);
		cout << "分" << endl;
	}
	if (x == 0) {
		daxie(0,1);
		cout << "圆整" << endl;
	}

	return 0;
}