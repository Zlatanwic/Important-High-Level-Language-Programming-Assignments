/*2353113 信16 李阔*/
#include <iostream>
#include <string>

//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖拾"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：daxie
  功    能：转大写的函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

string daxie(int num, int flag_of_zero)
{
	string daxie ;
	switch (num) {
		case 0:
			if (flag_of_zero) {
				daxie = chnstr[0];
				daxie += chnstr[1];
				return daxie;
			}
			else
				return "";
			//cout << "零";
			break;
		case 1:
			daxie = chnstr[2];
			daxie += chnstr[3];
			return daxie;
			//cout << "壹";
			break;
		case 2:
			daxie = chnstr[4];
			daxie += chnstr[5];
			return daxie;
			//cout << "贰";
			break;
		case 3:
			daxie = chnstr[6];
			daxie += chnstr[7];
			return daxie;
			//cout << "叁";
			break;
		case 4:
			daxie = chnstr[8];
			daxie += chnstr[9];
			return daxie;
			//cout << "肆";
			break;
		case 5:
			daxie = chnstr[10];
			daxie += chnstr[11];
			return daxie;
			//cout << "伍";
			break;
		case 6:
			daxie = chnstr[12];
			daxie += chnstr[13];
			return daxie;
			//cout << "陆";
			break;
		case 7:
			daxie = chnstr[14];
			daxie += chnstr[15];
			return daxie;
			//cout << "柒";
			break;
		case 8:
			daxie = chnstr[16];
			daxie += chnstr[17];
			return daxie;
			//cout << "捌";
			break;
		case 9:
			daxie = chnstr[18];
			daxie += chnstr[19];
			return daxie;
			//cout << "玖";
			break;
		default:
			return "error";
			break;
	}

}
int main()
{
	/* --允许添加需要的内容 --*/
	
	double a, e;
	while (1) {
        cout << "请输入[0-100亿)之间的数字:" << endl;
        cin >> a;   //读入a的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (a >= 0 && a < 1e10)
			break;
	}
	
	
	cout << "大写结果是:"<<endl;
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

	if (a == 0) {
		result += daxie(int(a), 1);
		result += "圆整";
	}
	else {
		result += daxie(w1, 0);
		if (w1 != 0)
			result += "拾";
		result += daxie(w2, 0);
		if (w2 != 0)
			result += "亿";
		else if (w1 != 0)
			result += "亿";
		result += daxie(w3, (w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))));
		if (w3 != 0)
			result += "仟";
		result += daxie(w4, w3 != 0 && (w5 != 0 || w6 != 0));
		if (w4 != 0)
			result += "佰";
		result += daxie(w5, w4 != 0 && w6 != 0);
		if (w5 != 0)
			result += "拾";
		result += daxie(w6, 0);
		if (w6 != 0)
			result += "万";
		else if (w3 != 0 || w4 != 0 || w5 != 0)
			result += "万";
		result += daxie(w7, (w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0));
		if (w7 != 0)
			result += "仟";
		result += daxie(w8, w7 != 0 && (w9 != 0 || w10 != 0));
		if (w8 != 0)
			result += "佰";
		result += daxie(w9, w8 != 0 && w10 != 0);
		if (w9 != 0)
			result += "拾";
		result += daxie(w10, 0);
		if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
			result += "圆";
		if (w11 == 0 && w12 == 0) {
			if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
				result += "整";
		}
		else if (w12 == 0) {
			result += daxie(w11, 0);
			result += "角整";
		}
		else {
			result += daxie(w11, !(w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0));
			if (w11 != 0)
				result += "角";
		}
		result += daxie(w12, 0);
		if (w12 != 0)
			result += "分";
	}
	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}