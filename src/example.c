#include <stdio.h>
#include <stdlib.h>

//#define __DEBUG
#ifdef __DEBUG
int main()
{
    char c;
    float a;

    while ((c = getchar()) != '\n')
    {
        c = c - '0';
        a = (float) c;
        printf("%c\n", c);
    }
    system("pause");
}

#endif // __DEBUG