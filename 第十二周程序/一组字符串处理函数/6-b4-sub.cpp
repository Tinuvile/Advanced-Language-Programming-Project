/* 2352495 张竹和 信16 */

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
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return 0;
    }
    const char* str_s = str;
    for (; *str != '\0'; str++) {
        if (*str == '\0')
            break;
        else
            continue;
    }
    return (str - str_s); //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL || s2 == NULL) {
        return s1;
    }
    int n = tj_strlen(s1);
    char* s1_1 = s1 + n;
    for (; *s2 != '\0'; s1_1++, s2++) {
        *s1_1 = *s2;
    }
    *s1_1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL || s2 == NULL) {
        return s1;
    }
    int n = tj_strlen(s1);
    const char* s2_1 = s2;
    char *s1_1 = s1 + n;
    int i = 0, judge = 0;
    for (; s2 - s2_1 < len; s1_1++, s2++) {
        if (*s2 == '\0') {
            *s1_1 = *s2;
            judge = 1;
            break;
        }
        else {
            *s1_1 = *s2;
            continue;
        }
    }
    if (judge == 0) {
        *s1_1 = '\0';
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
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) {
        return s1;
    }
    if (s2 == NULL) {
        *s1 = '\0';
        return s1;
    }
    int n = tj_strlen(s2);
    char* s1_1 = s1;
    for (; *s2!='\0'; s1_1++, s2++) {
        *s1_1 = *s2;
    }
    *s1_1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL || s2 == NULL) {
        return s1;
    }
    int n = tj_strlen(s2);
    if (len < n)
        n = len;
    char* s1_1 = s1;
    int i;
    for (i = 0; i < n; i++, s1_1++, s2++) {
        *s1_1 = *s2;
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
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) {
        if (s2 == NULL) {
            return 0;
        }
        else
            return -1;
    }
    else if (s2 == NULL) {
        return 1;
    }
    int n1 = tj_strlen(s1);
    int n2 = tj_strlen(s2);
    int n;
    if (n1 >= n2)
        n = n1;
    else
        n = n2;
    int t = 0;
    const char* p1 = s1, * p2 = s2;
    for (int i = 0; i < n; i++, p1++, p2++) {
        if ((int(*p1)) != (int(*p2))) {
            t = (int(*p1)) - (int(*p2));
            break;
        }
        else
            continue;
    }
    return t;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) {
        if (s2 == NULL) {
            return 0;
        }
        else
            return -1;
    }
    else if (s2 == NULL) {
        return 1;
    }
    int n1 = tj_strlen(s1);
    int n2 = tj_strlen(s2);
    int n;
    if (n1 >= n2)
        n = n1;
    else
        n = n2;
    int s11, s22;
    int t = 0;
    const char* p1 = s1, * p2 = s2;
    for (int i = 0; i < n; i++, p1++, p2++) {
        s11 = int(*p1);
        s22 = int(*p2);
        if (s11 >= 'A' && s11 <= 'Z') {
            s11 = int(*p1) + 32;
        }
        if (s22 >= 'A' && s22 <= 'Z') {
            s22 = int(*p2) + 32;
        }
        if (s11 != s22) {
            t = s11 - s22;
            break;
        }
        else
            continue;
    }
    return t;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) {
        if (s2 == NULL) {
            return 0;
        }
        else
            return -1;
    }
    else if (s2 == NULL) {
        return 1;
    }
    int n1 = tj_strlen(s1);
    int n2 = tj_strlen(s2);
    int n;
    if (n1 >= n2)
        n = n2;
    else
        n = n1;
    if (len <= n)
        n = len;
    else
        n = n + 1;
    int t = 0;
    const char* p1 = s1, * p2 = s2;
    for (int i = 0; i < n; i++, p1++, p2++) {
        if ((int(*p1)) != (int(*p2))) {
            t = (int(*p1)) - (int(*p2));
            break;
        }
        else
            continue;
    }
    return t;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL) {
        if (s2 == NULL) {
            return 0;
        }
        else
            return -1;
    }
    else if (s2 == NULL) {
        return 1;
    }
    int n1 = tj_strlen(s1);
    int n2 = tj_strlen(s2);
    int n;
    if (n1 >= n2)
        n = n2;
    else
        n = n1;
    if (len <= n)
        n = len;
    else
        n = n + 1;
    int s11, s22;
    int t = 0;
    const char* p1 = s1, * p2 = s2;
    for (int i = 0; i < n; i++, p1++, p2++) {
        s11 = int(*p1);
        s22 = int(*p2);
        if (s11 >= 'A' && s11 <= 'Z') {
            s11 = int(*p1) + 32;
        }
        if (s22 >= 'A' && s22 <= 'Z') {
            s22 = int(*p2) + 32;
        }
        if (s11 != s22) {
            t = s11 - s22;
            break;
        }
        else
            continue;
    }
    return t;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return str;
    }
    int n = tj_strlen(str);
    char* p = str;
    for (int i = 0; i < n; i++, p++) {
        if ((*p >= 'a') && (*p <= 'z')) {
            *p = char(int(*p) - 32);
        }
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
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return str;
    }
    int n = tj_strlen(str);
    char* p = str;
    for (int i = 0; i < n; i++, p++) {
        if ((*p >= 'A') && (*p <= 'Z')) {
            *p = char(int(*p) + 32);
        }
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
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return 0;
    }
    int n = tj_strlen(str);
    int judge = 0;
    int i = 0;
    const char* p = str;
    for (i; i < n; i++, p++) {
        if (*p == ch) {
            judge = i + 1;
            break;
        }
    }
    return judge;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL) {
        return 0;
    }
    int n = tj_strlen(str);
    int m = tj_strlen(substr);
    int judge = 0;
    int i = 0;
    const char* p1 = str, * p2 = substr;
    for (int i = 0; i <= n - m; i++, p1++) {
        int found = 1;
        const char* temp_p1 = p1; // 保存当前位置
        const char* temp_p2 = p2;
        for (int j = 0; j < m; j++, temp_p1++, temp_p2++) {
            if (*temp_p1 != *temp_p2) {
                found = 0;
                break;
            }
        }
        if (found) {
            judge = i + 1;
            break;
        }
    }
    return judge;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return 0;
    }
    int n = tj_strlen(str);
    int judge = 0;
    int i = n - 1;
    const char* p = str + n - 1;
    for (i; i >= 0; i--, p--) {
        if (*p == ch) {
            judge = i + 1;
            break;
        }
    }
    return judge;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || substr == NULL) {
        return 0;
    }
    int n = tj_strlen(str);
    int m = tj_strlen(substr);
    int judge = 0;
    int i = 0;
    const char* p1 = str + n - m, * p2 = substr;
    for (int i = n - m; i >= 0; i--, p1--) {
        int found = 1;
        const char* temp_p1 = p1;
        const char* temp_p2 = p2;
        for (int j = 0; j < m; j++,temp_p1++,temp_p2++) {
            if (*temp_p1 != *temp_p2) {
                found = 0;
                break;
            }
        }
        if (found) {
            judge = i + 1;
            break;
        }
    }
    return judge;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return str;
    }
    int n = tj_strlen(str);
    char* p1 = str;
    char* p2 = str + n - 1;
    for (int i = 0; i < n / 2; i++, p1++, p2--) {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
    return str;
}