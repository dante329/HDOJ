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
//            break;  // ��� N Ϊ 0���˳�����
//        }
//
//        // ��̬�����ڴ����ڴ洢������ɫ
//        char(*colors)[MAX_COLOR_LEN + 1] = (char(*)[MAX_COLOR_LEN + 1])malloc(N * sizeof(char[MAX_COLOR_LEN + 1]));
//        int* count = (int*)calloc(N, sizeof(int)); // ��¼��ɫ���ֵĴ���
//        int unique_count = 0; // ������ɫ����
//
//        if (colors == NULL || count == NULL) {
//            perror("Memory allocation failed");
//            exit(1);
//        }
//
//        // ��ȡ������ɫ
//        for (int i = 0; i < N; i++) {
//            char color[MAX_COLOR_LEN + 1];
//            scanf("%s", color);
//
//            // ����Ƿ��Ѿ���¼������ɫ
//            int found = 0;
//            for (int j = 0; j < unique_count; j++) {
//                if (strcmp(colors[j], color) == 0) {
//                    count[j]++;
//                    found = 1;
//                    break;
//                }
//            }
//
//            // ���������ɫ����������
//            if (!found) {
//                strcpy(colors[unique_count], color);
//                count[unique_count] = 1;
//                unique_count++;
//            }
//        }
//
//        // �ҳ����ִ���������ɫ
//        int max_count = 0;
//        char most_popular_color[MAX_COLOR_LEN + 1];
//        for (int i = 0; i < unique_count; i++) {
//            if (count[i] > max_count) {
//                max_count = count[i];
//                strcpy(most_popular_color, colors[i]);
//            }
//        }
//
//        // ������
//        printf("%s\n", most_popular_color);
//
//        // �ͷŶ�̬�ڴ�
//        free(colors);
//        free(count);
//    }
//
//    return 0;
//}
