#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


void find_max_sum(int n, int* arr, int* max_sum, int* start_pos, int* end_pos) {
    int current_sum = 0;
    int temp_start = 0;
    *max_sum = arr[0];  // 初始化最大和为数组第一个元素
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
        printf("%d %d %d\n", max_sum, start_pos + 1, end_pos + 1);  // 输出 1-based 索引
        if (t < T) {
            printf("\n");
        }
    }

    return 0;
}

//局部最优性：如果当前子序列的和变成负数，则不可能对后续子序列产生积极的贡献，应丢弃当前子序列（即重置为 0，从下一位置重新开始）。
//全局最优性：每次更新局部子序列和时，检查是否为当前最大的和，如果是，则更新全局最大和

/*
为什么要重置 current_sum 为 0？
如果子序列的和为负数，任何新的元素加入这个子序列都会降低和的值，因此应从下一个位置重新开始计算。

如何记录子序列的起始和结束位置？
当 current_sum 被更新为新的最大值时，记录起始位置 temp_start 和当前索引 i。
当 current_sum 被重置为 0 时，更新 temp_start 为下一个元素的位置。

数组全为负数时的处理：
Kadane 的算法能够正确处理这种情况，因为初始 max_sum 被设置为第一个元素，最终的结果就是所有负数中最大的那个。
*/