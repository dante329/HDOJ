#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int fun(int a, int b, int n)
{
	if (n == 0)	exit(-1);
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return (a * fun(a,b,n - 1) + b * fun(a,b,n - 2)) % 7;
}

int main()
{
	int a=1, b=1, n=1;
	while (a != 0 && b != 0 && n != 0)
	{
		scanf("%d%d%d", &a, &b, &n);
		int ret = fun(a, b, n);
		printf("%d", ret);
	}
	return 0;
}