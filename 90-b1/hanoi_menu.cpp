/*2353113 ��16 ����*/
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

     ���ļ����ܣ�
	1���ű� hanoi_main.cpp ���õĲ˵�������Ҫ����ʾ���˵��������ȷ��ѡ��󷵻�

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2���������徲̬ȫ�ֱ�����ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  �������ƣ�menu
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void menu() 
{
    while (1) {
        turn_zero();
        cct_cls();
        cout << "---------------------------------" << endl;
        cout << "1.������" << endl;
        cout << "2.������(������¼)" << endl;
        cout << "3.�ڲ�������ʾ(����)" << endl;
        cout << "4.�ڲ�������ʾ(����+����)" << endl;
        cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
        cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
        cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
        cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
        cout << "9.ͼ�ν�-��Ϸ��" << endl;
        cout << "0.�˳�" << endl;
        cout << "---------------------------------" << endl;
        int choice;
        cout << "[��ѡ��:]";
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
