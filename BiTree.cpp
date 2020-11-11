#include <iostream>
using namespace std;

struct ElemType
{
    int value;
};

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// Define an empty tree
BiTree root = NULL;

// Iterate all
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
}

int main()
{
    // Insert root node
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;

    // Insert new node
    BiTNode *p = (BiTree)malloc(sizeof(BiTNode));
    p->data = {1};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p;
}
