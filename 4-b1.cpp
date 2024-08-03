/*2353113 信16 李阔*/
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

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

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a, e;
	
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;   //读入a的方式必须是 cin>>int型变量，不允许其他方式
	cout << "大写结果是:" << endl;
	int  w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12;
	e = a + 0.001;
	int b = int(e / 10);
	w1 = int(b / 1e8);
	w2 = int((b - w1 * 1e8) / 1e7);
	w3 = int((b - w1 * 1e8 - w2 * 1e7) / 1e6);
	w4 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6) / 1e5);
	w5 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5) / 1e4);
	w6 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4) / 1e3);
	w7 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3) / 1e2);
	w8 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2) / 1e1);
	w9 = int((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2 - w8 * 1e1) / 1);
	double c = e / 10 - b;
	int d = int(1000 * c);
	w10 = d / 100;
	w11 = (d - w10 * 100) / 10;
	w12 = (d - w10 * 100 - w11 * 10) / 1;
	
	if (int(a)== 0) {
		daxie(int(a), 1);
		cout << "圆整";
	}
	else {
		daxie(w1, 0);
		if(w1!=0)
			cout << "拾";
		daxie(w2, 0);
		if(w2!=0)
			cout << "亿";
		else if (w1 != 0 )
			cout << "亿";
		daxie(w3, (w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))));
		if(w3!=0)
			cout << "仟";
		daxie(w4, w3 != 0 && (w5 != 0 || w6 != 0));
		if(w4!=0)
			cout << "佰";
		daxie(w5, w4 != 0 && w6 != 0);
		if(w5!=0)
			cout << "拾";
		daxie(w6, 0);
		if(w6!=0)
			cout << "万";
		else if (w3 != 0 || w4 != 0 || w5 != 0)
			cout << "万";
		daxie(w7, (w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0));
		if(w7!=0)
            cout << "仟";
		daxie(w8, w7 != 0 && (w9 != 0 || w10 != 0));
		if(w8!=0)
			cout << "佰";
		daxie(w9, w8 != 0 && w10 != 0);
		if(w9!=0)
			cout << "拾";
		daxie(w10, 0);
		if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
			cout << "圆";
		if (w11 == 0 && w12 == 0) {
			if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
				cout << "整";
		}
		else if (w12 == 0) {
			daxie(w11, 0);
			cout << "角整";
		}
		else {
			daxie(w11, !(w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0));
			if (w11 != 0)
				cout << "角";
		}
		daxie(w12, 0);
		if (w12 != 0)
			cout << "分";
	}

	cout << "\n";
	return 0;
}