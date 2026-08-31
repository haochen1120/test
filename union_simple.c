#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SqList;

// 初始化
void InitList(SqList *L) {
    L->length = 0;
}


int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}


int ListInsert(SqList *L, int e) {
    if (L->length >= MAX_SIZE)
        return 0;
    L->data[L->length++] = e;
    return 1;
}


void unionList(SqList *La, SqList Lb) {
    for (int i = 0; i < Lb.length; i++)
        if (!LocateElem(*La, Lb.data[i]))
            ListInsert(La, Lb.data[i]);
}

// 打印
void PrintList(SqList L, char *name) {
    printf("%s = (", name);
    for (int i = 0; i < L.length; i++)
        printf("%d%s", L.data[i], i < L.length - 1 ? ", " : "");
    printf(")\n");
}

int main() {
    SqList La, Lb;
    int arr_a[] = {3, 5, 8, 11};
    int arr_b[] = {2, 6, 8, 9, 11, 15, 20};

    InitList(&La);
    InitList(&Lb);
    
    for (int i = 0; i < 4; i++) 
        ListInsert(&La, arr_a[i]);

    for (int i = 0; i < 7; i++) 
        ListInsert(&Lb, arr_b[i]);

    printf("--- 合并前 ---\n");
    PrintList(La, "La");
    PrintList(Lb, "Lb");

    unionList(&La, Lb);

    printf("\n--- 合并后 (La = La U Lb) ---\n");
    PrintList(La, "La");
    return 0;
}
