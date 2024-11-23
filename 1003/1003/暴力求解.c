#include <stdio.h>
#include <limits.h>  // ���� INT_MIN
#include <stdlib.h>
void find_max_sum_brute_force(int n, int* arr, int* max_sum, int* start_pos, int* end_pos) {
    *max_sum = INT_MIN;  // ��ʼ��Ϊ�����ȷ�����ҵ���ȷ�����ֵ
    for (int i = 0; i < n; i++) {        // ö�����������
        for (int j = i; j < n; j++) {    // ö���������յ�
            int current_sum = 0;
            for (int k = i; k <= j; k++) {  // ���㵱ǰ�����еĺ�
                current_sum += arr[k];
            }
            if (current_sum > *max_sum) {   // ����ҵ�����ĺͣ����½��
                *max_sum = current_sum;
                *start_pos = i + 1;  // ��ĿҪ����ʼλ�ô� 1 ��ʼ
                *end_pos = j + 1;    // ��ĿҪ�����λ�ô� 1 ��ʼ
            }
        }
    }
}

int main() {
    int t; // ������������
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