#define _CRT_SECURE_NO_WARNINGS 1


//正确版

#include<stdio.h>
#include<string.h>

void  Bignum_add(char* s1, char* s2, char* s)
{
    int i, j, a, l1, l2, L, t;

    l1 = strlen(s1);
    l2 = strlen(s2);
    s[0] = '0';
    a = 0;
    if (l1 > l2) L = l1;
    else L = l2;
    s[L + 1] = '\0';
    for (i = L; l1 > 0 && l2 > 0; i--)
    {
        a = (s1[--l1] - '0') + (s2[--l2] - '0') + a / 10;//a储存每一位相加后的结果，+ a/10是加上上一位的进位
        s[i] = a % 10 + '0';//a % 10 如果这一位的a大于10就只储存个位
    }
    while (l1) {
        a = (s1[--l1] - '0') + a / 10;
        s[i--] = a % 10 + '0';
    }
    while (l2) {
        a = (s2[--l2] - '0') + a / 10;
        s[i--] = a % 10 + '0';
    }
    if (a / 10 > 0)
    {
        s[i] = a / 10 + '0';//如果s1和s2是一样长的，那么进位的处理无法在while (l1)和while (l2)这两个循环中的某一个完成，需要单独拿出来处理
    }
    
    t = 0;
    while (s[t] == '0' && t < L) t++;//用t来计算高位多余的0的数量

    strcpy(s, s + t);//去除高位多余的0
}

int main()
{
    int T, d = 1;
    char s[1000], s1[1000], s2[1000];//s考虑malloc最大字符长度+2
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", s1, s2);
        Bignum_add(s1, s2, s);
        printf("Case %d:\n", d++);
        printf("%s + %s = %s\n", s1, s2, s);
        if (T != 0) printf("\n");

    }

    return 0;
}