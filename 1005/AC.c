#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main() {
	int a, b, n, start, len;   //startΪѭ����㣬lenΪѭ������
	while (scanf("%d%d%d", &a, &b, &n) == 3 && (a || b || n)) {   //a��b��nͬʱΪ0ʱ�˳�ѭ��
		n--;            //��n��������±�
		start = len = 0;
		int f[51] = { 1,1 };            //����ǰ51�������
		for (int i = 2; i < 51; i++) {
			f[i] = (a * f[i - 1] + b * f[i - 2]) % 7;    //����m[i]
			for (int j = i - 1; j > 0; j--) {        //��i-1��ǰ��j��ʹ��m[i]==m[j]&&m[i-1]==m[j-1],�Ӷ�ȷ��ѭ������Լ�ѭ������
				if (f[i] == f[j] && f[i - 1] == f[j - 1]) {
					start = j - 1;
					len = i - j;
					break;
				}
			}
			if (len > 0)       //����һ���ҵ�start��len֮���˳�ѭ��
				break;
		}
		if (n < start)
			printf("%d\n", f[n]);
		else
			printf("%d\n", f[start + (n - start) % len]);
	}
	return 0;
}