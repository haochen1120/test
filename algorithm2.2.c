#include <stdio.h>

/**
 * @brief 合并两个有序数组为一个有序数组
 * 
 * @param La[] 第一个有序数组 (非递减)
 * @param La_len 第一个数组的长度
 * @param Lb[] 第二个有序数组 (非递减)
 * @param Lb_len 第二个数组的长度
 * @param Lc[] 用于存放合并结果的数组
 * @return int 合并后数组 Lc 的长度
 */
int mergeLists(int La[], int La_len, int Lb[], int Lb_len, int Lc[]) {
    int i = 0; // 指向 La 的指针
    int j = 0; // 指向 Lb 的指针
    int k = 0; // 指向 Lc 的指针

    // 1. 当两个数组都还有元素时，比较并放入较小的元素到 Lc
    while (i < La_len && j < Lb_len) {
        if (La[i] <= Lb[j]) {
            Lc[k++] = La[i++];
        } else {
            Lc[k++] = Lb[j++];
        }
    }

    // 2. 如果 La 中还有剩余元素，将它们全部复制到 Lc
    while (i < La_len) {
        Lc[k++] = La[i++];
    }

    // 3. 如果 Lb 中还有剩余元素，将它们全部复制到 Lc
    while (j < Lb_len) {
        Lc[k++] = Lb[j++];
    }

    return k; // 返回新数组的长度
}

// --- 主函数用于测试 ---
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