/*2353113 ��16 ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double a, e;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);
    printf("��д�����:\n");
    int  w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12;

    e = a + 0.001;
    int b = (int)(e / 10);
    w1 = (int)(b / 1e8);
    w2 = (int)((b - w1 * 1e8) / 1e7);
    w3 = (int)((b - w1 * 1e8 - w2 * 1e7) / 1e6);
    w4 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6) / 1e5);
    w5 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5) / 1e4);
    w6 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4) / 1e3);
    w7 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3) / 1e2);
    w8 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2) / 1e1);
    w9 = (int)((b - w1 * 1e8 - w2 * 1e7 - w3 * 1e6 - w4 * 1e5 - w5 * 1e4 - w6 * 1e3 - w7 * 1e2 - w8 * 1e1) / 1);
    double c = e / 10 - b;
    int d = (int)(1000 * c);
    w10 = d / 100;
    w11 = (d - w10 * 100) / 10;
    w12 = (d - w10 * 100 - w11 * 10) / 1;

    if (a == 0) {
        printf("��Բ��");
    }
    else {
        // �����һλ
        switch (w1) {
            case 9:
                printf("��ʰ");
                break;
            case 8:
                printf("��ʰ");
                break;
            case 7:
                printf("��ʰ");
                break;
            case 6:
                printf("½ʰ");
                break;
            case 5:
                printf("��ʰ");
                break;
            case 4:
                printf("��ʰ");
                break;
            case 3:
                printf("��ʰ");
                break;
            case 2:
                printf("��ʰ");
                break;
            case 1:
                printf("Ҽʰ");
                break;
            case 0:
                break;
        }

        // ����ڶ�λ
        switch (w2) {
            case 9:
                printf("����");
                break;
            case 8:
                printf("����");
                break;
            case 7:
                printf("����");
                break;
            case 6:
                printf("½��");
                break;
            case 5:
                printf("����");
                break;
            case 4:
                printf("����");
                break;
            case 3:
                printf("����");
                break;
            case 2:
                printf("����");
                break;
            case 1:
                printf("Ҽ��");
                break;
            case 0:
                if (w1 != 0 || w2 != 0) {
                    printf("��");
                }
                break;
        }
        // �������λ
        switch (w3) {
            case 9:
                printf("��Ǫ");
                break;
            case 8:
                printf("��Ǫ");
                break;
            case 7:
                printf("��Ǫ");
                break;
            case 6:
                printf("½Ǫ");
                break;
            case 5:
                printf("��Ǫ");
                break;
            case 4:
                printf("��Ǫ");
                break;
            case 3:
                printf("��Ǫ");
                break;
            case 2:
                printf("��Ǫ");
                break;
            case 1:
                printf("ҼǪ");
                break;
            case 0:
                if ((w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))))
                    printf("��");
        }

        // �������λ
        switch (w4) {
            case 9:
                printf("����");
                break;
            case 8:
                printf("�ư�");
                break;
            case 7:
                printf("���");
                break;
            case 6:
                printf("½��");
                break;
            case 5:
                printf("���");
                break;
            case 4:
                printf("����");
                break;
            case 3:
                printf("����");
                break;
            case 2:
                printf("����");
                break;
            case 1:
                printf("Ҽ��");
                break;
            case 0:
                if (w3 != 0 && (w5 != 0 || w6 != 0))
                    printf("��");
        }
        // �����5λ
        switch (w5) {
            case 9:
                printf("��ʰ");
                break;
            case 8:
                printf("��ʰ");
                break;
            case 7:
                printf("��ʰ");
                break;
            case 6:
                printf("½ʰ");
                break;
            case 5:
                printf("��ʰ");
                break;
            case 4:
                printf("��ʰ");
                break;
            case 3:
                printf("��ʰ");
                break;
            case 2:
                printf("��ʰ");
                break;
            case 1:
                printf("Ҽʰ");
                break;
            case 0:
                if (w4 != 0 && w6 != 0)
                    printf("��");
                break;
        }

        // �����6λ
        switch (w6) {
            case 9:
                printf("����");
                break;
            case 8:
                printf("����");
                break;
            case 7:
                printf("����");
                break;
            case 6:
                printf("½��");
                break;
            case 5:
                printf("����");
                break;
            case 4:
                printf("����");
                break;
            case 3:
                printf("����");
                break;
            case 2:
                printf("����");
                break;
            case 1:
                printf("Ҽ��");
                break;
            case 0:
                if (w3 != 0 || w4 != 0 || w5 != 0)
                    printf("��");
                break;
        }
        // �������λ
        switch (w7) {
            case 9:
                printf("��Ǫ");
                break;
            case 8:
                printf("��Ǫ");
                break;
            case 7:
                printf("��Ǫ");
                break;
            case 6:
                printf("½Ǫ");
                break;
            case 5:
                printf("��Ǫ");
                break;
            case 4:
                printf("��Ǫ");
                break;
            case 3:
                printf("��Ǫ");
                break;
            case 2:
                printf("��Ǫ");
                break;
            case 1:
                printf("ҼǪ");
                break;
            case 0:
                if ((w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0))
                    printf("��");
                break;
        }
        // ����ڰ�λ
        switch (w8) {
            case 9:
                printf("����");
                break;
            case 8:
                printf("�ư�");
                break;
            case 7:
                printf("���");
                break;
            case 6:
                printf("½��");
                break;
            case 5:
                printf("���");
                break;
            case 4:
                printf("����");
                break;
            case 3:
                printf("����");
                break;
            case 2:
                printf("����");
                break;
            case 1:
                printf("Ҽ��");
                break;
            case 0:
                if (w7 != 0 && (w9 != 0 || w10 != 0))
                    printf("��");
        }
        // �����9λ
        switch (w9) {
            case 9:
                printf("��ʰ");
                break;
            case 8:
                printf("��ʰ");
                break;
            case 7:
                printf("��ʰ");
                break;
            case 6:
                printf("½ʰ");
                break;
            case 5:
                printf("��ʰ");
                break;
            case 4:
                printf("��ʰ");
                break;
            case 3:
                printf("��ʰ");
                break;
            case 2:
                printf("��ʰ");
                break;
            case 1:
                printf("Ҽʰ");
                break;
            case 0:
                if (w8 != 0 && w10 != 0)
                    printf("��");
                break;
        }
        // �����10λ
        switch (w10) {
            case 9:
                printf("��Բ");
                break;
            case 8:
                printf("��Բ");
                break;
            case 7:
                printf("��Բ");
                break;
            case 6:
                printf("½Բ");
                break;
            case 5:
                printf("��Բ");
                break;
            case 4:
                printf("��Բ");
                break;
            case 3:
                printf("��Բ");
                break;
            case 2:
                printf("��Բ");
                break;
            case 1:
                printf("ҼԲ");
                break;
            case 0:
                if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
                    printf("Բ");
                break;
        }
        if (w11 == 0 && w12 == 0) {
            if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
                printf("��");
        }
        // �����11λ
        if (w12 == 0) {
            switch (w11) {
                case 9:
                    printf("������");
                    break;
                case 8:
                    printf("�ƽ���");
                    break;
                case 7:
                    printf("�����");
                    break;
                case 6:
                    printf("½����");
                    break;
                case 5:
                    printf("�����");
                    break;
                case 4:
                    printf("������");
                    break;
                case 3:
                    printf("������");
                    break;
                case 2:
                    printf("������");
                    break;
                case 1:
                    printf("Ҽ����");
                    break;
                case 0:
                    break;
            }
        }
        else {
            switch (w11) {
                case 9:
                    printf("����");
                    break;
                case 8:
                    printf("�ƽ�");
                    break;
                case 7:
                    printf("���");
                    break;
                case 6:
                    printf("½��");
                    break;
                case 5:
                    printf("���");
                    break;
                case 4:
                    printf("����");
                    break;
                case 3:
                    printf("����");
                    break;
                case 2:
                    printf("����");
                    break;
                case 1:
                    printf("Ҽ��");
                    break;
                case 0:
                    if (w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0) {
                        ;
                    
                    }
                    else 
                        printf("��");
                    break;
            }
            // �����12λ
            switch (w12) {
                case 9:
                    printf("����");
                    break;
                case 8:
                    printf("�Ʒ�");
                    break;
                case 7:
                    printf("���");
                    break;
                case 6:
                    printf("½��");
                    break;
                case 5:
                    printf("���");
                    break;
                case 4:
                    printf("����");
                    break;
                case 3:
                    printf("����");
                    break;
                case 2:
                    printf("����");
                    break;
                case 1:
                    printf("Ҽ��");
                    break;
            }
        }
    }
    printf("\n");
    return 0;
}