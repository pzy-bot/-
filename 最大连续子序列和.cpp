#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
���⣺ 
����n������������Ϊ��������ɵ�����a[1],a[2],a[3],��,a[n],���������a[i]+a[i+1]+��+a[j]���Ӷκ͵����ֵ��
��������������Ϊ����ʱ�����Ӷκ�Ϊ0�����˶��壬���������ֵΪ�� Max{0,a[i]+a[i+1]+��+a[j]},1<=i<=j<=n
���磬����a[1],a[2],a[3],a[4],a[5],a[6]��=(-2,11,-4,13,-5,-2)ʱ������Ӷκ�Ϊ20��
*/

int maxsequence(int arr[], int len)
{
    int max = arr[0]; //��ʼ�����ֵΪ��һ��Ԫ��
    for (int i = 0; i < len; i++) {
        int sum = 0; //sum��������
        for (int j = i; j < len; j++) { //��λ��i��ʼ�����i��ʼ��������������к͵Ĵ�С���������max�������max��
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
    printf("��������Ҫ���������������������10��\n");
    int num = 10;
    scanf("%d", &num);
    if (num <= 0) {
        printf("����ĸ������ԣ��˳�����");
        return 0;
    }
    printf("������һ�β�����%d�����������У������Կո�Ϊ�������д��������Ч����\n",num);
    int i = 0, arr[10];
    do {
        scanf("%d", &arr[i]);
        if (i >= num) break;
        i++;
    } while (getchar() != '\n');
    printf("����Ӷκ�Ϊ%d", maxsequence(arr, i));

    return 0;
}