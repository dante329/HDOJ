#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���°汾��hdoj���޷�ͨ����������vs�б���ʱ�ᱨ��

//��һ�� 
//int main()
//{
//	//Ҫ��һ����ȡ��һ�����
//	int t;
//	int i = 0;
//	char num1[1000], num2[1000];
//	scanf("%d", &t);
//	char(*pArr1[t])[1000] = { 0 };//����ָ�������
//	char(*pArr2[t])[1000] = { 0 };
//	//��t�����ݴ�������ָ������pArr1��pArr2
//	for (i = 0; i < t; i++)
//	{
//		scanf("%s%s", pArr1[i], pArr2[i]);//pArr1[i]ȡ����i��Ԫ����ָ�����ͣ�����&
//	}
//
//	//���ģ�飬ѭ�����㲢���
//	for (i = 0; i < t; i++)
//	{
//		//a��b���
//		int lenth1 = strlen(pArr1[i]);
//		int lenth2 = strlen(pArr2[i]);
//		int maxLen = lenth1 > lenth2 ? lenth1 : lenth2;
//
//		char* result = (char*)malloc(maxLen + 2);
//		result[maxLen + 1] = '\0';
//
//		int carry = 0;
//		int i = lenth1 - 1, j = lenth2 - 1, k = maxLen;
//
//		while (i >= 0 || j >= 0 || carry)
//		{
//			int digi1 = i >= 0 ? pArr1[i][i--] - '0' : 0;
//			int digi2 = j >= 0 ? pArr2[i][j--] - '0' : 0;
//
//			int sum = digi1 + digi2 + carry;
//
//			carry = sum / 10;
//
//			result[k--] = (sum % 10) + '0';
//		}
//		result + k + 1;
//		//��һ���ǡ�Case #:����# ��ʾ���������ı��
//		printf("Case %d:\n", i + 1);
//		//�ڶ����ǵ�ʽ��A + B = Sum����Sum ��ʾ A + B �Ľ��
//		printf("%s + %s = %s\n\n", num1, num2, result);
//	}
//
//	free(result);
//
//}
//return 0;
//}

//�ڶ���
int main()
{
	int t;
	int i = 0;
	char num1[1000], num2[1000];
	scanf("%d", &t);
	//�Ķ�����������ָ������ʹ�ô��������е�ÿ��Ԫ�ض���һ������ָ�룬��ָ�����û�п��ٿռ���û��ʹ�õ�
	//char(*pArr1[t])[1000] = { 0 };
	//char(*pArr2[t])[1000] = { 0 };
	
	//����Ϊ�Ķ���
	//char* pArr1[t];		
	//char* pArr2[t];		
	//for (i = 0; i < t; i++)
	//{
	//	pArr1[i] = (char*)malloc(sizeof(char[1000]));
	//	pArr2[i] = (char*)malloc(sizeof(char[1000]));
	//}
	//�����֧�ֱ䳤���飬����pArr1��pArr2�ĳ�ʼ������д����������!!
	char (*pArr1)[1000] = malloc(t * sizeof(*pArr1));
	char (*pArr2)[1000] = malloc(t * sizeof(*pArr2));
	
	for (i = 0; i < t; i++)
	{
		//�Ķ���pArr1[i] ��һ��ָ�� 1000 ���ַ������ָ�룬���ڴ�����ֱ�ӽ�������� pArr1[i] �� pArr2[i]��û�з���ʵ�ʵĴ洢�ռ䣬�ᵼ��δ������Ϊ��
		scanf("%s%s", pArr1[i], pArr2[i]);//ͨ�������forѭ����pArr1��pArr2�е�ÿ��ָ�붼��ʼ���ˣ����ڿ�����������
	}
	
	for (i = 0; i < t; i++)
	{	
		int lenth1 = strlen(pArr1[i]);
		int lenth2 = strlen(pArr2[i]);
		int maxLen = lenth1 > lenth2 ? lenth1 : lenth2;

		char* result = (char*)malloc(maxLen + 2);
		result[maxLen + 1] = '\0';

		int carry = 0;
		int p1 = lenth1 - 1, p2 = lenth2 - 1, k = maxLen;

		while (p1 >= 0 || p2 >= 0 || carry)
		{
			int digi1 = p1 >= 0 ? pArr1[i][p1--] - '0' : 0;
			int digi2 = p2 >= 0 ? pArr2[i][p2--] - '0' : 0;

			int sum = digi1 + digi2 + carry;

			carry = sum / 10;

			result[k--] = (sum % 10) + '0';
		}
		result = result + k + 1;
		
		printf("Case %d:\n", i + 1);
		
		printf("%s + %s = %s\n\n", pArr1[i], pArr2[i], result);

		free(result);//�Ķ���ÿ��ѭ����ͷmalloc�ڴ棬��β��Ҫ�ͷţ��ȳ���ѭ�����ͷŻ�����ڴ�й¶
	}

	//free(result);
	free(pArr1);
	free(pArr2);

	return 0;
}



////�����棬ʹ���˶�ά�������forѭ��malloc����ָ��ռ�
//int main() {
//    int t, i;
//    scanf("%d", &t);
//
//    // �����ά���飬ÿ�д��һ���ַ���
//    char pArr1[1][1000];
//    char pArr2[1][1000];
//
//    // ���� t ���ַ���
//    for (i = 0; i < t; i++) {
//        scanf("%s %s", pArr1[i], pArr2[i]);
//    }
//
//    // ���ÿ���ַ����ļӷ����
//    for (i = 0; i < t; i++) {
//        int len1 = strlen(pArr1[i]);
//        int len2 = strlen(pArr2[i]);
//        int maxLen = len1 > len2 ? len1 : len2;
//
//        // ����һ���㹻�洢���������
//        char* result = (char*)malloc(maxLen + 2);  // ����ַ����������Ҫ maxLen+1 λ + '\0'
//        result[maxLen + 1] = '\0';  // ȷ��ĩβ��'\0'
//
//        int carry = 0;
//        int p1 = len1 - 1, p2 = len2 - 1, k = maxLen;
//
//        // ��λ�ӷ������ҵ������
//        while (p1 >= 0 || p2 >= 0 || carry) {
//            int digi1 = p1 >= 0 ? pArr1[i][p1--] - '0' : 0;
//            int digi2 = p2 >= 0 ? pArr2[i][p2--] - '0' : 0;
//
//            int sum = digi1 + digi2 + carry;
//            carry = sum / 10;  // �����λ
//            result[k--] = (sum % 10) + '0';  // �洢��ǰλ������
//        }
//
//        // �����ǰ�����Ľ��
//        printf("Case %d:\n", i + 1);
//        printf("%s + %s = %s\n\n", pArr1[i], pArr2[i], result + k + 1);  // ���ʱ���������ǰ����
//    }
//
//    return 0;
//}
//
//int main() {
//    int t;
//    int i = 0;
//    scanf("%d", &t);
//
//     ��̬�����ڴ棬�洢 t ������Ϊ 1000 ���ַ�����
//    char(*pArr1)[1000] = malloc(t * sizeof(*pArr1));
//    char(*pArr2)[1000] = malloc(t * sizeof(*pArr2));
//
//     ���볬������
//    for (i = 0; i < t; i++) {
//        scanf("%s %s", pArr1[i], pArr2[i]);
//    }
//
//     ����ÿ����������
//    for (i = 0; i < t; i++) {
//        int len1 = strlen(pArr1[i]);
//        int len2 = strlen(pArr2[i]);
//        int maxLen = len1 > len2 ? len1 : len2;
//
//         Ϊ��������ڴ�
//        char* result = (char*)malloc(maxLen + 2);
//        result[maxLen + 1] = '\0';  // �����ĩβ�� '\0'
//
//        int carry = 0;
//        int p1 = len1 - 1, p2 = len2 - 1, k = maxLen;
//
//         �����λ��ʼ��λ���
//        while (p1 >= 0 || p2 >= 0 || carry) {
//            int digi1 = p1 >= 0 ? pArr1[i][p1--] - '0' : 0;
//            int digi2 = p2 >= 0 ? pArr2[i][p2--] - '0' : 0;
//
//            int sum = digi1 + digi2 + carry;
//            carry = sum / 10;
//
//            result[k--] = (sum % 10) + '0';
//        }
//
//         ������
//        printf("Case %d:\n", i + 1);
//        printf("%s + %s = %s\n\n", pArr1[i], pArr2[i], result);
//
//         �ͷŽ���ַ������ڴ�
//        free(result);
//    }
//
//     �ͷ� pArr1 �� pArr2 ������ڴ�
//    free(pArr1);
//    free(pArr2);
//
//    return 0;
//}
