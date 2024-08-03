/*2353113 ��16 ����*/
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <cstring>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  �������ƣ�initial_visualize_without_frame
  ��    �ܣ���ʼͼ����ʾ��û�б߿�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void initial_visualize_without_frame(int hang, int lie, int table[][11], int display_repeated_or_not, int continuous)
{
	if (continuous == 0) {
		cout << "���س�����ʾͼ��..." << endl;
		while (_getch() != 13) {
			;
		}
		//if (_getch() == 13);
	}
	cct_cls();
	int repeat = 0;
	repeat = check_eliminated_or_not(hang, lie, table);
	if (repeat == 0)
		cout << "δ�ҵ���ʼ��������" << endl;
	cout << endl;
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int i = 1; i <= lie; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		Sleep(30);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	cout << endl;
	for (int i = 1; i <= hang; i++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_setcolor();

		for (int j = 1; j <= lie; j++) {
			cct_getxy(x, y);
			if (display_repeated_or_not == 1)
				cct_showstr(x, y, (judge_erasable_or_not(i, j, table) ? "��" : "��"), table[i][j], COLOR_BLACK, 1);
			else
				cct_showstr(x, y, "��", table[i][j], COLOR_BLACK, 1);

		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cout << endl;
		Sleep(30);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int j = 1; j <= lie; j++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		Sleep(30);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
	cout << endl;
	cct_setcolor();

}
/***************************************************************************
  �������ƣ�initial_visualize_with_frame
  ��    �ܣ���ʼͼ����ʾ���б߿�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void initial_visualize_with_frame(int hang, int lie, int table[][11], int display_repeated_or_not, int continuous)
{
	if (continuous == 0) {
		cout << "���س�����ʾͼ��..." << endl;
		while (_getch() != 13) {
			;
		}
	}
	cct_cls();
	cout << endl;
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int j = 1; j <= lie; j++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�j", COLOR_HWHITE, COLOR_BLACK, 1);
		Sleep(30);
	}
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
	cout << endl;
	for (int i = 1; i <= hang; i++) {

		for (int j = 1; j <= lie; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_getxy(x, y);
			if (display_repeated_or_not == 1)
				cct_showstr(x, y, (judge_erasable_or_not(i, j, table) ? "��" : "��"), table[i][j], COLOR_BLACK, 1);
			else
				cct_showstr(x, y, "��", table[i][j], COLOR_BLACK, 1);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
		cout << endl;
		cct_getxy(x, y);
		cct_showstr(x, y, "�d", COLOR_HWHITE, COLOR_BLACK, 1);
		for (int j = 1; j <= lie; j++) {
			cct_getxy(x, y);
			cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
			cct_getxy(x, y);
			cct_showstr(x, y, "�p", COLOR_HWHITE, COLOR_BLACK, 1);
		}
		cct_showstr(x, y, "�g", COLOR_HWHITE, COLOR_BLACK, 1);
		cout << endl;
	}
	cct_gotoxy(0, y);
	cct_getxy(x, y);
	cct_showstr(x, y, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
	for (int j = 1; j <= lie; j++) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�m", COLOR_HWHITE, COLOR_BLACK, 1);
	}
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
}
/***************************************************************************
  �������ƣ�visualize_prompt_items
  ��    �ܣ�ͼ�λ���ʾ��ʾ��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void visualize_prompt_items(int hang, int lie, int table[][11], int prompt_or_not[][11], int continuous)
{
	if (continuous == 0) {
		cct_gotoxy(0, 2 * hang + 3);
		cout << "���س�����ʾ��������ʾ��..." << endl;
		while (_getch() != 13) {
			;
		}
	}
	
	for (int i = 1; i <= hang; i++) {

		for (int j = 1; j <= lie; j++){
			cct_showstr(4 * j - 2, 2 * i, (prompt_or_not[i][j] ? "��" : "��"), table[i][j], COLOR_BLACK, 1);
		}
		
	}
}
/***************************************************************************
  �������ƣ�visualize_remove
  ��    �ܣ�ͼ�λ���ȥС��Ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void visualize_remove(int hang, int lie, int table[][11], int erasable_or_not[][11], int continuous, int& score, int conduct_by_my_self)
{
	if (continuous == 0) {
		cct_gotoxy(0, 2 * hang + 3);
		cout << "���س������������������0�Ĳ���..." << endl;
		while (_getch() != 13) {
			;
		}
	}

	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (erasable_or_not[i][j] == 1) {
				if (conduct_by_my_self)
					score++;
				for (int t = 1; t <= 5; t++) {
					cct_showstr(4 * j - 2, 2 * i, "��", table[i][j], COLOR_BLACK, 1);
					Sleep(50);
					cct_showstr(4 * j - 2, 2 * i, "��", table[i][j], COLOR_BLACK, 1);
					Sleep(50);
					cct_showstr(4 * j - 2, 2 * i, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
					//table[i][j] = 0;
				}
			}
		}
	}
	cct_setcolor();
	//drop(hang, lie, table, erasable_or_not);
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (erasable_or_not[i][j] == 1)
				table[i][j] = 0;
		}
	}
}

/***************************************************************************
  �������ƣ�visualize_remove
  ��    �ܣ�ͼ�λ���ȥС��Ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void visualize_ball_drop(int hang, int lie, int table[][11], int erasable_or_not[][11])
{
	int ret = 0;
	for (int j = 1; j <= lie; j++) {
		for (int t = 1; t <= 10; t++) {
			for (int i = hang - 1; i >= 1; i--) {
				if ((table[i][j] != 0) && (table[i + 1][j] == 0)) {
					for (; i <= hang - 1; i++) {
						if ((table[i][j] != 0) && (table[i + 1][j] == 0)) {
							cct_gotoxy(4 * j - 2, 2 * i);
							int x, y;
							cct_getxy(x, y);
							cct_showstr(x, y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
							cct_setcolor();
							Sleep(10);
							cct_showstr(x, y + 1, "��", table[i][j], COLOR_BLACK, 1);
							Sleep(10);
							cct_showstr(x, y + 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
							Sleep(10);
							cct_showstr(x, y + 2, "��", table[i][j], COLOR_BLACK, 1);

							Sleep(10);
							int t = table[i][j];
							table[i][j] = table[i + 1][j];
							table[i + 1][j] = t;
						}
					}
				}
			}
		}
	}



	/*int ret = 0;
	for (int j = 1; j <= lie; j++) {
		for (int t = 1; t <= 10; t++) {
			for (int i = 1; i <= hang - 1; i++) {
				if ((table[i][j] != 0) && (table[i + 1][j] == 0)) {
					cct_gotoxy(4 * j - 2, 2 * i);
					int x, y;
					cct_getxy(x, y);
					cct_showstr(x, y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
					cct_setcolor();
					Sleep(10);
					cct_showstr(x, y + 1, "��", table[i][j], COLOR_BLACK, 1);
					Sleep(10);
					cct_showstr(x, y + 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1);
					Sleep(10);
					cct_showstr(x, y + 2, "��", table[i][j], COLOR_BLACK, 1);

					Sleep(10);
					int t = table[i][j];
					table[i][j] = table[i + 1][j];
					table[i + 1][j] = t;
				}
			}
		}
	}*/
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�visualize_fill_balls
  ��    �ܣ�ͼ�λ�����µ�С��Ĺ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void visualize_fill_balls(int hang, int lie, int table[][11], int continuous)
{
	if (continuous == 0) {
		cct_gotoxy(0, 2 * hang + 3);
		cout << "                                    ";
		cct_gotoxy(0, 2 * hang + 3);
		cout << "���س���������ֵ���..." << endl;
		while (_getch() != 13) {
			;
		}
	}

	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (table[i][j] == 0) {
				table[i][j] = rand() % 9 + 1;
				cct_showstr(4 * j - 2, 2 * i, "��", table[i][j], COLOR_BLACK, 1);
				Sleep(200);
			}
		}
	}
	cct_setcolor();
}
/***************************************************************************
  �������ƣ�read_mouse
  ��    �ܣ����λ�ö�ȡ,����ʾ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void read_mouse(int hang, int lie, int table[][11], int prompt_or_not[][11])
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int hang_rn, lie_rn;
	cct_enable_mouse();
	while (loop) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {

			cct_gotoxy(0, 2 * hang + 3);
			hang_rn = (Y) / 2 + 64;
			lie_rn = (X + 2) / 4;
			if (((X % 4) > 1) && (Y % 2 == 0) && Y > 0 && Y <= 2 * hang && X <= 4 * lie - 2 + 1)
				cout << "[��ǰ���] " << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
			else
				cout << "[��ǰ���] λ�÷Ƿ�";
			//cout << "[��ǰ���] " << setw(2) << X << "��" << setw(2) << Y<< "��";

			switch (maction) {

				case MOUSE_LEFT_BUTTON_CLICK:			//�������
					//cout << "�������      " << endl;
					if (((X % 4) > 1) && (Y % 2 == 0) && Y > 0 && Y <= 2 * hang && X <= 4 * lie - 2 + 1) {
						if (prompt_or_not[Y / 2][X / 4 + 1]) {
							cct_gotoxy(0, 2 * hang + 3);
							cout << "                                ";
							cct_gotoxy(0, 2 * hang + 3);
							cout << "��ǰѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
							loop = 0;
						}
						else {
							cct_gotoxy(0, 2 * hang + 3);
							cout << "                                ";
							cct_gotoxy(0, 2 * hang + 3);
							cout << "����ѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
						}
					}			//�����ָ��λ����ʾ1
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
					//cout << "�����Ҽ�      " << endl;
					loop = 0;
					//cct_showch(X, Y, '3');			//�����ָ��λ����ʾ3
					break;
				case MOUSE_NO_ACTION:
				default:
					//�����ָ��λ����ʾ0
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)

	}
}
/***************************************************************************
  �������ƣ�visualize_repeated
  ��    �ܣ���ȥ��������ʾ��ʾ��������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void visualize_repeated(int hang, int lie, int table[][11], int erasable_or_not[][11])
{
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (erasable_or_not[i][j]) {
				cct_showstr(4 * j - 2, 2 * i, "��", table[i][j], COLOR_BLACK, 1);
			}
		}
	}
	cct_setcolor();
	Sleep(300);
}
/***************************************************************************
  �������ƣ�choose_with_mouse
  ��    �ܣ�ʹ�����ѡ�񼴽�������С��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void choose_with_mouse(int hang, int lie, int table[][11], int prompt_or_not[][11], int exchange[], int& x, int& y, int& quit_or_not)
{
	for (int i = 0; i < 4; i++)
		exchange[i] = 0;
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int hang_rn, lie_rn;
	cct_enable_mouse();

	while (loop) {
		/* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT) {

			cct_gotoxy(0, 2 * hang + 3);
			hang_rn = (Y) / 2 + 64;
			lie_rn = (X + 2) / 4;
			if (((X % 4) > 1) && (Y % 2 == 0) && Y > 0 && Y <= 2 * hang && X <= 4 * lie - 2 + 1){
				cout << "[��ǰ���] " << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";

				switch (maction) {

					case MOUSE_LEFT_BUTTON_CLICK:			//�������
						//cout << "�������      " << endl;
						if (((X % 4) > 1) && (Y % 2 == 0) && Y > 0 && Y <= 2 * hang && X <= 4 * lie - 2 + 1) {
							if (prompt_or_not[Y / 2][X / 4 + 1]) {
								cct_gotoxy(0, 2 * hang + 3);
								cout << "                                ";
								cct_gotoxy(0, 2 * hang + 3);
								cout << "��ǰѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
								x = hang_rn - 64;
								y = lie_rn;
								cct_showstr(4 * y - 2, 2 * x, "��", table[x][y], COLOR_HWHITE, 1);
								//exchange[t - 1] = hang_rn - 64;
								//exchange[t] = lie_rn;
								loop = 0;
							}
							else {
								cct_gotoxy(0, 2 * hang + 3);
								cout << "                                ";
								cct_gotoxy(0, 2 * hang + 3);
								cout << "����ѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
							}
						}			//�����ָ��λ����ʾ1
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
						//cout << "�����Ҽ�      " << endl;
						Sleep(500);
						loop = 0;
						quit_or_not = 1;
						//cct_showch(X, Y, '3');			//�����ָ��λ����ʾ3
						break;
					case MOUSE_NO_ACTION:
					default:
						//�����ָ��λ����ʾ0
						break;
				} //end of switch(maction)
			}
			else
				cout << "[��ǰ���] λ�÷Ƿ�";
			//cout << "[��ǰ���] " << setw(2) << X << "��" << setw(2) << Y<< "��";

			/*switch (maction) {

				case MOUSE_LEFT_BUTTON_CLICK:			//�������
					//cout << "�������      " << endl;
					if (((X % 4) > 1) && (Y % 2 == 0) && Y > 0 && Y <= 2 * hang && X <= 4 * lie - 2 + 1) {
						if (prompt_or_not[Y / 2][X / 4 + 1]) {
							cct_gotoxy(0, 2 * hang + 3);
							cout << "                                ";
							cct_gotoxy(0, 2 * hang + 3);
							cout << "��ǰѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
							x = hang_rn - 64;
							y = lie_rn;
							cct_showstr(4 * y - 2, 2 * x, "��", table[x][y], COLOR_HWHITE, 1);
							//exchange[t - 1] = hang_rn - 64;
							//exchange[t] = lie_rn;
							loop = 0;
						}
						else {
							cct_gotoxy(0, 2 * hang + 3);
							cout << "                                ";
							cct_gotoxy(0, 2 * hang + 3);
							cout << "����ѡ��" << setw(2) << char(hang_rn) << "��" << setw(2) << lie_rn << "��";
						}
					}			//�����ָ��λ����ʾ1
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
					//cout << "�����Ҽ�      " << endl;
					Sleep(500);
					loop = 0;
					quit_or_not = 1;
					//cct_showch(X, Y, '3');			//�����ָ��λ����ʾ3
					break;
				case MOUSE_NO_ACTION:
				default:
					//�����ָ��λ����ʾ0
					break;
			}*/ //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)

	}
	
	cct_setcolor();
}
/***************************************************************************
  �������ƣ�exchange_balls
  ��    �ܣ������ڲ���ͼ�λ�С�򽻻�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void exchange_balls(int x1, int y1, int x2, int y2, int table[][11])
{
	if(fabs(x1-x2)<=1|| fabs(y1 - y2) <= 1){
	    int t;
	    t = table[x1][y1];
	    table[x1][y1] = table[x2][y2];
	    table[x2][y2] = t;
		if(judge_erasable_or_not(x1,y1,table)|| judge_erasable_or_not(x2, y2, table))
	        cct_showstr(4 * y1 - 2, 2 * x1, "��", table[x1][y1], COLOR_BLACK, 1); 
		else {
			int t;
			t = table[x1][y1];
			table[x1][y1] = table[x2][y2];
			table[x2][y2] = t;
		}
	}  //�����x��y��������

	cct_setcolor();
}
/***************************************************************************
  �������ƣ�print_scores
  ��    �ܣ���ӡĿǰ�÷�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void print_scores(int score)
{
	cct_gotoxy(0, 0);
	cout << "��ǰ����:" << setw(3) << score;
}