#include <stdlib.h>
#include <stdio.h>
#define InitSize 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

void InitList(SeqList L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// Dynamic increase the length
void IncreaseSize(SeqList L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

int GetElem(SeqList L, int i)
{
    return L.data[i - 1];
}

int main()
{
    // gcc -o list list.c
    // ./list

    SeqList L;
    InitList(L);
    printf("%d\n", L.MaxSize);
    for (int i = 0; i < L.MaxSize; i++)
    {
        L.data[i] = i;
        printf("%d\n", L.data[i]);
    }
    // L.data[11] = 11;

    //    for (int i = 0; i < 10; i++)
    //    {
    //        printf("%d\n", L.data[i]);
    //    }
    //    // printf("%d\n", L.data[11]);
    //    printf("%d\n", GetElem(L, 5));

    // IncreaseSize(L, 5);

    return 0;
}