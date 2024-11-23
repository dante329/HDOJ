#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//以下版本在hdoj中无法通过，并且在vs中编译时会报错

//第一版 
//int main()
//{
//	//要求一并读取，一并输出
//	int t;
//	int i = 0;
//	char num1[1000], num2[1000];
//	scanf("%d", &t);
//	char(*pArr1[t])[1000] = { 0 };//数组指针的数组
//	char(*pArr2[t])[1000] = { 0 };
//	//将t条数据存入数组指针数组pArr1，pArr2
//	for (i = 0; i < t; i++)
//	{
//		scanf("%s%s", pArr1[i], pArr2[i]);//pArr1[i]取出第i个元素是指针类型，无需&
//	}
//
//	//输出模块，循环运算并输出
//	for (i = 0; i < t; i++)
//	{
//		//a，b相加
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
//		//第一行是“Case #:”，# 表示测试用例的编号
//		printf("Case %d:\n", i + 1);
//		//第二行是等式“A + B = Sum”，Sum 表示 A + B 的结果
//		printf("%s + %s = %s\n\n", num1, num2, result);
//	}
//
//	free(result);
//
//}
//return 0;
//}

//第二版
int main()
{
	int t;
	int i = 0;
	char num1[1000], num2[1000];
	scanf("%d", &t);
	//改动：以下数组指针数组使用错误，数组中的每个元素都是一个数组指针，而指针如果没有开辟空间是没法使用的
	//char(*pArr1[t])[1000] = { 0 };
	//char(*pArr2[t])[1000] = { 0 };
	
	//以下为改动后
	//char* pArr1[t];		
	//char* pArr2[t];		
	//for (i = 0; i < t; i++)
	//{
	//	pArr1[i] = (char*)malloc(sizeof(char[1000]));
	//	pArr2[i] = (char*)malloc(sizeof(char[1000]));
	//}
	//如果不支持变长数组，以上pArr1和pArr2的初始化可以写成下面这样!!
	char (*pArr1)[1000] = malloc(t * sizeof(*pArr1));
	char (*pArr2)[1000] = malloc(t * sizeof(*pArr2));
	
	for (i = 0; i < t; i++)
	{
		//改动：pArr1[i] 是一个指向 1000 个字符数组的指针，但在代码中直接将输入存入 pArr1[i] 和 pArr2[i]，没有分配实际的存储空间，会导致未定义行为。
		scanf("%s%s", pArr1[i], pArr2[i]);//通过上面的for循环将pArr1和pArr2中的每个指针都初始化了，现在可以正常访问
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

		free(result);//改动：每次循环开头malloc内存，结尾就要释放，等出了循环再释放会造成内存泄露
	}

	//free(result);
	free(pArr1);
	free(pArr2);

	return 0;
}



////第三版，使用了二维数组代替for循环malloc分配指针空间
//int main() {
//    int t, i;
//    scanf("%d", &t);
//
//    // 定义二维数组，每行存放一个字符串
//    char pArr1[1][1000];
//    char pArr2[1][1000];
//
//    // 输入 t 对字符串
//    for (i = 0; i < t; i++) {
//        scanf("%s %s", pArr1[i], pArr2[i]);
//    }
//
//    // 输出每对字符串的加法结果
//    for (i = 0; i < t; i++) {
//        int len1 = strlen(pArr1[i]);
//        int len2 = strlen(pArr2[i]);
//        int maxLen = len1 > len2 ? len1 : len2;
//
//        // 分配一个足够存储结果的数组
//        char* result = (char*)malloc(maxLen + 2);  // 结果字符串，最多需要 maxLen+1 位 + '\0'
//        result[maxLen + 1] = '\0';  // 确保末尾是'\0'
//
//        int carry = 0;
//        int p1 = len1 - 1, p2 = len2 - 1, k = maxLen;
//
//        // 逐位加法，从右到左进行
//        while (p1 >= 0 || p2 >= 0 || carry) {
//            int digi1 = p1 >= 0 ? pArr1[i][p1--] - '0' : 0;
//            int digi2 = p2 >= 0 ? pArr2[i][p2--] - '0' : 0;
//
//            int sum = digi1 + digi2 + carry;
//            carry = sum / 10;  // 计算进位
//            result[k--] = (sum % 10) + '0';  // 存储当前位的数字
//        }
//
//        // 输出当前案例的结果
//        printf("Case %d:\n", i + 1);
//        printf("%s + %s = %s\n\n", pArr1[i], pArr2[i], result + k + 1);  // 输出时跳过多余的前导零
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
//     动态分配内存，存储 t 个长度为 1000 的字符数组
//    char(*pArr1)[1000] = malloc(t * sizeof(*pArr1));
//    char(*pArr2)[1000] = malloc(t * sizeof(*pArr2));
//
//     输入超长整数
//    for (i = 0; i < t; i++) {
//        scanf("%s %s", pArr1[i], pArr2[i]);
//    }
//
//     处理每个测试用例
//    for (i = 0; i < t; i++) {
//        int len1 = strlen(pArr1[i]);
//        int len2 = strlen(pArr2[i]);
//        int maxLen = len1 > len2 ? len1 : len2;
//
//         为结果分配内存
//        char* result = (char*)malloc(maxLen + 2);
//        result[maxLen + 1] = '\0';  // 结果的末尾是 '\0'
//
//        int carry = 0;
//        int p1 = len1 - 1, p2 = len2 - 1, k = maxLen;
//
//         从最低位开始逐位相加
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
//         输出结果
//        printf("Case %d:\n", i + 1);
//        printf("%s + %s = %s\n\n", pArr1[i], pArr2[i], result);
//
//         释放结果字符串的内存
//        free(result);
//    }
//
//     释放 pArr1 和 pArr2 分配的内存
//    free(pArr1);
//    free(pArr2);
//
//    return 0;
//}
