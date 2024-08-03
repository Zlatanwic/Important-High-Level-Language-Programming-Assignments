/*2353113 信16 李阔*/
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
  函数名称：input
  功    能：负责行和列的输入
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void input(int& hang, int& lie)
{
	while (1) {
		cout << "请输入行数(5-9)：" << endl;
		cin >> hang;
		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (hang >= 5 && hang <= 9)
			break;
	}
	while (1) {
		cout << "请输入列数(5-9)：" << endl;
		cin >> lie;
		if (cin.fail() == 1) {
			cin.clear();
			cin.ignore(65535, '\n');
		}
		else if (lie >= 5 && lie <= 9)
			break;
	}
	cout << endl;
}
/***************************************************************************
  函数名称：initailize_table
  功    能：初始化数组内容
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void initailize_table(int hang, int lie, int table[][11])
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)(time(0)));
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			table[i][j] = rand() % 9 + 1;
		}
	}
}
/***************************************************************************
  函数名称：print_table
  功    能：打印非图形化表格
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_table(int hang, int lie, int table[][11])
{
	cout << "初始数组：" << endl;
	cout << "  | ";
	for (int t = 1; t <= lie; t++)
		cout << ' ' << t << ' ';
	cout << endl;
	cout << "--+-";
	for (int t = 1; t <= lie; t++)
		cout << "---";
	cout << endl;
	for (int i = 1; i <= hang; i++) {
		cout << char(i - 1 + 65) << " | ";
		for (int j = 1; j <= lie; j++) {
			cout << ' ' << table[i][j] << ' ';
		}
		cout << endl;
	}
}
/***************************************************************************
  函数名称：find_repeated_erasable_num
  功    能：寻找初始可消除项
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void find_repeated_erasable_num(const char str1[], const char str2[], int hang, int lie, int table[][11],int erasable_or_not[][11])
{

	cout << str1 << endl;
	if (_getch() == 13) {
		cout << str2 << endl;
		cout << "  | ";
		for (int t = 1; t <= lie; t++)
			cout << ' ' << t << ' ';
		cout << endl;
		cout << "--+-";
		for (int t = 1; t <= lie; t++)
			cout << "---";
		cout << endl;
		for (int i = 1; i <= hang; i++) {
			cout << char(i - 1 + 65) << " | ";
			for (int j = 1; j <= lie; j++) {
				if (erasable_or_not[i][j]==1) {
					cout << ' ';
					int x, y;
					cct_getxy(x, y);
					cct_showch(x, y, char(table[i][j] + 48), COLOR_HYELLOW, COLOR_WHITE, 1);
					cct_setcolor();
					cout << ' ';
					//table[i][j] = 0;
				}
				
				else {
					cout << ' ' << table[i][j] << ' ';
				}

			}
			cout << endl;
		}
	}
	cout << endl;
}
/***************************************************************************
  函数名称：print_prompt_items
  功    能：显示消除提示项
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_prompt_items(int hang, int lie, int table[][11], int prompt_or_not[][11])
{

	if (_getch() == 13) {
		cout << "可选择的消除提示（不同色标识）：" << endl;
		cout << "  | ";
		for (int t = 1; t <= lie; t++)
			cout << ' ' << t << ' ';
		cout << endl;
		cout << "--+-";
		for (int t = 1; t <= lie; t++)
			cout << "---";
		cout << endl;
		for (int i = 1; i <= hang; i++) {
			cout << char(i - 1 + 65) << " | ";
			for (int j = 1; j <= lie; j++) {
				if (prompt_or_not[i][j] == 1) {
					cout << ' ';
					int x = 0, y = 0;
					cct_getxy(x, y);
					cct_showch(x, y, char(table[i][j] + 48), COLOR_HYELLOW, COLOR_WHITE, 1);
					cct_setcolor();
					cout << ' ';
				}
				else {
					cout << ' ' << table[i][j] << ' ';
				}
				//cout << ' ' << table[i][j] << ' ';

				int x = 0, y = 0;



			}
			cout << endl;
		}
	}
	cout << endl;



}
/***************************************************************************
  函数名称：find_prompt_items
  功    能：查找消除提示项
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int find_prompt_items(int hang, int lie, int table[][11], int prompt_or_not[][11])
{
	for (int i = 1; i <= hang; i++)
		for (int j = 1; j <= lie; j++)
			prompt_or_not[i][j] = 0;
	int t = 0;
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (judge_prompt_or_not(i, j, table, prompt_or_not, 1) == 1) {
				prompt_or_not[i][j] = 1;
				prompt_or_not[i - 1][j] = 1;
				t++;
			}
			if (judge_prompt_or_not(i, j, table, prompt_or_not, 2) == 1) {
				prompt_or_not[i][j] = 1;
				prompt_or_not[i][j + 1] = 1;
				t++;
			}
			if (judge_prompt_or_not(i, j, table, prompt_or_not, 3) == 1) {
				prompt_or_not[i][j] = 1;
				prompt_or_not[i + 1][j] = 1;
				t++;
			}
			if (judge_prompt_or_not(i, j, table, prompt_or_not, 4) == 1) {
				prompt_or_not[i][j] = 1;
				prompt_or_not[i][j - 1] = 1;
				t++;
			}
		}
	}
	return t;
}
/***************************************************************************
  函数名称：judge_erasable_or_not
  功    能：判断数组该位置是初始可消除项
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int judge_erasable_or_not(int i, int j, int table[][11])
{
	if ((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
		(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j]))
		return 1;
	else
		return 0;
}
/***************************************************************************
  函数名称：make_erasable_array
  功    能：形成erasable数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void make_erasable_array(int hang, int lie, int table[][11], int erasable_or_not[][11])
{
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if ((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
				(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j]))
				erasable_or_not[i][j] = 1;
		}
	}
}

/***************************************************************************
  函数名称：drop
  功    能：进行数组下落的处理
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void drop(int hang,int lie,int table[][11],int erasable_or_not[][11])
{
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (erasable_or_not[i][j] == 1)
				table[i][j] = 0;
		}
	}
	int ret = 0;
	for (int j = 1; j <= lie; j++) {
		
		for (int t = 1; t <= 9;t++) {
			ret = 0;
			for(int i=1;i<=hang-1;i++){
				
				if (table[i][j] == 0 && (table[i - 1][j] != 0 ))
					ret++;
				if (table[i + 1][j] == 0){
					int t = table[i][j];
					table[i][j] = table[i + 1][j];
					table[i + 1][j] = t;
					
				}
			}
			//if (ret == 0)
				//break;
		}
	}
}
/***************************************************************************
  函数名称：fill_rand_num
  功    能：填充随机数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fill_rand_num(int hang, int lie, int table[][11])
{
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if (table[i][j] == 0)
				table[i][j] = rand() % 9 + 1;
		}
	}
}

/***************************************************************************
  函数名称：erasable_array_back_to_zero
  功    能：把记录是否作为初始可消除项的数组全部初始化为0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void erasable_array_back_to_zero(int erasable_or_not[][11])
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			erasable_or_not[i][j] = 0;
}