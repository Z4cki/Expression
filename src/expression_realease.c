#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void appendchar(char * s, char c);
void remchar(char * s);
void appendfloat(float * f, char c);

int main()
{

    // c stores the current character, current_op the last operand detected
    char c, current_op;

    // the input line / string
    char input[256] = "";

    float result, f = 0.0;

    printf("Enter expression: \n");

    // read the input
    while ((c = getchar()) != '\n' && c != '\r')
    {
        // ignore spaces or returns
        if (c == 32 || c == 13) continue;
        if (c == '\b') 
        {
            remchar(input);
            continue;
        }
        appendchar(input, c);
    }

    size_t len = strlen(input);
    for (int i = 0; i <= len; i++)
    {
        if (i < len) c = input[i];
        else c = '+';
        // subtract '0' gives us the numeric value
        if (c - '0' < 0 || 9 < c - '0')
        {
            switch (current_op) 
            {
            case '+':
                result += f;
                break;
            case '-':
                result -= f;
                break;
            case '*':
                result *= f;
                break;
            case '/':
                result /= f;
                break;
            case '^':
                result = pow(result, f);
                break;
            default:
                result = f;
            }
            f = 0.0;
        }
        // if we have got an actual number
        else
        {
            appendfloat(&f, c - '0');
        }

        if (c - '0' < 0 || 9 < c - '0')
        {
            current_op = c;
        }
    }

    printf("Value of expression: %.1f\n\n", result);

    // pause the console, must include stdlib.h
    system("pause");                       
    return 0;
}

void appendchar(char * s, char c)
{
    size_t len = strlen(s);
    if (len < 254)
    {
        s[len] = c;
        s[len+1] = '\0';
    }
}

void remchar(char * s)
{
    size_t len = strlen(s);
    s[len-1] = '\0';
}

void appendfloat(float * f, char c)
{
    if (*f == 0.0)
    {
        *f = c;
    }
    else
    {
        *f = *f * 10 + c;
    }
}