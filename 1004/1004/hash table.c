//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_COLOR_LEN 15
//#define MAX_BALLOONS 1000
//
//typedef struct {
//    char color[MAX_COLOR_LEN + 1]; // 颜色字符串
//    int count;                     // 出现次数
//} HashNode;
//
//int main() {
//    while (1) {
//        int N;
//        scanf("%d", &N);
//        if (N == 0) {
//            break; // N 为 0 时，终止程序
//        }
//
//        // 哈希表的初始化
//        HashNode hashTable[MAX_BALLOONS] = { 0 }; // 假定最多 1000 种颜色
//        int unique_count = 0; // 哈希表中已有的颜色数量
//
//        // 读取颜色并更新哈希表
//        for (int i = 0; i < N; i++) {
//            char color[MAX_COLOR_LEN + 1];
//            scanf("%s", color);
//
//            // 遍历哈希表，检查是否已经存在该颜色
//            int found = 0;
//            for (int j = 0; j < unique_count; j++) {
//                if (strcmp(hashTable[j].color, color) == 0) {
//                    hashTable[j].count++; // 如果存在，计数加一
//                    found = 1;
//                    break;
//                }
//            }
//
//            // 如果是新颜色，加入哈希表
//            if (!found) {
//                strcpy(hashTable[unique_count].color, color);
//                hashTable[unique_count].count = 1;
//                unique_count++;
//            }
//        }
//
//        // 找到出现次数最多的颜色
//        int max_count = 0;
//        char most_popular_color[MAX_COLOR_LEN + 1];
//        for (int i = 0; i < unique_count; i++) {
//            if (hashTable[i].count > max_count) {
//                max_count = hashTable[i].count;
//                strcpy(most_popular_color, hashTable[i].color);
//            }
//        }
//
//        // 输出结果
//        printf("%s\n", most_popular_color);
//    }
//
//    return 0;
//}
