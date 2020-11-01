#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *next;
} Node, *LinkedList;

void InitLinkedList(LinkedList &L)
{
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
}

void PrintLinkedList(LinkedList &L)
{
    Node *p = L;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf(" \n");
}

void AppendNodeToEnd(LinkedList &L, int e)
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *s = (Node *)malloc(sizeof(Node));
    s->val = e;
    s->next = NULL;
    p->next = s;
}

Node *GetElembyLocation(LinkedList &L, int i)
{
    if (i < 1)
    {
        return NULL;
    }
    Node *p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    return p;
}

int LocateElement(LinkedList &L, int e)
{
    Node *p = L;
    int count = 0;
    while (p != NULL && p->val != e)
    {
        p = p->next;
        count++;
    }
    return count;
}

bool InsertElementAti(LinkedList &L, int i, int e)
{
    Node *p = GetElembyLocation(L, i);
    if (p == NULL)
        return false;
    Node *s = (Node *)malloc(sizeof(Node));
    s->val = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertElementBeforei(LinkedList &L, int i, int e)
{
    Node *p = GetElembyLocation(L, i);
    if (p == NULL)
        return false;
    Node *s = (Node *)malloc(sizeof(Node));
    s->val = p->val;
    p->val = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool DeleteElementAti(LinkedList &L, int i)
{
    Node *p = GetElembyLocation(L, i);
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;
    Node *q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    LinkedList L;
    InitLinkedList(L);
    for (int i = 1; i < 5; i++)
    {
        AppendNodeToEnd(L, i);
    }
    Node *p = GetElembyLocation(L, 4);
    // int i = LocateElement(L, 4);
    // printf("i: %d\n", i);
    // i = LocateElement(L, 3);
    printf("before: ");
    PrintLinkedList(L);
    // if (!InsertElementAti(L, 2, 9))
    //     printf("Not insert\n");
    // if (!InsertElementBeforei(L, 3, 9))
    //     printf("Not insert\n");
    if (!DeleteElementAti(L, 2))
        printf("Not insert\n");
    printf("after: ");
    PrintLinkedList(L);
}