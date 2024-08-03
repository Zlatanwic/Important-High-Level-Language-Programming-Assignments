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
  函数名称：judge_prompt_or_not
  功    能：判断该处是否为显示提示项的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int judge_prompt_or_not(int i, int j, int table[][11], int light_or_not[][11],int direction)
{
	switch (direction) {
		case 1:
			int a;
			a = table[i][j];
			table[i][j] = table[i - 1][j];
			table[i - 1][j] = a;
			if (((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
				(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j]))&&table[i][j]!=0) {
				a = table[i][j];
				table[i][j] = table[i - 1][j];
				table[i - 1][j] = a;
				return 1;
			}
			else {
				a = table[i][j];
				table[i][j] = table[i - 1][j];
				table[i - 1][j] = a;
				return 0;
			}
			break;
		case 2:
			a = table[i][j];
			table[i][j] = table[i][j + 1];
			table[i][j + 1] = a;
			if (((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
				(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j])) && table[i][j] != 0) {
				a = table[i][j];
				table[i][j] = table[i][j + 1];
				table[i][j + 1] = a;
				return 1;
			}
			else {
				a = table[i][j];
				table[i][j] = table[i][j + 1];
				table[i][j + 1] = a;
				return 0;
			}
			break;
		case 3:
			a = table[i][j];
			table[i][j] = table[i + 1][j];
			table[i + 1][j] = a;
			if (((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
				(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j])) && table[i][j] != 0) {
				a = table[i][j];
				table[i][j] = table[i + 1][j];
				table[i + 1][j] = a;
				return 1;
			}
			else {
				a = table[i][j];
				table[i][j] = table[i + 1][j];
				table[i + 1][j] = a;
				return 0;
			}
			break;
		case 4:
			a = table[i][j];
			table[i][j] = table[i][j - 1];
			table[i][j - 1] = a;
			if (((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]) ||
				(table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j])) && table[i][j] != 0) {
				a = table[i][j];
				table[i][j] = table[i][j - 1];
				table[i][j - 1] = a;
				return 1;
			}
			else {
				a = table[i][j];
				table[i][j] = table[i][j - 1];
				table[i][j - 1] = a;
				return 0;
			}
			break;
		default:
			return 0;
	}
}
/***************************************************************************
  函数名称：check_eliminated_or_not
  功    能：先初步检查一下数组内是否有重复的
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int check_eliminated_or_not(int hang, int lie, int table[][11])
{
	int repeat = 0;
	for (int i = 1; i <= hang; i++) {
		for (int j = 1; j <= lie; j++) {
			if ((table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) || (table[i][j - 1] == table[i][j] && table[i][j] == table[i][j + 1]) || (table[i][j - 2] == table[i][j - 1] && table[i][j - 1] == table[i][j]))
				repeat++;
			else if ((table[i][j] == table[i + 1][j] && table[i + 1][j] == table[i + 2][j]) || (table[i - 1][j] == table[i][j] && table[i][j] == table[i + 1][j]) || (table[i - 2][j] == table[i - 1][j] && table[i - 1][j] == table[i][j]))
				repeat++;

		}
	}
	return repeat;
}
/***************************************************************************
  函数名称：back_to_menu
  功    能：一个项目执行结束后返回菜单
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void back_to_menu()
{
	cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	char str[256] = { 0 };

	/*while (1) {
		strcpy(str, "\0");
		cin.getline(str, 4, '\n');
		
		if (my_strcasecmp(str, "end") == 0)
			break;
		else {
			cout << endl << "输入错误，请重新输入";
			cct_gotoxy(x, y);
			cout << "              ";
			cct_gotoxy(x, y);
		}
	}*/

	while (1) {
		strcpy(str, "\0");
		for (int t = 0; t < 10; t++) {
			str[t] = _getche();
			if (str[t] == 13) {
				str[t] = '\0';
				break;
			}
		}
		if (my_strcasecmp(str, "end") == 0)
			break;
		else {
			cout << endl << "输入错误，请重新输入";
			cct_gotoxy(x, y);
			cout << "              ";
			cct_gotoxy(x, y);
		}
	}
}

/***************************************************************************
  函数名称：my_strcasecmp
  功    能：比较字符串大小，忽略英文大小写
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int my_strcasecmp(const char s1[], const char s2[])
{
	int dif, value1, value2;
	for (int i = 0; i < 256; i++) {
		value1 = int(s1[i]);
		value2 = int(s2[i]);
		if (s1[i] >= 65 && s1[i] <= 90)   //都把ASCII码转成小写字母
			value1 += 32;
		if (s2[i] >= 65 && s2[i] <= 90)
			value2 += 32;
		dif = value1 - value2;
		if (dif != 0 || (s1[i] == '\0' && s2[i] == '\0'))
			break;
	}
	return dif;
}
