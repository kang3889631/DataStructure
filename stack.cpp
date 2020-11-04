#include <iostream>
using namespace std;

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;
} Sqstack;

// InitStack
void InitStack(Sqstack &S)
{
    S.top = -1;
}

// check if stack empty
bool StackEmpty(Sqstack S)
{
    return (S.top == -1);
}

// Push
bool Push(Sqstack &S, int x)
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

// Pop
bool Pop(Sqstack &S, int &x)
{
    if (S.top == -1)
        return false;

    x = S.data[S.top--];
    return true;
}

// GetTop
bool GetTop(Sqstack &S, int &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}
// Main function
int main()
{
    Sqstack S;
    InitStack(S);
    if (StackEmpty(S))
        printf("empty\n");

    return 0;
}