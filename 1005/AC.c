#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main() {
	int a, b, n, start, len;   //start为循环起点，len为循环长度
	while (scanf("%d%d%d", &a, &b, &n) == 3 && (a || b || n)) {   //a，b，n同时为0时退出循环
		n--;            //将n变成数组下标
		start = len = 0;
		int f[51] = { 1,1 };            //保存前51项的数组
		for (int i = 2; i < 51; i++) {
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;    //计算m[i]
			for (int j = i - 1; j > 0; j--) {        //从i-1往前找j，使得m[i]==m[j]&&m[i-1]==m[j-1],从而确定循环起点以及循环长度
				if (f[i] == f[j] && f[i - 1] == f[j - 1]) {
					start = j - 1;
					len = i - j;
					break;
				}
			}
			if (len > 0)       //当第一次找到start，len之后退出循环
				break;
		}
		if (n < start)
			printf("%d\n", f[n]);
		else
			printf("%d\n", f[start + (n - start) % len]);
	}
	return 0;
}