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
static int step;
static int num_of_each_column[3];
static int details_of_column[3][10];
static int v;
const int Y_MIN = 0;
/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

void turn_zero()
{
    step = 0;
    for (int i = 0; i < 3; i++) {
        num_of_each_column[i] = 0;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++)
            details_of_column[i][j] = 0;
    }
}

void input(int* n, char* src, char* tmp, char* dst)
{
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        if (cin.fail() || *n < 1 || *n>16) {
            cin.clear();
            cin.ignore(65535, '\n');
        }
        else if (*n >= 1 && *n <= 16) {
            cin.ignore(65535, '\n');
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        cin.ignore(65535, '\n');
        if (int(*src) >= 97)
            *src = char(int(*src) - 32);
        if (cin.fail()) {
            cin.clear();
        }
        else if (*src == 'A' || *src == 'B' || *src == 'C')
            break;
    }

    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        cin.ignore(65535, '\n');
        if (int(*dst) >= 97)
            *dst = char(int(*dst) - 32);
        if (cin.fail()) {
            cin.clear();
        }
        else if (*dst == 'A' || *dst == 'B' || *dst == 'C') {
            if (int(*dst) == int(*src) || int(*dst) == int(*src) + 32 || int(*dst) == int(*src) - 32)
                cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
            else
                break;
        }
    }
    if ((*src == 'A') && (*dst == 'C') || (*src == 'C') && (*dst == 'A'))
        *tmp = 'B';
    if ((*src == 'A') && (*dst == 'B') || (*src == 'B') && (*dst == 'A'))
        *tmp = 'C';
    if ((*src == 'B') && (*dst == 'C') || (*src == 'C') && (*dst == 'B'))
        *tmp = 'A';
    if (*src == 'A') {
        num_of_each_column[0] = *n;
        for (int i = 0; i < 10; i++) {
            details_of_column[0][i] = (*n - i);
        }
    }
    if (*src == 'B') {
        num_of_each_column[1] = *n;
        for (int i = 0; i < 10; i++) {
            details_of_column[1][i] = (*n - i);
        }
    }
    if (*src == 'C') {
        num_of_each_column[2] = *n;
        for (int i = 0; i < 10; i++) {
            details_of_column[2][i] = (*n - i);
        }
    }
}
/***************************************************************************
     函数名称：to_be_continued
     功    能：等待结束重返菜单
     输入参数：
     返 回 值：
     说    明：
***************************************************************************/
void to_be_continued()
{
    cct_setcolor(); //恢复缺省颜色
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "按回车键继续...";

    /* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
    while (_getch() != '\r')
        ;
    cct_cls();
    return;
}
/***************************************************************************
     函数名称：print_process
     功    能：打印横向的汉诺塔移动过程
     输入参数：表示哪个柱(A,B,C)
     返 回 值：
     说    明：
***************************************************************************/
void print_process(char a) {
    cout << ' ' << a << ':';
    for (int i = 0; i < 10; i++) {
        if (details_of_column[int(a) - 65][i] > 0)
            cout << ' ' << details_of_column[int(a) - 65][i];
        else
            cout << "  ";
    }
}
/***************************************************************************
  函数名称：assist_counting
  功    能：在横向或纵向演示时，负责记录各个柱的具体情况
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void assist_counting(int n, int details_of_column[][10], int num_of_each_column[], char src, char dst, int game_or_not) {
    step++;
    int t = details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1];
    details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1] = 0;
    num_of_each_column[int(src) - 65]--;
    if (game_or_not == 0)
        details_of_column[int(dst) - 65][num_of_each_column[int(dst) - 65]] = n;
    else
        details_of_column[int(dst) - 65][num_of_each_column[int(dst) - 65]] = t;
    num_of_each_column[int(dst) - 65]++;

}
/***************************************************************************
  函数名称：print_pattern
  功    能：打印纵向汉诺塔的图形
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_pattern(char a, int Y) {
    cct_gotoxy((int(a) - 65) * 10 + 7, Y - 1);
    for (int i = 0; i < 10; i++) {

        if (details_of_column[(int)(a)-65][i] > 0) {
            cct_gotoxy((int(a) - 65) * 10 + 7, Y - 1 - i);
            cout << details_of_column[(int)(a)-65][i];
            // printf("%d", column0[i]);
        }
        else {
            cct_gotoxy((int(a) - 65) * 10 + 7, Y - 1 - i);
            cout << char(32);
        }
    }
}
/***************************************************************************
  函数名称：horizontal_initial_print
  功    能：负责横向输出的初始话打印
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void horizontal_initial_print(int n, char src, int Y, int vertical_or_not)
{

    if (vertical_or_not == 1) {
        cct_gotoxy(30, Y);
    }
    cout << "初始:               ";
    for (int i = 0; i < 3; i++) {
        cout << " " << char(65 + i) << ':';
        if (src == char(65 + i)) {
            for (int i = n; i > 0; i--) {
                cout << " " << i;
            }
            for (int i = n; i < 10; i++) {
                cout << "  ";
            }
        }
        else
            cout << "                    ";
    }
}

/***************************************************************************
  函数名称：vertial_initial_print
  功    能：纵向输出的初始化打印
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void vertial_initial_print(int n, char src, int Y)
{
    cct_gotoxy(5, Y);
    cout << "=========================";
    cct_gotoxy(5, Y + 1);
    cout << "  A         B         C  ";
    if (src == 'A') {
        cct_gotoxy(7, Y - n);
        for (int i = 1; i <= n; i++) {
            cout << i;
            cct_gotoxy(7, Y - n + i);
        }
    }
    else if (src == 'B') {
        cct_gotoxy(7 + 10, Y - n);
        for (int i = 1; i <= n; i++) {
            cout << i;
            cct_gotoxy(7 + 10, Y - n + i);
        }
    }
    else if (src == 'C') {
        cct_gotoxy(7 + 20, Y - n);
        for (int i = 1; i <= n; i++) {
            cout << i;
            cct_gotoxy(7 + 20, Y - n + i);
        }
    }
}
/***************************************************************************
  函数名称：print_totally
  功    能：整合了真正打印屏幕输出的关键步骤的语句
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void print_totally(int n, char src, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not, int X, int Y, int game_or_not)
{
    if (vertical_or_not == 0) {
        if (step_or_not > 0) {
            if (horizontal_or_not > 0)
                cout << "第" << setw(4) << step << " 步(" << setw(2) << n << "):" << " " << src << "-->" << dst;
            else
                cout << "第" << setw(4) << step << " 步(" << setw(2) << n << "):" << " " << src << "-->" << dst << endl;
        }
        else
            cout << setw(2) << n << "#" << " " << src << "-->" << dst << endl;

        if (horizontal_or_not > 0) {
            print_process('A');
            print_process('B');
            print_process('C');
            cout << endl;
        }
    }
    else {
        switch (v) {
            case 0:
                if (_getch() == 13) {
                    cct_gotoxy(X, Y);
                    if (game_or_not == 0)
                        cout << "第" << setw(4) << step << " 步(" << setw(2) << n << "): " << src << "-->" << dst;

                    print_process('A');
                    print_process('B');
                    print_process('C');
                    print_pattern('A', Y);
                    print_pattern('B', Y);
                    print_pattern('C', Y);
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                Sleep(2000 - v * 390);
                cct_gotoxy(X, Y);
                if (game_or_not == 0)
                    cout << "第" << setw(4) << step << " 步(" << setw(2) << n << "): " << src << "-->" << dst;

                print_process('A');
                print_process('B');
                print_process('C');

                print_pattern('A', Y);
                print_pattern('B', Y);
                print_pattern('C', Y);
        }
    }
}
/***************************************************************************
  函数名称：draw_column
  功    能：画出三个柱子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_column()
{
    const int Y = 15;
    const int bg_color = COLOR_HYELLOW;	//背景为亮黄色
    const int fg_color = COLOR_HBLUE;		//前景为亮蓝色
    const char ch = ' ';        //字符为*(注意：如果是空格，则前景色无法显示)
    const int LENGTH = 10;
    int x;
    for (x = 1; x <= 23; x++) {
        cct_showch(x, Y, ch, bg_color, fg_color, 1);
        Sleep(10);
    }
    for (x = 33; x <= 33 + 22; x++) {
        cct_showch(x, Y, ch, bg_color, fg_color, 1);
        Sleep(10);
    }
    for (x = 65; x <= 65 + 22; x++) {
        cct_showch(x, Y, ch, bg_color, fg_color, 1);
        Sleep(10);
    }
    const int X = 12;
    int y;
    for (y = 14; y > 2; y--) {
        /* 在坐标(x,2)位置处连续打印10个字符 */
        cct_showch(12, y, ch, bg_color, fg_color, 1);
        cct_showch(44, y, ch, bg_color, fg_color, 1);
        cct_showch(65 + 11, y, ch, bg_color, fg_color, 1);
        /* 延时0.3秒 */
        Sleep(50);

    }
    cct_setcolor();
}
/***************************************************************************
  函数名称：draw_plate
  功    能：画初始盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void draw_plate(int n, char src, char dst)
{
    int x1 = 32 * (int(src) - 65) + 12 - n;
    int x2 = 32 * (int(src) - 65) + 12 + n;
    const char ch = ' ';
    int i = 1;
    int x;
    for (i = 1; i <= n; i++) {
        for (x = x1; x <= x2; x++) {
            cct_showch(x, 14 + 1 - i, ch, n + 1 - i, n + 1 - i, 1);
            Sleep(25);
        }
        x1++;
        x2--;
    }
    cct_setcolor();
}
/***************************************************************************
  函数名称：move_plate
  功    能：移动盘子
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void move_one_plate(int n, char src, char tmp, char dst, int game_or_not)
{
    if (game_or_not == 0)
        if (n % 2 == 0)
            dst = tmp;
    int x0 = (32 * (int(src) - 65) + 12 - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int y0 = 15 - num_of_each_column[int(src) - 65];
    int m = 1 + 2 * (details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int color = details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1];                      //n - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1] + 1;//表示该编号的盘子对应的颜色号
    int x1 = (32 * (int(dst) - 65) + 12 - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int y1 = 15 - num_of_each_column[int(dst) - 65] - 1;
    if (game_or_not == 1) {
        assist_counting(n, details_of_column, num_of_each_column, src, dst, 1);
        print_totally(n, src, dst, 1, 1, 1, 0, 51, 30, game_or_not);
        cct_gotoxy(30, 30);
        cout << "         ";
    }
    for (int y = y0; y > Y_MIN; y--) {
        cct_showstr(x0, y, " ", color, color, m, -1);
        Sleep(100);
        if (y > Y_MIN + 1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x0, y, ' ', 0, 0, m);
            if (y >= 3)
                cct_showch(32 * (int(src) - 65) + 12, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        }
    }

    if (int(dst) > int(src)) {
        for (int x = x0; x <= x1; x++) {
            cct_showch(x, 1, ' ', color, color, m);
            Sleep(100);
            if (x < x1) {
                cct_showch(x, 1, ' ', 0, 0, 1);
            }
        }
    }
    else {
        for (int x = x0; x >= x1; x--) {
            cct_showch(x, 1, ' ', color, color, m);
            Sleep(100);
            if (x > x1) {
                cct_showch(x + m - 1, 1, ' ', 0, 0, 1);
            }
        }
    }
    for (int y = 1; y <= y1; y++) {
        cct_showstr(x1, y, " ", color, color, m, -1);
        Sleep(100);
        if (y < y1) {
            /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
            cct_showch(x1, y, ' ', 0, 0, m);
            if (y >= 3)
                cct_showch(32 * (int(dst) - 65) + 12, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        }
    }
    cct_setcolor();
}
/***************************************************************************
  函数名称：Integrated output
  功    能：综合输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void Integrated_output(int n, char src, char tmp, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not, int X, int Y)
{
    int x0 = (32 * (int(src) - 65) + 12 - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int y0 = 15 - num_of_each_column[int(src) - 65];
    int m = 1 + 2 * (details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int color = details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1];                      //n - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1] + 1;//表示该编号的盘子对应的颜色号
    int x1 = (32 * (int(dst) - 65) + 12 - details_of_column[int(src) - 65][num_of_each_column[int(src) - 65] - 1]);
    int y1 = 15 - num_of_each_column[int(dst) - 65] - 1;

    assist_counting(n, details_of_column, num_of_each_column, src, dst, 0);
    print_totally(n, src, dst, step_or_not, horizontal_or_not, vertical_or_not, automove_or_not, X, Y, 0);
    if (automove_or_not == 1) {
        for (int y = y0; y > Y_MIN; y--) {
            cct_showstr(x0, y, " ", color, color, m, -1);
            Sleep(100);
            if (y > Y_MIN + 1) {
                /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                cct_showch(x0, y, ' ', 0, 0, m);
                if (y >= 3)
                    cct_showch(32 * (int(src) - 65) + 12, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
            }
        }
        if (int(dst) > int(src)) {
            for (int x = x0; x <= x1; x++) {
                cct_showch(x, 1, ' ', color, color, m);
                Sleep(100);
                if (x < x1) {
                    cct_showch(x, 1, ' ', 0, 0, 1);
                }
            }
        }
        else {
            for (int x = x0; x >= x1; x--) {
                cct_showch(x, 1, ' ', color, color, m);
                Sleep(100);
                if (x > x1) {
                    cct_showch(x + m - 1, 1, ' ', 0, 0, 1);
                }
            }
        }
        for (int y = 1; y <= y1; y++) {
            cct_showstr(x1, y, " ", color, color, m, -1);
            Sleep(100);
            if (y < y1) {
                /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                cct_showch(x1, y, ' ', 0, 0, m);
                if (y >= 3)
                    cct_showch(32 * (int(dst) - 65) + 12, y, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
            }
        }
        cct_setcolor();
    }
}
/***************************************************************************
  函数名称：hanoi_game
  功    能：汉诺塔小游戏
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_game(int n, char src, char dst)
{
    vertial_initial_print(n, src, 30);
    horizontal_initial_print(n, src, 30, 1);
    cct_gotoxy(0, 35);
    cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
    int x = 61, y = 35;
    int m = 0;
    char input[10] = { 0 };
    while (1) {
        while (1) {
            cct_gotoxy(x, y);
            for (int i = 0; i < 3; i++) {
                input[i] = 0;
            }
            for (int i = 0; i < 2; i++) {
                input[i] = _getche();
                if (int(input[i]) == 13)
                    break;
            }
            if (int(input[0]) > 96)
                input[0] = char(int(input[0]) - 32);
            if (int(input[1]) > 96)
                input[1] = char(int(input[1]) - 32);
            if (input[0] == 'Q' || input[0] == 'q') {
                m = 1;
                break;
            }
            int a = details_of_column[int(input[0]) - 65][num_of_each_column[int(input[0]) - 65] - 1];
            int b = details_of_column[int(input[1]) - 65][num_of_each_column[int(input[1]) - 65] - 1];
            if (num_of_each_column[int(input[0]) - 65] == 0) {
                cout << endl;
                cout << "源柱为空!";
                Sleep(2000);
                cct_gotoxy(0, y + 1);
                cout << "                      ";
                cct_gotoxy(x, y);
                cout << "                      ";
                continue;
            }
            else if (num_of_each_column[input[1] - 65] == 0)
                break;
            else if ((a > b) && (b > 0)) {
                cout << endl << "大盘压小盘，非法移动!";
                Sleep(2000);
                cct_gotoxy(0, y + 1);
                cout << "                      ";
                cct_gotoxy(x, y);
                cout << "                      ";
                continue;
            }
            else if (a < b || b == 0) {
                break;
            }
        }
        if (input[0] == 'A' && input[1] == 'B')
            move_one_plate(n, 'A', 'C', 'B', 1);
        if (input[0] == 'A' && input[1] == 'C')
            move_one_plate(n, 'A', 'B', 'C', 1);
        if (input[0] == 'B' && input[1] == 'C')
            move_one_plate(n, 'B', 'A', 'C', 1);
        if (input[0] == 'B' && input[1] == 'A')
            move_one_plate(n, 'B', 'C', 'A', 1);
        if (input[0] == 'C' && input[1] == 'A')
            move_one_plate(n, 'C', 'B', 'A', 1);
        if (input[0] == 'C' && input[1] == 'B')
            move_one_plate(n, 'C', 'A', 'B', 1);
        if (m == 1)
            break;
        if (num_of_each_column[int(dst) - 65] == n)
            break;
        cct_setcolor();
        cct_gotoxy(x, y);
        cout << "                      ";
    }
    if (m == 1) {
        cct_gotoxy(x, y);
        cout << endl << "你选择退出，游戏中止";
    }
    else {
        cct_gotoxy(x, y);
        cout << endl << "你成功了，游戏结束!!!";
    }
    if (_getch() == 13)
        cout << endl;
}
/***************************************************************************
  函数名称：hanoi_solution
  功    能：递归函数综合计算汉诺塔的解
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_solution(int n, char src, char tmp, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not, int X, int Y)
{
    if (n == 1) 
        Integrated_output(n, src, tmp, dst, step_or_not, horizontal_or_not, vertical_or_not, automove_or_not, X, Y);
    else {
        hanoi_solution(n - 1, src, dst, tmp, step_or_not, horizontal_or_not, vertical_or_not, automove_or_not, X, Y);
        Integrated_output(n, src, tmp, dst, step_or_not, horizontal_or_not, vertical_or_not, automove_or_not, X, Y);
        hanoi_solution(n - 1, tmp, src, dst, step_or_not, horizontal_or_not, vertical_or_not, automove_or_not, X, Y);
    }
}

void situation1(int n, char src, char tmp, char dst)
{
    hanoi_solution(n, src, tmp, dst, 0, 0, 0, 0, 0, 0);
    to_be_continued();
}
void situation2(int n, char src, char tmp, char dst)
{
    hanoi_solution(n, src, tmp, dst, 1, 0, 0, 0, 0, 0);
    to_be_continued();
}
void situation3(int n, char src, char tmp, char dst)
{
    horizontal_initial_print(n, src, 30, 0);
    cout << endl;
    hanoi_solution(n, src, tmp, dst, 1, 1, 0, 0, 0, 0);
    to_be_continued();
}
void situation4(int n, char src, char tmp, char dst)
{
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> v;
    cct_cls();
    vertial_initial_print(n, src, 20);
    horizontal_initial_print(n, src, 20, 1);
    hanoi_solution(n, src, tmp, dst, 1, 1, 1, 0, 30, 20);
    to_be_continued();
}
void situation5()
{
    cct_cls();
    draw_column();
    cct_gotoxy(0, 20);
    to_be_continued();
}
void situation6(int n, char src, char tmp, char dst)
{
    cct_cls();
    draw_column();
    draw_plate(n, src, dst);
    cct_gotoxy(0, 20);
    to_be_continued();
}
void situation7(int n, char src, char tmp, char dst)
{
    cct_cls();
    draw_column();
    draw_plate(n, src, dst);
    move_one_plate(n, src, tmp, dst, 0);
    cct_gotoxy(0, 20);
    to_be_continued();
}
void situation8(int n, char src, char tmp, char dst)
{
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    cin >> v;
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << "，延时设置为" << v;
    vertial_initial_print(n, src, 30);
    horizontal_initial_print(n, src, 30, 1);
    draw_column();
    draw_plate(n, src, dst);
    hanoi_solution(n, src, tmp, dst, 1, 1, 1, 1, 30, 30);
    cct_gotoxy(0, 35);
    to_be_continued();
}
void situation9(int n, char src, char tmp, char dst)
{
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共" << n << "层";
    draw_column();
    draw_plate(n, src, dst);
    hanoi_game(n, src, dst);
    to_be_continued();
}
