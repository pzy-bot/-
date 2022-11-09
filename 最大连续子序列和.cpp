#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
问题： 
给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n],求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。
当所给的整数均为负数时定义子段和为0，依此定义，所求的最优值为： Max{0,a[i]+a[i+1]+…+a[j]},1<=i<=j<=n
例如，当（a[1],a[2],a[3],a[4],a[5],a[6]）=(-2,11,-4,13,-5,-2)时，最大子段和为20。
*/

int maxsequence(int arr[], int len)
{
    int max = arr[0]; //初始化最大值为第一个元素
    for (int i = 0; i < len; i++) {
        int sum = 0; //sum必须清零
        for (int j = i; j < len; j++) { //从位置i开始计算从i开始的最大连续子序列和的大小，如果大于max，则更新max。
            sum += arr[j];
            if (sum > max)
                max = sum;
        }
    }
    if (max < 0)
        return 0;
    else
        return max;
}

int main() {
    printf("请输入需要输入的整数个数（不超过10也不能小于1）\n");
    int num = 10;
    scanf("%d", &num);
    if (num <= 0 || num > 10) {
        printf("输入的个数不对，退出程序。");
        return 0;
    }
    printf("请输入一段不超过%d个整数的序列（数据以空格为间隔，多写的数据无效）：\n",num);
    int i = 0, arr[10];
    do {
        scanf("%d", &arr[i]);
        if (i >= num) break;
        i++;
    } while (getchar() != '\n');
    //int arr[10] = { -1,-2,-3,-4,5,-9,7,-8,-9 ,-10 };//测试用例
    //int i = 10;//测试用例
    printf("最大子段和为%d", maxsequence(arr, i));

    return 0;
}
