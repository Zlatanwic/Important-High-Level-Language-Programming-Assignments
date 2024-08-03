/*2353113 ��16 ����*/

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int num = 0;
    if (str == NULL)
        return 0;
    for (const char* pch = str;*pch!='\0'; pch++) {
        num++;
    }

    return num;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return NULL;
    const char* ps2 = s2;
    char* ps1 = s1+tj_strlen(s1);
    
    
    for (; *ps2 != '\0'; ps1++,ps2++) {
        *ps1 = *ps2;
    }
    *ps1 = '\0';
    return s1;
    
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return NULL;
    const char* ps2 = s2;
    
    char* ps1 = s1 + tj_strlen(s1);
    const char* end = ps1 + len;
    int time = 0;
    for (; (*ps2 != '\0');  ps2++) {
        *ps1 = *ps2;
        time++;
        ps1++;
        if (time == len)
            break;
    }
    //cout << hex << (void*)(end) << endl;
   // cout << hex << (void*)(ps1) << endl;
    *ps1 = '\0';
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL)
        return NULL;
    char* ps1 = s1;
    const char* ps2 = s2;
    if (s2 == NULL) {
        *ps1 = '\0';
        return s1;

    }
    else{
        for (;; ps1++, ps2++) {
            *ps1 = *ps2;
            if (*ps2 == '\0')
                break;
        }
    return s1;
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    if (s1 == NULL)
        return NULL;
    int time = 0;
    char* ps1 = s1;
    const char* ps2 = s2;
    if (s2 == NULL) 
        return s1;
    for (;; ps1++, ps2++) {
        if (*ps2 == '\0'||time==len)
            break;
        *ps1 = *ps2;
        time++;
        
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL&&s2!=NULL)
        return -1;
    if (s2 == NULL&&s1!=NULL)
        return 1;
    int dif;
    const char* ps1 = s1;
    const char* ps2 = s2;
    for (; ; ps1++,ps2++) {
        dif = *ps1 - *ps2;
        if (dif != 0 || (*ps1 == '\0' && *ps2 == '\0'))
            break;
    }
    return dif;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    int dif;
    const char* ps1 = s1;
    const char* ps2 = s2;
    int value1;
    int value2;
    for (; ; ps1++, ps2++) {
        value1 = int(*ps1);
        value2 = int(*ps2);
        if (*ps1 >= 65 && *ps1 <= 90)   //����ASCII��ת��Сд��ĸ
            value1 += 32;
        if (*ps2 >= 65 && *ps2 <= 90)
            value2 += 32;
        dif = value1 - value2;
        if (dif != 0 || (*ps1 == '\0' && *ps2 == '\0'))
            break;
    }
    return dif;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    int dif;
    const char* ps1 = s1;
    const char* ps2 = s2;
    const char* end = s2 + len;
    for (;ps2< end ; ps1++, ps2++) {
        dif = *ps1 - *ps2;
        if (dif != 0 || (*ps1 == '\0' && *ps2 == '\0'))
            break;
    }
    return dif;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    int dif;
    const char* ps1 = s1;
    const char* ps2 = s2;
    const char* end = s2 + len;
    int value1;
    int value2;
    for (; ps2 < end; ps1++, ps2++) {
        value1 = int(*ps1);
        value2 = int(*ps2);
        if (*ps1 >= 65 && *ps1 <= 90)   //����ASCII��ת��Сд��ĸ
            value1 += 32;
        if (*ps2 >= 65 && *ps2 <= 90)
            value2 += 32;
        dif = value1 - value2;
        
        if (dif != 0 || (*ps1 == '\0' && *ps2 == '\0'))
            break;
    }

    return dif;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return NULL;
    char* p = str;
    for (; *p != '\0'; p++) {
        if (int(*p) >= 97 && int(*p) <= 122)
            *p = char(int(*p) - 32);
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return NULL;
    char* p = str;
    for (; *p != '\0'; p++) {
        
        if (int(*p) >= 65 && int(*p) <= 90)
            *p =char(int(*p)+32);
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    const char* p = str;
    int check=0;
    for (; *p != '\0'; p++) {
        if (*p == ch) {
            check = 1;
            break;
        }
    }
    if (check == 1)
        return p - str + 1;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL|| substr==NULL)
        return 0;
    int t = 0;
    const char* p = str;
    const char* psub = substr;
    const char* src=NULL ;
    for (; ; ) {
        if (*p == *substr) {
            src = p;
            for (; *psub != '\0'; p++, psub++) {
                if (*p == *psub)
                    t++;
                if (*psub == '\0')
                    break;
            }
        }
        else{
            p++;
            
        }
        if (t == tj_strlen(substr))
            break;
        else {
            if(t>0){
                p = src + 1;
                psub = substr;
            }
        }
        if (*p == '\0')
            break;
        t = 0;
    }
    if (t == tj_strlen(substr))
        return src-str+1 ;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return 0;
    const char* p = str+tj_strlen(str)-1;
    int check = 0;
    for (;  ; p--) {
        if (*p == ch) {
            check = 1;
            break;
        }
        if (p == str)
            break;
    }
    if (check == 1)
        return p - str + 1;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL || substr == NULL)
        return 0;
    int t = 0;
    const char* p = str+ tj_strlen(str) - 1;
    const char* psub = substr;
    const char* src = NULL;
    for (; ; ) {
        if (*p == *substr) {
            src = p;
            for (; *psub != '\0'; p++, psub++) {
                if (*p == *psub)
                    t++;
                if (*psub == '\0')
                    break;
            }
        }
        else {
            p--;
        }
        if (t == tj_strlen(substr))
            break;
        else {
            if (t > 0) {
                p = src - 1;
                psub = substr;
            }
        }
        if (p+1 == str)
            break;
        t = 0;
    }
    if (t == tj_strlen(substr))
        return src - str + 1;
    else
        return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL)
        return NULL;
    else {
        char* p = str;
        if (tj_strlen(str) % 2 == 0) {
            for(;p-str<=tj_strlen(str)/2-1;p++){
                char ch = *p;
                *p = *(str + tj_strlen(str) - 1 - (p - str));
                *(str + tj_strlen(str) - 1 - (p - str)) = ch;
            }
        }
        else {
            for (; p - str <= (tj_strlen(str) + 1) / 2 - 1; p++) {
                char ch = *p;
                *p = *(str + tj_strlen(str) - 1 - (p - str));
                *(str + tj_strlen(str) - 1 - (p - str)) = ch;
            }
                
        }
    }
    return str;
}
