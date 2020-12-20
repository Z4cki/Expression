#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendChar(char * s, char c)
{
    size_t len = strlen(s);
    if (len < 254)
    {
        s[len] = c;
        s[len + 1] = '\0';
    }
    else 
    {
        printf("Not enough space\n");
    }

}

int main()
{

    // c stores the current character, current_op the last operand detected
    char c, current_op;

    // the build number
    char current_num[256] = "";

    // indicates if a number is currently being build
    int num_flag = 0;

    float a;

    printf("Enter expression: ");


    while ((c = getchar()) != '\n')
    {
        // subtract '0' gives us the numeric value         
        if (c - '0' < 0)
        {
            num_flag = 1;
        }
        // if we have got an actual number
        else
        {
            appendChar(current_num, c - '0');
        }
        
        if(num_flag)
        {
            float f = (float) *current_num;
            switch (current_op) 
            {
            case '+':
                a += f;
                break;
            case '-':
                a -= f;
                break;
            case '*':
                a *= f;
                break;
            case '/':
                a /= f;
                break;
            default:
                a = f;
            }
            num_flag = 0;
            current_num[0] = '\0';
        }

        if (c - '0' < 0)
        {
            current_op = c;
        }

    }
    

    printf("Value of expression: %.1f\n\n", a);

    // pause the console, must include stdlib.h
    system("pause");                       
    return 0;
}