/*2353113 信16 李阔*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int num = 0;
    if (str == NULL)
        return 0;
    for (const char* pch = str;*pch!='\0'; pch++) {
        num++;
    }

    return num;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
        if (*ps1 >= 65 && *ps1 <= 90)   //都把ASCII码转成小写字母
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
        if (*ps1 >= 65 && *ps1 <= 90)   //都把ASCII码转成小写字母
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
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
