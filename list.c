#include <stdio.h>
int mergeLists(int La[], int La_len, int Lb[], int Lb_len, int Lc[]) {
    int i = 0; // 指向 La 的指针
    int j = 0; // 指向 Lb 的指针
    int k = 0; // 指向 Lc 的指针
int main() {
    // 定义两个已排序的数组
    int list_a[] = {1, 3, 5, 7};
    int list_b[] = {2, 4, 6, 8, 10};
    
    int len_a = sizeof(list_a) / sizeof(list_a[0]);
    int len_b = sizeof(list_b) / sizeof(list_b[0]);

    // 创建一个足够大的数组来存放结果
    int list_c[len_a + len_b];

    // 调用合并函数
    int len_c = mergeLists(list_a, len_a, list_b, len_b, list_c);

    // 打印结果
    printf("合并后的列表: ");
    for (int i = 0; i < len_c; i++) {
        printf("%d ", list_c[i]);
    }
    printf("\n");

    return 0;
}