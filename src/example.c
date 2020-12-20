#include <stdio.h>
#include <stdlib.h>

#ifdef __DEBUG
int main()
{
    char c;
    float a;

    while ((c = getchar()) != '\n')
    {
        c = c - '0';
        a = (float) c;
        if (a) printf("works\n");
    }
    system("pause");
}

#endif // __DEBUG