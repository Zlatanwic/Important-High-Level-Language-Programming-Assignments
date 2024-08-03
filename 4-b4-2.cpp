/*2353113 ��16 ����*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�


/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu() {
	int choice;
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)(�����ͷ�������ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����)(�����ͷ�������ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";
	choice = _getch();
	return choice;
}
/***************************************************************************
�������ƣ�move_by_ijkl
��    �ܣ�ͨ��ijkl�����ƶ����
���������circling���Ƿ����
�� �� ֵ��
˵    ����
***************************************************************************/
void move_by_ijkl(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	// �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	// ��ʾ��ʼ�ı߿����е�����ַ� */
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
	cout << "��Ϸ���������س����˳�." << endl;
	//gotoxy(hout, x, 23);
	y = 23;

	while (_getch() != 13) {
		;
	}
}
/***************************************************************************
�������ƣ�move_by_arrow
��    �ܣ�ͨ����������ƶ����
���������circling���Ƿ����
�� �� ֵ��
˵    ����
***************************************************************************/
void move_by_arrow(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	// �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	// ��ʾ��ʼ�ı߿����е�����ַ� */
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
	cout << "��Ϸ���������س����˳�." << endl;
	//gotoxy(hout, x, 23);
	y = 23;
	while (_getch() != 13) {
		;
	}
}
//�ӷ���
void move_by_ijkl_without_bug(bool circling) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	// �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);

	// ��ʾ��ʼ�ı߿����е�����ַ� */
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
	cout << "��Ϸ���������س����˳�." << endl;
	//gotoxy(hout, x, 23);
	y = 23;
	while (_getch() != 13) {
		;
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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
/*˼��1���������ʹ��������ƶ���ԭ����������ĵڶ�������ֵΪ75�����ú�k��ASCII����ͬ��������˸�Ч����
�������:����������ֵ�ֿ��жϣ�
* ˼��2�������������ӡ��ĸ��ԭ��������������ֱ��69��17ȡģ������������꣬�������������Ӧ��������ֱ����ò���������69��17��
�ͻᵼ�����δ�ӡ����ĸλ����ͬ�����ӡ�ľͻḲ��֮ǰ��ӡ�ģ�������ӡ����ĸ�ͻ᲻��20��
*/
