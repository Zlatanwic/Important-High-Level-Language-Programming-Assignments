/*2353113 ��16 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�ʰ"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void daxie(int num, int flag_of_zero,char result[])
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero) {
				strncat(result, chnstr,2);
			}
			break;
		case 1:
			strncat(result, &chnstr[2],2);
			break;
		case 2:
			strncat(result, &chnstr[4],2);
			break;
		case 3:
			strncat(result, &chnstr[6],2);
			break;
		case 4:
			strncat(result, &chnstr[8],2);
			break;
		case 5:
			strncat(result, &chnstr[10],2);
			break;
		case 6:
			strncat(result, &chnstr[12],2);
			break;
		case 7:
			strncat(result, &chnstr[14],2);
			break;
		case 8:
			strncat(result, &chnstr[16],2);
			break;
		case 9:
			strncat(result, &chnstr[18],2);
			break;
		default:
			printf("error");
			break;
	}
}

int main()
{
    /* --���������Ҫ������ --*/
	double a, e;
	int ret;
	while (1) {
		printf("������[0-100��)֮�������:\n");
        ret=scanf("%lf", &a);   //����a�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
		if (ret == 0)
			while (getchar() != '\n')
				;
		else if (a >= 0 && a < 1e10)
			break;
	}
	printf("��д�����:\n");
	int  w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12;
	e = a + 0.001;
	int b = (int)(e / 10);
	w1 = (int)(b / 1e8);
	w2 = (int)((b - w1 * 1e8) / 1e7);
	w3 = (int)((b - w1 * 1e8 - w2 * 1e7) / 1e6);
	w4 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6) / 1e5);
	w5 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5) / 1e4);
	w6 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4) / 1e3);
	w7 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3) / 1e2);
	w8 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2) / 1e1);
	w9 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2 - w8 * 1e1) / 1);
	double c = e / 10 - b;
	int d = (int)(1000 * c);
	w10 = d / 100;
	w11 = (d - w10 * 100) / 10;
	w12 = (d - w10 * 100 - w11 * 10) / 1;

	if (a == 0) {
		daxie((int)(a), 1,result);
		strcat(result, "Բ��");
	}
	else {
		daxie(w1, 0, result);
		if (w1 != 0)
			strcat(result, "ʰ");
		daxie(w2, 0, result);
		if (w2 != 0)
			strcat(result, "��");
		else if (w1 != 0)
			strcat(result, "��");
		daxie(w3, (w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))), result);
		if (w3 != 0)
			strcat(result, "Ǫ");
		daxie(w4, w3 != 0 && (w5 != 0 || w6 != 0), result);
		if (w4 != 0)
			strcat(result, "��");
		daxie(w5, w4 != 0 && w6 != 0, result);
		if (w5 != 0)
			strcat(result, "ʰ");
		daxie(w6, 0, result);
		if (w6 != 0)
			strcat(result, "��");
		else if (w3 != 0 || w4 != 0 || w5 != 0)
			strcat(result, "��");
		daxie(w7, (w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0), result);
		if (w7 != 0)
			strcat(result, "Ǫ");
		daxie(w8, w7 != 0 && (w9 != 0 || w10 != 0), result);
		if (w8 != 0)
			strcat(result, "��");
		daxie(w9, w8 != 0 && w10 != 0, result);
		if (w9 != 0)
			strcat(result, "ʰ");
		daxie(w10, 0, result);
		if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
			strcat(result, "Բ");
		if (w11 == 0 && w12 == 0) {
			if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
				strcat(result, "��");
		}
		else if (w12 == 0) {
			daxie(w11, 0, result);
			strcat(result, "����");
		}
		else {
			daxie(w11, !(w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0), result);
			if (w11 != 0)
				strcat(result, "��");
		}
		daxie(w12, 0, result);
		if (w12 != 0)
			strcat(result, "��");
	}

    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
