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
		//�����еĵ�һ��϶�ҪΪ����
		if (arr[i] > 0)
		{
			sum += arr[i];
			start = i;
			result[1] = start + 1;
			break;
		}
		//�ӵ�һ��������ʼ����� �����һ��Ϊ����Ҫ�ж��Ƿ�ֵ�ü�һ������
	}
	for (; i < n; i++)
	{
		if (arr[i + 1] >= 0)
		{
			sum += arr[i + 1];
		}
		else//����else��ȷ��arr[i + 1]�Ǹ���
		{

			//�㷨��ȱ��
			if (i < n-2 && arr[i + 1] > -arr[i + 2]) //arr[i + 2] > abs(arr[i + 1]) #include <math.h>
			{
				sum += arr[i + 1];
			}
			else
			{
				end = i;
				result[2] = end + 1;
				result[0] = sum;
				return result;//result��һ���ֲ����������˺�������Զ����٣����޷������ݴ��������ģ���Ҫmallocһ��ָ�뽫���ݴ���������malloc���ڴ濪���ڶ��ڴ��ϣ�
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
		//�����ݶ�ȡ���洢���
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

		//���м��㣺������������ĺ����
		int* ret = Sub_sum(n, arr);//������Ĵ�Сn��Я�����ݵ����鴫�뺯����,����ֵ��һ������ָ�����
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

