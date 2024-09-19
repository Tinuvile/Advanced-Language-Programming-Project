#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int s = 0, j = 0, m = 0;
int ss[10] = { 0 }, jj[10] = { 0 }, mm[10] = { 0 };
int i = 1;

void input();
int panduan1(int a[]);
int panduan2(int c[]);
void jisuan1(int d, int a[], int b[], int c[]);
void shuchu1(int d, int a[]);
void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst);

int main() {
    input();
    return 0;
}

void input() {
    // 输入汉诺塔的层数和起始柱目标柱
    int d;
    char qs, zj, mb;
    printf("Enter the number of disks: ");
    scanf("%d", &d);
    printf("Enter the initial, auxiliary, and target pegs (e.g., A B C): ");
    scanf(" %c %c %c", &qs, &zj, &mb);

    // 初始化第一个柱子上的盘子
    for (int k = 0; k < d; k++) {
        ss[k] = d - k;
    }

    // 开始移动盘子
    output(d, d, qs, zj, mb, ss, jj, mm, qs, zj, mb);
}

int panduan1(int a[]) {
    if (a == ss) {
        s--;
        return (s + 1);
    }
    else if (a == jj) {
        j--;
        return (j + 1);
    }
    else if (a == mm) {
        m--;
        return (m + 1);
    }
    else {
        return 0;
    }
}

int panduan2(int c[]) {
    if (c == ss) {
        s++;
        return (s - 1);
    }
    else if (c == jj) {
        j++;
        return (j - 1);
    }
    else if (c == mm) {
        m++;
        return (m - 1);
    }
    else {
        return 0;
    }
}

void jisuan1(int d, int a[], int b[], int c[]) {
    int ka, kc, j, k;
    ka = d - (j = panduan1(a));
    kc = d - (k = panduan2(c));
    c[kc - 1] = a[ka];
    a[ka] = 0;
}

void shuchu1(int d, int a[]) {
    for (int p = d - 1; p >= 0; p--) {
        if (a[p] != 0) {
            printf("%2d ", a[p]);
        }
        else {
            printf("   ");
        }
    }
    for (int p = 10 - d; p > 0; p--) {
        printf("   ");
    }
}

void output(int d, int n, char qs, char zj, char mb, int a[], int b[], int c[], char src, char tmp, char dst) {
    jisuan1(d, a, b, c);
    printf("Step %4d (%2d): %c-->%c\n", i++, n, qs, mb);

    if ((src == 'a' || src == 'A') && (dst == 'b' || dst == 'B')) {
        printf("A: ");
        shuchu1(d, ss);
        printf("B: ");
        shuchu1(d, mm);
        printf("C: ");
        shuchu1(d, jj);
        printf("\n");
    }
    else if ((src == 'a' || src == 'A') && (dst == 'c' || dst == 'C')) {
        printf("A: ");
        shuchu1(d, ss);
        printf("B: ");
        shuchu1(d, jj);
        printf("C: ");
        shuchu1(d, mm);
        printf("\n");
    }
    else if ((src == 'b' || src == 'B') && (dst == 'c' || dst == 'C')) {
        printf("A: ");
        shuchu1(d, jj);
        printf("B: ");
        shuchu1(d, ss);
        printf("C: ");
        shuchu1(d, mm);
        printf("\n");
    }
    else if ((src == 'b' || src == 'B') && (dst == 'a' || dst == 'A')) {
        printf("A: ");
        shuchu1(d, mm);
        printf("B: ");
        shuchu1(d, ss);
        printf("C: ");
        shuchu1(d, jj);
        printf("\n");
    }
    else if ((src == 'c' || src == 'C') && (dst == 'b' || dst == 'B')) {
        printf("A: ");
        shuchu1(d, jj);
        printf("B: ");
        shuchu1(d, mm);
        printf("C: ");
        shuchu1(d, ss);
        printf("\n");
    }
    else if ((src == 'c' || src == 'C') && (dst == 'a' || dst == 'A')) {
        printf("A: ");
        shuchu1(d, mm);
        printf("B: ");
        shuchu1(d, jj);
        printf("C: ");
        shuchu1(d, ss);
        printf("\n");
    }
}