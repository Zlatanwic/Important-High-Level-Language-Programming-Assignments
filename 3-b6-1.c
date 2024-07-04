/*2353113 ÐÅ16 ÀîÀ«*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double a, e;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
    scanf("%lf", &a);
    printf("´óÐ´½á¹ûÊÇ:\n");
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
        printf("ÁãÔ²Õû");
    }
    else {
        // ´¦ÀíµÚÒ»Î»
        switch (w1) {
            case 9:
                printf("¾ÁÊ°");
                break;
            case 8:
                printf("°ÆÊ°");
                break;
            case 7:
                printf("ÆâÊ°");
                break;
            case 6:
                printf("Â½Ê°");
                break;
            case 5:
                printf("ÎéÊ°");
                break;
            case 4:
                printf("ËÁÊ°");
                break;
            case 3:
                printf("ÈþÊ°");
                break;
            case 2:
                printf("·¡Ê°");
                break;
            case 1:
                printf("Ò¼Ê°");
                break;
            case 0:
                break;
        }

        // ´¦ÀíµÚ¶þÎ»
        switch (w2) {
            case 9:
                printf("¾ÁÒÚ");
                break;
            case 8:
                printf("°ÆÒÚ");
                break;
            case 7:
                printf("ÆâÒÚ");
                break;
            case 6:
                printf("Â½ÒÚ");
                break;
            case 5:
                printf("ÎéÒÚ");
                break;
            case 4:
                printf("ËÁÒÚ");
                break;
            case 3:
                printf("ÈþÒÚ");
                break;
            case 2:
                printf("·¡ÒÚ");
                break;
            case 1:
                printf("Ò¼ÒÚ");
                break;
            case 0:
                if (w1 != 0 || w2 != 0) {
                    printf("ÒÚ");
                }
                break;
        }
        // ´¦ÀíµÚÈýÎ»
        switch (w3) {
            case 9:
                printf("¾ÁÇª");
                break;
            case 8:
                printf("°ÆÇª");
                break;
            case 7:
                printf("ÆâÇª");
                break;
            case 6:
                printf("Â½Çª");
                break;
            case 5:
                printf("ÎéÇª");
                break;
            case 4:
                printf("ËÁÇª");
                break;
            case 3:
                printf("ÈþÇª");
                break;
            case 2:
                printf("·¡Çª");
                break;
            case 1:
                printf("Ò¼Çª");
                break;
            case 0:
                if ((w1 != 0 || w2 != 0) && ((w4 != 0 || w5 != 0 || w6 != 0) || (w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && (w8 != 0 || w9 != 0 || w10 != 0))))
                    printf("Áã");
        }

        // ´¦ÀíµÚËÄÎ»
        switch (w4) {
            case 9:
                printf("¾Á°Û");
                break;
            case 8:
                printf("°Æ°Û");
                break;
            case 7:
                printf("Æâ°Û");
                break;
            case 6:
                printf("Â½°Û");
                break;
            case 5:
                printf("Îé°Û");
                break;
            case 4:
                printf("ËÁ°Û");
                break;
            case 3:
                printf("Èþ°Û");
                break;
            case 2:
                printf("·¡°Û");
                break;
            case 1:
                printf("Ò¼°Û");
                break;
            case 0:
                if (w3 != 0 && (w5 != 0 || w6 != 0))
                    printf("Áã");
        }
        // ´¦ÀíµÚ5Î»
        switch (w5) {
            case 9:
                printf("¾ÁÊ°");
                break;
            case 8:
                printf("°ÆÊ°");
                break;
            case 7:
                printf("ÆâÊ°");
                break;
            case 6:
                printf("Â½Ê°");
                break;
            case 5:
                printf("ÎéÊ°");
                break;
            case 4:
                printf("ËÁÊ°");
                break;
            case 3:
                printf("ÈþÊ°");
                break;
            case 2:
                printf("·¡Ê°");
                break;
            case 1:
                printf("Ò¼Ê°");
                break;
            case 0:
                if (w4 != 0 && w6 != 0)
                    printf("Áã");
                break;
        }

        // ´¦ÀíµÚ6Î»
        switch (w6) {
            case 9:
                printf("¾ÁÍò");
                break;
            case 8:
                printf("°ÆÍò");
                break;
            case 7:
                printf("ÆâÍò");
                break;
            case 6:
                printf("Â½Íò");
                break;
            case 5:
                printf("ÎéÍò");
                break;
            case 4:
                printf("ËÁÍò");
                break;
            case 3:
                printf("ÈþÍò");
                break;
            case 2:
                printf("·¡Íò");
                break;
            case 1:
                printf("Ò¼Íò");
                break;
            case 0:
                if (w3 != 0 || w4 != 0 || w5 != 0)
                    printf("Íò");
                break;
        }
        // ´¦ÀíµÚÆßÎ»
        switch (w7) {
            case 9:
                printf("¾ÁÇª");
                break;
            case 8:
                printf("°ÆÇª");
                break;
            case 7:
                printf("ÆâÇª");
                break;
            case 6:
                printf("Â½Çª");
                break;
            case 5:
                printf("ÎéÇª");
                break;
            case 4:
                printf("ËÁÇª");
                break;
            case 3:
                printf("ÈþÇª");
                break;
            case 2:
                printf("·¡Çª");
                break;
            case 1:
                printf("Ò¼Çª");
                break;
            case 0:
                if ((w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0) && (w8 != 0 || w9 != 0 || w10 != 0))
                    printf("Áã");
                break;
        }
        // ´¦ÀíµÚ°ËÎ»
        switch (w8) {
            case 9:
                printf("¾Á°Û");
                break;
            case 8:
                printf("°Æ°Û");
                break;
            case 7:
                printf("Æâ°Û");
                break;
            case 6:
                printf("Â½°Û");
                break;
            case 5:
                printf("Îé°Û");
                break;
            case 4:
                printf("ËÁ°Û");
                break;
            case 3:
                printf("Èþ°Û");
                break;
            case 2:
                printf("·¡°Û");
                break;
            case 1:
                printf("Ò¼°Û");
                break;
            case 0:
                if (w7 != 0 && (w9 != 0 || w10 != 0))
                    printf("Áã");
        }
        // ´¦ÀíµÚ9Î»
        switch (w9) {
            case 9:
                printf("¾ÁÊ°");
                break;
            case 8:
                printf("°ÆÊ°");
                break;
            case 7:
                printf("ÆâÊ°");
                break;
            case 6:
                printf("Â½Ê°");
                break;
            case 5:
                printf("ÎéÊ°");
                break;
            case 4:
                printf("ËÁÊ°");
                break;
            case 3:
                printf("ÈþÊ°");
                break;
            case 2:
                printf("·¡Ê°");
                break;
            case 1:
                printf("Ò¼Ê°");
                break;
            case 0:
                if (w8 != 0 && w10 != 0)
                    printf("Áã");
                break;
        }
        // ´¦ÀíµÚ10Î»
        switch (w10) {
            case 9:
                printf("¾ÁÔ²");
                break;
            case 8:
                printf("°ÆÔ²");
                break;
            case 7:
                printf("ÆâÔ²");
                break;
            case 6:
                printf("Â½Ô²");
                break;
            case 5:
                printf("ÎéÔ²");
                break;
            case 4:
                printf("ËÁÔ²");
                break;
            case 3:
                printf("ÈþÔ²");
                break;
            case 2:
                printf("·¡Ô²");
                break;
            case 1:
                printf("Ò¼Ô²");
                break;
            case 0:
                if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
                    printf("Ô²");
                break;
        }
        if (w11 == 0 && w12 == 0) {
            if (w1 != 0 || w2 != 0 || w3 != 0 || w4 != 0 || w5 != 0 || w6 != 0 || w7 != 0 || w8 != 0 || w9 != 0 || w10 != 0)
                printf("Õû");
        }
        // ´¦ÀíµÚ11Î»
        if (w12 == 0) {
            switch (w11) {
                case 9:
                    printf("¾Á½ÇÕû");
                    break;
                case 8:
                    printf("°Æ½ÇÕû");
                    break;
                case 7:
                    printf("Æâ½ÇÕû");
                    break;
                case 6:
                    printf("Â½½ÇÕû");
                    break;
                case 5:
                    printf("Îé½ÇÕû");
                    break;
                case 4:
                    printf("ËÁ½ÇÕû");
                    break;
                case 3:
                    printf("Èþ½ÇÕû");
                    break;
                case 2:
                    printf("·¡½ÇÕû");
                    break;
                case 1:
                    printf("Ò¼½ÇÕû");
                    break;
                case 0:
                    break;
            }
        }
        else {
            switch (w11) {
                case 9:
                    printf("¾Á½Ç");
                    break;
                case 8:
                    printf("°Æ½Ç");
                    break;
                case 7:
                    printf("Æâ½Ç");
                    break;
                case 6:
                    printf("Â½½Ç");
                    break;
                case 5:
                    printf("Îé½Ç");
                    break;
                case 4:
                    printf("ËÁ½Ç");
                    break;
                case 3:
                    printf("Èþ½Ç");
                    break;
                case 2:
                    printf("·¡½Ç");
                    break;
                case 1:
                    printf("Ò¼½Ç");
                    break;
                case 0:
                    if (w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0 && w5 == 0 && w6 == 0 && w7 == 0 && w8 == 0 && w9 == 0 && w10 == 0) {
                        ;
                    
                    }
                    else 
                        printf("Áã");
                    break;
            }
            // ´¦ÀíµÚ12Î»
            switch (w12) {
                case 9:
                    printf("¾Á·Ö");
                    break;
                case 8:
                    printf("°Æ·Ö");
                    break;
                case 7:
                    printf("Æâ·Ö");
                    break;
                case 6:
                    printf("Â½·Ö");
                    break;
                case 5:
                    printf("Îé·Ö");
                    break;
                case 4:
                    printf("ËÁ·Ö");
                    break;
                case 3:
                    printf("Èþ·Ö");
                    break;
                case 2:
                    printf("·¡·Ö");
                    break;
                case 1:
                    printf("Ò¼·Ö");
                    break;
            }
        }
    }
    printf("\n");
    return 0;
}