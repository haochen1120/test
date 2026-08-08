/**
 * algorithm2.1.c
 *
 * 通用算法框架模板（C 语言）
 * 包含 main 函数与基本程序结构，可作为编写具体算法的起点。
 *
 * 结构说明：
 *   1. 头文件包含区
 *   2. 宏定义与常量区
 *   3. 数据结构定义区
 *   4. 函数声明区（算法核心函数）
 *   5. main 函数
 */

/* ========== 1. 头文件包含区 ========== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ========== 2. 宏定义与常量区 ========== */
#define MAX_SIZE 100       /* 数组等容量的最大尺寸 */
#define OK 0               /* 成功返回码 */
#define ERROR -1           /* 失败返回码 */

/* ========== 3. 数据结构定义区 ========== */
/* 示例：简单顺序表结构（可按需修改） */
typedef struct {
    int data[MAX_SIZE];
    int length;            /* 当前元素个数 */
} SqList;

/* ========== 4. 函数声明区（算法核心函数） ========== */

/**
 * 示例算法：顺序表顺序查找
 * @param list 顺序表指针
 * @param key  待查找的关键字
 * @return 找到返回下标，未找到返回 ERROR
 */
int SeqSearch(SqList *list, int key)
{
    int i;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] == key) {
            return i;      /* 找到，返回下标 */
        }
    }
    return ERROR;          /* 未找到 */
}

/**
 * 初始化顺序表
 */
void InitList(SqList *list)
{
    list->length = 0;
}

/* ========== 5. main 函数 ========== */
int main(void)
{
    SqList list;
    int i, key, pos;

    InitList(&list);

    /* 构造测试数据 */
    for (i = 0; i < 5; i++) {
        list.data[list.length++] = i * 2;
    }

    printf("顺序表中的数据: ");
    for (i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    /* 测试查找算法 */
    key = 6;
    pos = SeqSearch(&list, key);
    if (pos != ERROR) {
        printf("关键字 %d 位于下标 %d\n", key, pos);
    } else {
        printf("未找到关键字 %d\n", key);
    }

    return OK;
}
