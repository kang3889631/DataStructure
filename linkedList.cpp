#include <iostream>
using namespace std;

typedef struct Node
{
    int value;
    struct Node *next;
} Node, *LinkedList;

void InitLinkedList(LinkedList &L)
{
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
}

int main()
{
    LinkedList L;
    InitLinkedList(L);
    L->value = 2;
    printf("L value: %d\n", L->value);
}