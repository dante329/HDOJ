#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


void find_max_sum(int n, int* arr, int* max_sum, int* start_pos, int* end_pos) {
    int current_sum = 0;
    int temp_start = 0;
    *max_sum = arr[0];  // ��ʼ������Ϊ�����һ��Ԫ��
    *start_pos = 0;
    *end_pos = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        if (current_sum > *max_sum) {
            *max_sum = current_sum;
            *start_pos = temp_start;
            *end_pos = i;
        }

        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        int* arr = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int max_sum, start_pos, end_pos;
        find_max_sum(n, arr, &max_sum, &start_pos, &end_pos);

        printf("Case %d:\n", t);
        printf("%d %d %d\n", max_sum, start_pos + 1, end_pos + 1);  // ��� 1-based ����
        if (t < T) {
            printf("\n");
        }
    }

    return 0;
}

//�ֲ������ԣ������ǰ�����еĺͱ�ɸ������򲻿��ܶԺ��������в��������Ĺ��ף�Ӧ������ǰ�����У�������Ϊ 0������һλ�����¿�ʼ����
//ȫ�������ԣ�ÿ�θ��¾ֲ������к�ʱ������Ƿ�Ϊ��ǰ���ĺͣ�����ǣ������ȫ������

/*
ΪʲôҪ���� current_sum Ϊ 0��
��������еĺ�Ϊ�������κ��µ�Ԫ�ؼ�����������ж��ή�ͺ͵�ֵ�����Ӧ����һ��λ�����¿�ʼ���㡣

��μ�¼�����е���ʼ�ͽ���λ�ã�
�� current_sum ������Ϊ�µ����ֵʱ����¼��ʼλ�� temp_start �͵�ǰ���� i��
�� current_sum ������Ϊ 0 ʱ������ temp_start Ϊ��һ��Ԫ�ص�λ�á�

����ȫΪ����ʱ�Ĵ���
Kadane ���㷨�ܹ���ȷ���������������Ϊ��ʼ max_sum ������Ϊ��һ��Ԫ�أ����յĽ���������и����������Ǹ���
*/