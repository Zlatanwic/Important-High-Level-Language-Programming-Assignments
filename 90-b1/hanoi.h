/*2353113 ��16 ����*/
#pragma once
void menu();
void hanoi_solution(int n, char src,char tmp, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not,int X,int Y);
void print_process(char a);
void assist_counting(int n, int details_of_column[][10], int num_of_each_column[], char src, char dst,int game_or_not);
void print_pattern(char a,int Y);
void print_totally(int n, char src, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not,int X,int Y,int game_or_not);
void Integrated_output(int n, char src, char tmp, char dst, int step_or_not, int horizontal_or_not, int vertical_or_not, int automove_or_not,int X,int Y);
void draw_column();
void draw_plate(int n, char src, char dst);
void move_one_plate(int n, char src,char tmp, char dst,int game_or_not);
void to_be_continued();
void horizontal_initial_print(int n, char src,  int Y, int vertical_or_not);
void vertial_initial_print(int n, char src, int Y);
void hanoi_game(int n, char src, char dst);
void turn_zero();
void input(int* n, char* src, char* tmp, char* dst);
void situation1(int n, char src, char tmp, char dst);
void situation2(int n, char src, char tmp, char dst);
void situation3(int n, char src, char tmp, char dst);
void situation4(int n, char src, char tmp, char dst);
void situation5();
void situation6(int n, char src, char tmp, char dst);
void situation8(int n, char src, char tmp, char dst);
void situation7(int n, char src, char tmp, char dst);
void situation9(int n, char src, char tmp, char dst);
/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

