#include <iostream>
using namespace std;

#define MaxSize 10
typedef struct
{
    char data[MaxSize];
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
bool Push(Sqstack &S, char x)
{
    if (S.top == MaxSize - 1)
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

// Pop
bool Pop(Sqstack &S, char &x)
{
    if (S.top == -1)
        return false;

    x = S.data[S.top--];
    return true;
}

// GetTop
bool GetTop(Sqstack &S, char &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

bool Checkbracket(char str[], int length)
{
    Sqstack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]);
        }
        else
        {
            if (StackEmpty(S))
                return false;
            char topElem = Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    printf("\n");
    return true;
}

// Main function
int main()
{
    char a[] = "((()))";
    Checkbracket(a, 6);
    return 0;
}