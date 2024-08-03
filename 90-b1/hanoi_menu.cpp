/*2353113 信16 李阔*/
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放被 hanoi_main.cpp 调用的菜单函数，要求显示各菜单项，读入正确的选项后返回

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、不允许定义静态全局变量（全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：menu
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void menu() 
{
    while (1) {
        turn_zero();
        cct_cls();
        cout << "---------------------------------" << endl;
        cout << "1.基本解" << endl;
        cout << "2.基本解(步数记录)" << endl;
        cout << "3.内部数组显示(横向)" << endl;
        cout << "4.内部数组显示(纵向+横向)" << endl;
        cout << "5.图形解-预备-画三个圆柱" << endl;
        cout << "6.图形解-预备-在起始柱上画n个盘子" << endl;
        cout << "7.图形解-预备-第一次移动" << endl;
        cout << "8.图形解-自动移动版本" << endl;
        cout << "9.图形解-游戏版" << endl;
        cout << "0.退出" << endl;
        cout << "---------------------------------" << endl;
        int choice;
        cout << "[请选择:]";
        cout << endl;
        choice = _getch();
        if (choice == 49 || choice == 50 || choice == 51 || choice == 52 || choice == 56|| choice == 54|| choice == 55||choice==57) {
            int n;
            char src, tmp, dst;
            input(&n, &src, &tmp, &dst);
            
            switch (choice) {
                case 49:   //1
                    situation1(n, src, tmp, dst);
                    break;
                case 50:   //2
                    situation2(n, src, tmp, dst);
                    break;
                case 51:    //3
                    situation3(n, src, tmp, dst);
                    break;
                case 52:                //4
                    situation4(n, src, tmp, dst);
                    break;
                case 54:   //6
                    situation6(n, src, tmp, dst);
                    break;
                case 55:    //7
                    situation7(n, src, tmp, dst);
                    break;
                case 56:     //8
                    situation8(n, src, tmp, dst);
                    break;
                case 57:        //9
                    situation9(n, src, tmp, dst);
                    break;
            }
        }
        else if(choice==53 )  
            situation5();
        else if (choice == 48) 
            break;
    }
}
