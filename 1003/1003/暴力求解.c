#include <stdio.h>
#include <limits.h>  // 包含 INT_MIN
#include <stdlib.h>
void find_max_sum_brute_force(int n, int* arr, int* max_sum, int* start_pos, int* end_pos) {
    *max_sum = INT_MIN;  // 初始化为负无穷，确保能找到正确的最大值
    for (int i = 0; i < n; i++) {        // 枚举子序列起点
        for (int j = i; j < n; j++) {    // 枚举子序列终点
            int current_sum = 0;
            for (int k = i; k <= j; k++) {  // 计算当前子序列的和
                current_sum += arr[k];
            }
            if (current_sum > *max_sum) {   // 如果找到更大的和，更新结果
                *max_sum = current_sum;
                *start_pos = i + 1;  // 题目要求起始位置从 1 开始
                *end_pos = j + 1;    // 题目要求结束位置从 1 开始
            }
        }
    }
}

int main() {
    int t; // 测试用例数量
    scanf("%d", &t);

    for (int case_num = 1; case_num <= t; case_num++) {
        int n;
        scanf("%d", &n);

        int* arr = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int max_sum, start_pos, end_pos;
        find_max_sum_brute_force(n, arr, &max_sum, &start_pos, &end_pos);

        printf("Case %d:\n", case_num);
        printf("%d %d %d\n", max_sum, start_pos, end_pos);

        if (case_num < t) {
            printf("\n");
        }
    }

    return 0;
}