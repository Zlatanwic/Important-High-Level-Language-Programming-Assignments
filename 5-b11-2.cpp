/*2353113 ��16 ����*/
#include <iostream>
#include <string>

//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�ʰ"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ�ת��д�ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
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
			//cout << "��";
			break;
		case 1:
			daxie = chnstr[2];
			daxie += chnstr[3];
			return daxie;
			//cout << "Ҽ";
			break;
		case 2:
			daxie = chnstr[4];
			daxie += chnstr[5];
			return daxie;
			//cout << "��";
			break;
		case 3:
			daxie = chnstr[6];
			daxie += chnstr[7];
			return daxie;
			//cout << "��";
			break;
		case 4:
			daxie = chnstr[8];
			daxie += chnstr[9];
			return daxie;
			//cout << "��";
			break;
		case 5:
			daxie = chnstr[10];
			daxie += chnstr[11];
			return daxie;
			//cout << "��";
			break;
		case 6:
			daxie = chnstr[12];
			daxie += chnstr[13];
			return daxie;
			//cout << "½";
			break;
		case 7:
			daxie = chnstr[14];
			daxie += chnstr[15];
			return daxie;
			//cout << "��";
			break;
		case 8:
			daxie = chnstr[16];
			daxie += chnstr[17];
			return daxie;
			//cout << "��";
			break;
		case 9:
			daxie = chnstr[18];
			daxie += chnstr[19];
			return daxie;
			//cout << "��";
			break;
		default:
			return "error";
			break;
	}

}
int main()
{
	/* --���������Ҫ������ --*/
	
	double a, e;
	while (1) {
        cout << "������[0-100��)֮�������:" << endl;
        cin >> a;   //����a�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (a >= 0 && a < 1e10)
			break;
	}
	
	
	cout << "��д�����:"<<endl;
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
		result += "Բ��";
	}
	else {
		result += daxie(w1, 0);
		if (w1 != 0)
			result += "ʰ";
		result += daxie(w2, 0);
		if (w2 != 0)
			result += "��";
		else if (w1 != 0)
			result += "��";
		result += daxie(w3, (w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))));
		if (w3 != 0)
			result += "Ǫ";
		result += daxie(w4, w3 != 0 && (w5 != 0 || w6 != 0));
		if (w4 != 0)
			result += "��";
		result += daxie(w5, w4 != 0 && w6 != 0);
		if (w5 != 0)
			result += "ʰ";
		result += daxie(w6, 0);
		if (w6 != 0)
			result += "��";
		else if (w3 != 0 || w4 != 0 || w5 != 0)
			result += "��";
		result += daxie(w7, (w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0));
		if (w7 != 0)
			result += "Ǫ";
		result += daxie(w8, w7 != 0 && (w9 != 0 || w10 != 0));
		if (w8 != 0)
			result += "��";
		result += daxie(w9, w8 != 0 && w10 != 0);
		if (w9 != 0)
			result += "ʰ";
		result += daxie(w10, 0);
		if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
			result += "Բ";
		if (w11 == 0 && w12 == 0) {
			if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
				result += "��";
		}
		else if (w12 == 0) {
			result += daxie(w11, 0);
			result += "����";
		}
		else {
			result += daxie(w11, !(w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0));
			if (w11 != 0)
				result += "��";
		}
		result += daxie(w12, 0);
		if (w12 != 0)
			result += "��";
	}
	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}