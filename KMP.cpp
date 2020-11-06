#include <iostream>
using namespace std;

#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

int Index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}