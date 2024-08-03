/*2353113 信16 李阔*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度


/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
int menu() {
	int choice;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止)(按左箭头不向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕)(按左箭头不向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	choice = _getch();
	return choice;
}
/***************************************************************************
函数名称：move_by_ijkl
功    能：通过ijkl键来移动光标
输入参数：circling，是否回绕
返 回 值：
说    明：
***************************************************************************/
void move_by_ijkl(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	// 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	// 显示初始的边框及其中的随机字符 */
	init_border(hout);
	gotoxy(hout, 35, 9);
	int x = 35, y = 9;
	while (1) {
		int movement = _getch();
		if (movement == 105 || movement == 73) {
			switch (circling) {
				case 0:
					if (y > 1) {          //i
						y--;
						gotoxy(hout, x, y);
					}
					break;
				case 1:
					if (y > 1) {
						y--;
						gotoxy(hout, x, y);
					}
					else {
						y = 17;
						gotoxy(hout, x, y);
					}
					break;
			}
		}
		else if (movement == 107 || movement == 75) {//k
			switch (circling) {
				case 0:
					if (y < 17) {
						y++;
						gotoxy(hout, x, y);
					}
					break;
				case 1:
					if (y < 17) {
						y++;
						gotoxy(hout, x, y);
					}
					else {
						y = 1;
						gotoxy(hout, x, y);
					}
					break;
			}
		}
		else if (movement == 74 || movement == 106) {
			//j
			switch (circling) {
				case 0:
					if (x > 1) {          //i
						x--;
						gotoxy(hout, x, y);
					}
					break;
				case 1:
					if (x > 1) {
						x--;
						gotoxy(hout, x, y);
					}
					else {
						x = 69;
						gotoxy(hout, x, y);
					}
					break;
			}
		}
		else if (movement == 108 || movement == 76) {
			//L
			switch (circling) {
				case 0:
					if (x < 69) {
						x++;
						gotoxy(hout, x, y);
					}
					break;
				case 1:
					if (x < 69) {
						x++;
						gotoxy(hout, x, y);
					}
					else {
						x = 1;
						gotoxy(hout, x, y);
					}
					break;
			}
		}
		else if (movement == 32) {
			cout << char(32);
			gotoxy(hout, x, y);
		}
		else if (movement == 81 || movement == 113)
			break;

	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	//gotoxy(hout, x, 23);
	y = 23;

	while (_getch() != 13) {
		;
	}
}
/***************************************************************************
函数名称：move_by_arrow
功    能：通过方向键来移动光标
输入参数：circling，是否回绕
返 回 值：
说    明：
***************************************************************************/
void move_by_arrow(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	// 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	// 显示初始的边框及其中的随机字符 */
	init_border(hout);
	gotoxy(hout, 35, 9);
	int x = 35, y = 9;
	int movement1, movement2;
	while (1) {
		movement1 = _getch();
		if (movement1 == 224) {
			movement2 = _getch();
			switch (movement2) {
				case 72:
					switch (circling) {
						case 0:
							if (y > 1) {          //i
								y--;
								gotoxy(hout, x, y);
							}
							else
								;
							break;
						case 1:
							if (y > 1) {
								y--;
								gotoxy(hout, x, y);
							}
							else {
								y = 17;
								gotoxy(hout, x, y);
							}
					}
					break;
				case 80:  //k
					switch (circling) {
						case 0:
							if (y < 17) {
								y++;
								gotoxy(hout, x, y);
							}
							break;
						case 1:
							if (y < 17) {
								y++;
								gotoxy(hout, x, y);
							}
							else {
								y = 1;
								gotoxy(hout, x, y);
							}
							break;
					}
					break;
				case 75:
					switch (circling) {
						case 0:
							if (x > 1) {          //i
								x--;
								gotoxy(hout, x, y);
							}
							break;
						case 1:
							if (x > 1) {
								x--;
								gotoxy(hout, x, y);
							}
							else {
								x = 69;
								gotoxy(hout, x, y);
							}
							break;
					}
					break;
				case 77:
					//L
					switch (circling) {
						case 0:
							if (x < 69) {
								x++;
								gotoxy(hout, x, y);
							}
							break;
						case 1:
							if (x < 69) {
								x++;
								gotoxy(hout, x, y);
							}
							else {
								x = 1;
								gotoxy(hout, x, y);
							}
							break;
					}
					break;
			}
		}
		else {
			if (movement1 == 32) {
				cout << char(32);
				gotoxy(hout, x, y);
			}
			else if (movement1 == 81 || movement1 == 113)
				break;
			else
				;
		}
	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	//gotoxy(hout, x, 23);
	y = 23;
	while (_getch() != 13) {
		;
	}
}
//加分项
void move_by_ijkl_without_bug(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	// 此句的作用是调用系统的cls命令清屏 */
	cls(hout);

	// 显示初始的边框及其中的随机字符 */
	init_border(hout);
	gotoxy(hout, 35, 9);
	int x = 35, y = 9;
	int movement5, movement6;
	while (1) {
		movement5 = _getch();
		if (movement5 == 224)
			movement6 = _getch();
		else {
			//movement6 = _getch();
			if (movement5 == 105 || movement5 == 73) {
				switch (circling) {
					case 0:
						if (y > 1) {          //i
							y--;
							gotoxy(hout, x, y);
						}
						break;
					case 1:
						if (y > 1) {          //i
							y--;
							gotoxy(hout, x, y);
						}
						else {
							y = 17;
							gotoxy(hout, x, y);
						}
						break;
				}
			}
			else if (movement5 == 107 || movement5 == 75) {//k
				switch (circling) {
					case 0:
						if (y < 17) {
							y++;
							gotoxy(hout, x, y);
						}
						break;
					case 1:
						if (y < 17) {
							y++;
							gotoxy(hout, x, y);
						}
						else {
							y = 1;
							gotoxy(hout, x, y);
						}
						break;
				}
			}
			else if (movement5 == 74 || movement5 == 106) {
				switch (circling) {
					case 0:
						if (x > 1) {
							x--;
							gotoxy(hout, x, y);
						}
						break;
					case 1:
						if (x > 1) {
							x--;
							gotoxy(hout, x, y);
						}
						else {
							x = 69;
							gotoxy(hout, x, y);
						}
						break;
				}
			}
			else if (movement5 == 108 || movement5 == 76) {
				//L
				switch (circling) {
					case 0:
						if (x < 69) {
							x++;
							gotoxy(hout, x, y);
						}
						break;
					case 1:
						if (x < 69) {
							x++;
							gotoxy(hout, x, y);
						}
						else {
							x = 1;
							gotoxy(hout, x, y);
						}
						break;
				}
			}
			else if (movement5 == 32) {
				cout << char(32);
				gotoxy(hout, x, y);
			}
			else if (movement5 == 81 || movement5 == 113)
				break;
		}
	}gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键退出." << endl;
	//gotoxy(hout, x, 23);
	y = 23;
	while (_getch() != 13) {
		;
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int x = 35, y = 9;
	while (1) {
		cls(hout);
		switch (menu()) {

			case 49:
				move_by_ijkl(0);
				break;
			case 50:
				move_by_ijkl(1);
				break;
			case 51:
				move_by_arrow(0);
				break;
			case 52:
				move_by_arrow(1);
				break;
			case 53:
				move_by_ijkl_without_bug(0);
				break;
			case 54:
				move_by_ijkl_without_bug(1);
				break;
			case 48:
				cout << 0;
				return 0;
		}
	}
	return 0;
}
/*思考1：按左方向键使光标向下移动的原因是左方向键的第二个返回值为75，正好和k的ASCII码相同，就造成了该效果，
解决方法:将两个返回值分开判断；
* 思考2：本程序随机打印字母的原理是生成随机数分别对69和17取模，求出横纵坐标，而当两个方向对应的随机数分别正好差整数倍的69和17，
就会导致两次打印的字母位置相同，后打印的就会覆盖之前打印的，这样打印的字母就会不到20个
*/
