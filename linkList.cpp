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

Node *GetElem(LinkedList &L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    Node *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

Node *LocateElem(LinkedList &L, int e)
{
    Node *p = L->next;
    while (p != NULL && p->value != e)
    {
        p = p->next;
    }
    return p;
}

int Length(LinkedList &L)
{
    int len = 0;
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

bool ListInsert(LinkedList &L, int i, int e)
{
    if (i < 1)
        return false;
    Node *p = GetElem(L, i - 1);
    if (p == NULL)
        return false;
    Node *s = (Node *)malloc(sizeof(Node));
    s->value = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main()
{
    LinkedList L;
    InitLinkedList(L);
    L->value = 2;
    printf("L value: %d\n", L->value);
}