#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LEN 15

int main()
{
	int N;
	scanf("%d", &N);
	char (*arr)[MAX_COLOR_LEN+1] = (char(*)[MAX_COLOR_LEN+1])malloc(N * sizeof(char[MAX_COLOR_LEN+1]));
	if (arr == NULL)
	{
		perror("arr");
		exit(1);
	}
	char (*color_reset)[MAX_COLOR_LEN+1] = (char(*)[MAX_COLOR_LEN+1])malloc(N * sizeof(char[MAX_COLOR_LEN + 1]));
	int* count = (int*)calloc(N , sizeof(int));//一定要用calloc初始化，count中有可能后面的位置用不完，但是可能会参与比较
	if (N != 0)
	{
		int i = 0;
		for (i = 0; i < N; i++)
		{
			scanf("%s", arr + i);
		}
		
		//color_reset[i] = arr[i];//color_reset[i]和arr[i]都是地址，不能这样赋值，数组名不是一个可直接赋值修改的左值	
		int color_types = 0;
		for (i = 0; i < N; i++)//fori是为了取出arr中的每个颜色
		{
			int flag = 0;
			int j = 0;
			for (j = 0; j < color_types; j++)//forj是为了将arr中的每个颜色与color_reset里面的每个颜色作比较
			{
				if (strcmp(arr[i], color_reset[j]) == 0)
				{
					count[j]++;
					flag = 1;
					break;
				}				
			}
		if(flag == 0)
		{
			strcpy(color_reset[j], arr[i]);
			color_types++;
			count[color_types] = 1;//count[color_types]++;也可以，count[color_types] = 1防未初始化
		}			
		}
		int max_count = 0;
		char max_color[MAX_COLOR_LEN + 1];
		for (int a = 0; a < color_types; a++)
		{
			if (count[a] > max_count)
			{
				max_count = count[a];
				strcpy(max_color, color_reset[a]);
			}
		}
		printf("%s\n", max_color);
	}
	

	free(arr);
	free(color_reset);
	free(count);
	return 0;
}