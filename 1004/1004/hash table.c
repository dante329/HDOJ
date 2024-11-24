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
//    char color[MAX_COLOR_LEN + 1]; // ��ɫ�ַ���
//    int count;                     // ���ִ���
//} HashNode;
//
//int main() {
//    while (1) {
//        int N;
//        scanf("%d", &N);
//        if (N == 0) {
//            break; // N Ϊ 0 ʱ����ֹ����
//        }
//
//        // ��ϣ��ĳ�ʼ��
//        HashNode hashTable[MAX_BALLOONS] = { 0 }; // �ٶ���� 1000 ����ɫ
//        int unique_count = 0; // ��ϣ�������е���ɫ����
//
//        // ��ȡ��ɫ�����¹�ϣ��
//        for (int i = 0; i < N; i++) {
//            char color[MAX_COLOR_LEN + 1];
//            scanf("%s", color);
//
//            // ������ϣ������Ƿ��Ѿ����ڸ���ɫ
//            int found = 0;
//            for (int j = 0; j < unique_count; j++) {
//                if (strcmp(hashTable[j].color, color) == 0) {
//                    hashTable[j].count++; // ������ڣ�������һ
//                    found = 1;
//                    break;
//                }
//            }
//
//            // ���������ɫ�������ϣ��
//            if (!found) {
//                strcpy(hashTable[unique_count].color, color);
//                hashTable[unique_count].count = 1;
//                unique_count++;
//            }
//        }
//
//        // �ҵ����ִ���������ɫ
//        int max_count = 0;
//        char most_popular_color[MAX_COLOR_LEN + 1];
//        for (int i = 0; i < unique_count; i++) {
//            if (hashTable[i].count > max_count) {
//                max_count = hashTable[i].count;
//                strcpy(most_popular_color, hashTable[i].color);
//            }
//        }
//
//        // ������
//        printf("%s\n", most_popular_color);
//    }
//
//    return 0;
//}
