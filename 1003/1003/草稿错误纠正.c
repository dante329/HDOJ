#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int* Sub_sum(int n, int* arr)
{
	int i = 0;
	int sum = 0;
	int start = 0;
	int end = 0;
	int* result = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		//子序列的第一项肯定要为正数
		if (arr[i] > 0)
		{
			sum += arr[i];
			start = i;
			result[1] = start + 1;
			break;
		}
		//从第一个正数开始往后加 如果下一项为负数要判断是否值得加一个负数
	}
	for (; i < n; i++)
	{
		if (arr[i + 1] >= 0)
		{
			sum += arr[i + 1];
		}
		else//进了else就确定arr[i + 1]是负数
		{

			//算法有缺陷
			if (i < n-2 && arr[i + 1] > -arr[i + 2]) //arr[i + 2] > abs(arr[i + 1]) #include <math.h>
			{
				sum += arr[i + 1];
			}
			else
			{
				end = i;
				result[2] = end + 1;
				result[0] = sum;
				return result;//result是一个局部变量，出了函数后会自动销毁，是无法将数据带出函数的，需要malloc一个指针将数据带出函数（malloc的内存开辟在堆内存上）
			}
		}
	}
}

int main()
{
	int t;
	int d = 1;
	scanf("%d", &t);
	while (t--)
	{
		//将数据读取并存储完毕
		int n;
		scanf("%d", &n);
		int* arr = (int*)malloc(n * sizeof(int));
		int i = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", arr + i);
		}
		//for (i = 0; i < n; i++)
		//{
		//	printf("%d ", arr[i]);
		//}

		//进行计算：连续的子数组的和最大
		int* ret = Sub_sum(n, arr);//将数组的大小n和携带数据的数组传入函数中,返回值用一个整形指针接收
		printf("Case %d:\n", d++);
		printf("%d %d %d\n", ret[0], ret[1], ret[2]);
		if (t != 0)
		{
			printf("\n");
		}
		free(arr);
		free(ret);
	}
	return 0;
}

