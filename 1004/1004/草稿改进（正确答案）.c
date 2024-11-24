//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_COLOR_LEN 15
//#define MAX_BALLOONS 1000
//
//int main() {
//    while (1) {
//        int N;
//        scanf("%d", &N);
//        if (N == 0) {
//            break;  // 如果 N 为 0，退出程序
//        }
//
//        // 动态分配内存用于存储气球颜色
//        char(*colors)[MAX_COLOR_LEN + 1] = (char(*)[MAX_COLOR_LEN + 1])malloc(N * sizeof(char[MAX_COLOR_LEN + 1]));
//        int* count = (int*)calloc(N, sizeof(int)); // 记录颜色出现的次数
//        int unique_count = 0; // 独立颜色计数
//
//        if (colors == NULL || count == NULL) {
//            perror("Memory allocation failed");
//            exit(1);
//        }
//
//        // 读取气球颜色
//        for (int i = 0; i < N; i++) {
//            char color[MAX_COLOR_LEN + 1];
//            scanf("%s", color);
//
//            // 检查是否已经记录过此颜色
//            int found = 0;
//            for (int j = 0; j < unique_count; j++) {
//                if (strcmp(colors[j], color) == 0) {
//                    count[j]++;
//                    found = 1;
//                    break;
//                }
//            }
//
//            // 如果是新颜色，加入数组
//            if (!found) {
//                strcpy(colors[unique_count], color);
//                count[unique_count] = 1;
//                unique_count++;
//            }
//        }
//
//        // 找出出现次数最多的颜色
//        int max_count = 0;
//        char most_popular_color[MAX_COLOR_LEN + 1];
//        for (int i = 0; i < unique_count; i++) {
//            if (count[i] > max_count) {
//                max_count = count[i];
//                strcpy(most_popular_color, colors[i]);
//            }
//        }
//
//        // 输出结果
//        printf("%s\n", most_popular_color);
//
//        // 释放动态内存
//        free(colors);
//        free(count);
//    }
//
//    return 0;
//}
