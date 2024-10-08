#pragma once
void menu();
void input(int& hang, int& lie);
void print_table(int hang, int lie, int table[][11]);
void find_repeated_erasable_num(const char str1[], const char str2[], int hang, int lie, int table[][11], int erasable_or_not[][11]);
void back_to_menu();
void initailize_table(int hang, int lie, int table[][11]);
int my_strcasecmp(const char s1[], const char s2[]);
int check_eliminated_or_not(int hang, int lie, int table[][11]);
void fill_rand_num(int hang, int lie, int table[][11]);
void print_prompt_items(int hang, int lie, int table[][11], int light_or_not[][11]);
int find_prompt_items(int i, int j, int table[][11], int light_or_not[][11]);
int judge_prompt_or_not(int i, int j, int table[][11], int light_or_not[][11], int direction);
void initial_visualize_without_frame(int hang, int lie, int table[][11],int display_repeated_or_not, int continuous);
void initial_visualize_with_frame(int hang, int lie, int table[][11], int display_repeated_or_not, int continuous);
int judge_erasable_or_not(int i, int j, int table[][11]);
void visualize_prompt_items(int hang, int lie, int table[][11], int light_or_not[][11], int continuous);
void visualize_remove(int hang, int lie, int table[][11], int erasable_or_not[][11], int continuous,int &score,int conduct_by_my_self);
void make_erasable_array(int hang, int lie, int table[][11], int erasable_or_not[][11]);
void erasable_array_back_to_zero(int erasable_or_not[][11]);
void drop(int hang, int lie, int table[][11], int erasable_or_not[][11]);
//void turn_repeated_to_zero(int hang, int lie, int table[][11], int erasable_or_not[][11]);
void visualize_ball_drop(int hang, int lie, int table[][11], int erasable_or_not[][11]);
void visualize_fill_balls(int hang, int lie, int table[][11], int continuous);
void read_mouse(int hang, int lie, int table[][11], int prompt_or_not[][11]);
void visualize_repeated(int hang, int lie, int table[][11], int erasable_or_not[][11]);
void choose_with_mouse(int hang, int lie, int table[][11], int prompt_or_not[][11], int exchange[],int &x,int &y,int &quit_or_not);
void exchange_balls(int x1, int y1, int x2, int y2, int table[][11]);
void print_scores(int score);