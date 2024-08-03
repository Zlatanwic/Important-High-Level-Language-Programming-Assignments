/*2353113 ��16 ����*/
#define _CRT_SECURE_NO_WARNINGS 
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include <iomanip>

#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
class stu_list;
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	char round1_inf[MAX_NAME_LEN];
	char round2_inf[MAX_NAME_LEN];
	friend stu_list;
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
	//stu_merge(int no,char name[MAX_NAME_LEN], char round_inf1[MAX_NAME_LEN], char round_inf2[MAX_NAME_LEN]);
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	void merge();
	void order();
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


void stu_list::merge()
{
	/*stu_merge midlist;
	for (int i = 0; i < MAX_STU_NUM - 1; i++) {
		for (int j = 0; j < MAX_STU_NUM - (i + 1); j++) {
			if (list_round_1[j].no < list_merge[j + 1].stu_no) {
				midlist = list_merge[j];
				list_merge[j] = list_merge[j + 1];
				list_merge[j + 1] = midlist;
			}

		}
	}*/

	int bu = 0;
	int i = 0;
	for (int t = 0; t < MAX_STU_NUM; t++) {
		list_merge[t].stu_no = 0;

	}
	int n = 0;
	for (; i < MAX_STU_NUM; i++) {
		if (list_round_1[i].no < 0) {

			break;
		}
		n = 0;

		/*for (int a = 0; list_round_1[a].no > 0 && list_merge[a].stu_no>0; a++) {
			if (list_merge[a].stu_no == list_round_1[i].no) {
				n = 1;
				break;
			}

		}
		if(n==1)
			continue;*/
		list_merge[i].stu_no = list_round_1[i].no;
		strcpy(list_merge[i].stu_name, list_round_1[i].name);
		strcpy(list_merge[i].round1_inf, "Y");
		//int tui = 1;
		for (int t = 0; t < MAX_STU_NUM; t++) {
			if (list_round_2[t].no == list_round_1[i].no) {
				strcpy(list_merge[i].round2_inf, "Y");
				//tui = 0;
				break;
			}
			if (t == MAX_STU_NUM - 1 && list_round_2[t].no != list_round_1[i].no)
				strcpy(list_merge[i].round2_inf, "�˿�");
		}

	}
	i = 0;
	for (; list_merge[i].stu_no > 0;) {
		i++;
	}
	int j = 0;
	int w = 0;
	for (; list_round_2[j].no > 0; j++) {
		w = 0;
		for (int a = 0; list_merge[a].stu_no > 0; a++) {
			if (list_merge[a].stu_no == list_round_2[j].no) {
				w = 1;
				break;
			}

		}
		if (w == 1)
			continue;
		else {
			list_merge[i].stu_no = list_round_2[j].no;
			strcpy(list_merge[i].stu_name, list_round_2[j].name);
			strcpy(list_merge[i].round1_inf, "/");
			strcpy(list_merge[i].round2_inf, "��ѡ");
			i++;
		}

	}
}

void stu_list::order()
{
	stu_merge midlist;
	for (int i = 0; i < MAX_STU_NUM - 1; i++) {
		for (int j = 0; j < MAX_STU_NUM - (i + 1); j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				midlist = list_merge[j];
				list_merge[j] = list_merge[j + 1];
				list_merge[j + 1] = midlist;
			}

		}
	}
	int point = 0;
	for (int i = 1; i < MAX_STU_NUM; i++) {
		if (list_merge[point].stu_no != list_merge[i].stu_no) {
			point++;
			list_merge[point] = list_merge[i];
		}
	}
	for (int i = point + 1; i < MAX_STU_NUM; i++) {
		list_merge[i].stu_no = 0;
	}

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (int i = 0; i < MAX_STU_NUM; i++) {
		if (list_merge[i].stu_no > 0) {
			cout << setiosflags(ios::left) << setw(5) << i << list_merge[i].stu_no << "  " << setw(32) << list_merge[i].stu_name
				<< setiosflags(ios::left) << setw(7) << list_merge[i].round1_inf << setiosflags(ios::left) << setw(5) << list_merge[i].round2_inf << endl;

		}
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.merge();
	list.order();
	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

