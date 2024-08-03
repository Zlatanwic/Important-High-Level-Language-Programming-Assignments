/*2353113 信16 李阔*/
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m) {
	int  c, w;
	if (m >= 3 && m <= 14) {
		c = (y / 100) % 100;
		y = y % 100;
		w = y + int(double(y) / 4) + int(double(c) / 4) - 2 * c + int(double(13 * (m + 1)) / 5);
	}
	else if (m == 1 || m == 2) {
		y = y - 1;
		m = m + 12;
		c = (y / 100) % 100;
		y = y % 100;
		w = y + int(double(y) / 4) + int(double(c) / 4) - 2 * c + int(double(13 * (m + 1)) / 5);
	}
	if (w >= 0)
		w = w % 7;
	else {
		int n = 1;
		for (; w < 0; n++) {
			w += n * 7;
		}
		w = w % 7;
	}
	return w;
}
void month_calendar(int year, int num_of_day[], int line[], int month, int run_or_not) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (num_of_day[month] != 31) {
				if (line[month] == zeller(year, month)) {

					for (int i = 0; i < zeller(year, month); i++)//打空格
						cout << "    ";

				}
				for (int i = num_of_day[month] + 1; i <= 31; i++) {
					cout << setw(4) << setiosflags(ios::left) << i;
					num_of_day[month]++;
					line[month]++;
					if (line[month] % 7 == 0)
						break;
				}
				if (num_of_day[month] == 31) {
					if (line[month] % 7 != 0)
						for (int i = 1; i <= 7 - line[month] % 7; i++) {
							cout << "    ";
							//line[month]++;
						}

				}
			}
			else {

				cout << "                            ";
			}
			cout << "    ";
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (num_of_day[month] != 30) {
				if (line[month] == zeller(year, month)) {

					for (int i = 0; i < zeller(year, month); i++)//打空格
						cout << "    ";
				}
				for (int i = num_of_day[month] + 1; i <= 30; i++) {
					cout << setw(4) << setiosflags(ios::left) << i;
					num_of_day[month]++;
					line[month]++;
					if (line[month] % 7 == 0)
						break;
				}
				if (num_of_day[month] == 30) {
					if (line[month] % 7 != 0)
						for (int i = 1; i <= 7 - line[month] % 7; i++) {
							cout << "    ";
							//line[month]++;
						}

				}
			}
			else {
				cout << "                            ";
			}
			cout << "    ";
			break;
		case 2:
			if (num_of_day[month] != 28 + run_or_not) {
				if (line[month] == zeller(year, month)) {

					for (int i = 0; i < zeller(year, month); i++)//打空格
						cout << "    ";
				}
				for (int i = num_of_day[month] + 1; i <= 28 + run_or_not; i++) {
					cout << setw(4) << setiosflags(ios::left) << i;
					num_of_day[month]++;
					line[month]++;
					if (line[month] % 7 == 0)
						break;
				}
				if (num_of_day[month] == 28 + run_or_not) {
					if (line[month] % 7 != 0)
						for (int i = 1; i <= 7 - line[month] % 7; i++) {
							cout << "    ";
							//line[month]++;
						}

				}
			}
			else
				cout << "                            ";
			cout << "    ";
			break;

	}
}
int cal_column(int year, int month, int run_or_not) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (zeller(year, month) != 0) {
				if ((31 - (7 - zeller(year, month))) % 7 != 0)
					return (31 - (7 - zeller(year, month))) / 7 + 1 + 1;
				else
					return (31 - (7 - zeller(year, month))) / 7 + 1;

			}
			else
				return 31 / 7 + 1;
		case 4:
		case 6:
		case 9:
		case 11:
			if (zeller(year, month) != 0) {
				if ((30 - (7 - zeller(year, month))) % 7 != 0)
					return (30 - (7 - zeller(year, month))) / 7 + 1 + 1;
				else
					return (30 - (7 - zeller(year, month))) / 7 + 1;

			}
			else
				return 30 / 7 + 1;
		case 2:
			if (zeller(year, month) != 0) {
				if ((28 + run_or_not - (7 - zeller(year, month))) % 7 != 0)
					return (28 + run_or_not - (7 - zeller(year, month))) / 7 + 1 + 1;
				else
					return (28 + run_or_not - (7 - zeller(year, month))) / 7 + 1;

			}
			else
				return 28 + run_or_not / 7 + 1;
		default :
			return 0;

	}
}
int max_of_three(int a, int b, int c) {
	int maxab = (a > b ? a : b);
	return (maxab < c ? c : maxab);
}
int main()
{
	cout << "请输入年份[1900-2100]" << endl;
	int year;
	cin >> year;
	int run_or_not = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	int line[13] = { 0 };
	for (int i = 1; i <= 12; i++) {
		line[i] = zeller(year, i);
	}
	int num_of_day[13] = { 0 };
	cout << year << "年的日历:" << endl;
	cout << endl;
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;


	for (int i = 1; i <= max_of_three(cal_column(year, 1, run_or_not), cal_column(year, 2, run_or_not), cal_column(year, 3, run_or_not)); i++) {
		month_calendar(year, num_of_day, line, 1, run_or_not);
		month_calendar(year, num_of_day, line, 2, run_or_not);
		month_calendar(year, num_of_day, line, 3, run_or_not);
		cout << endl;
	}
	cout << endl;
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max_of_three(cal_column(year, 4, run_or_not), cal_column(year, 5, run_or_not), cal_column(year, 6, run_or_not)); i++) {
		month_calendar(year, num_of_day, line, 4, run_or_not);
		month_calendar(year, num_of_day, line, 5, run_or_not);
		month_calendar(year, num_of_day, line, 6, run_or_not);
		cout << endl;
	}
	cout << endl;
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max_of_three(cal_column(year, 7, run_or_not), cal_column(year, 8, run_or_not), cal_column(year, 9, run_or_not)); i++) {
		month_calendar(year, num_of_day, line, 7, run_or_not);
		month_calendar(year, num_of_day, line, 8, run_or_not);
		month_calendar(year, num_of_day, line, 9, run_or_not);
		cout << endl;
	}
	cout << endl;
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (int i = 1; i <= max_of_three(cal_column(year, 10, run_or_not), cal_column(year, 11, run_or_not), cal_column(year, 12, run_or_not)); i++) {
		month_calendar(year, num_of_day, line, 10, run_or_not);
		month_calendar(year, num_of_day, line, 11, run_or_not);
		month_calendar(year, num_of_day, line, 12, run_or_not);
		cout << endl;
	}
	cout << endl << endl;
	return 0;
}