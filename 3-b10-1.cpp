/*2353113 ��16 ����*/
#include<iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��

using namespace std;
int num = 0;
int main()
{
    LARGE_INTEGER tick, begin, end;

    QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
    QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

    for (int a = 1; a <= 9; ++a) {
        for (int b = 1; b <= 9; ++b) {
            if (b == a) continue; // ȷ��ʮλ���ֲ����ڰ�λ����
            for (int c = 1; c <= 9; ++c) {
                if (c == a || c == b)
                    continue; // ȷ����λ���ֲ����ڰ�λ��ʮλ����
                for (int d = 1; d <= 9; ++d) {
                    if (d == a || d == b || d == c)
                        continue;
                    for (int e = 1; e <= 9; ++e) {
                        if (e == a || e == b || e == c || e == d)
                            continue;
                        for (int f = 1; f <= 9; ++f) {
                            if (f == a || f == b || f == c || f == d || f == e)
                                continue;
                            for (int g = 1; g <= 9; ++g) {
                                if (g == a || g == b || g == c || g == d || g == e || g == f)
                                    continue;
                                for (int h = 1; h <= 9; ++h) {
                                    if (h == a || h == b || h == c || h == d || h == e || h == f || h == g)
                                        continue;
                                    for (int i = 1; i <= 9; ++i) {
                                        if (i == a || i == b || i == c || i == d || i == e || i == f || i == g || i == h)
                                            continue;
                                        int fst = 100 * a + 10 * b + c;
                                        int snd = 100 * d + 10 * e + f;
                                        int trd = 100 * g + 10 * h + i;
                                        if (100 * a + 10 * b + c + 100 * d + 10 * e + f + 100 * g + 10 * h + i == 1953) {
                                            if (100 * a + 10 * b + c > 598 || snd > trd || fst > snd)
                                                break;
                                            num++;
                                            cout << "No." << setw(3) << num << " : " << fst << "+" << snd << "+" << trd << "=" << "1953" << endl;
                                            // cout << num << " " << fst << " " << snd << " " << trd << endl;

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    QueryPerformanceCounter(&end);		//�����ֹӲ������������
    cout << "total=" << num << endl;
    cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
    cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
    cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;
    return 0;
}
