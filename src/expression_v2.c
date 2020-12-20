#include <stdio.h>
#include <stdlib.h>

int main()
{
    // c stores the current character, current_op the last operand detected
    char c, current_op;
    float a;

    printf("Enter expression: \n");

    while ((c = getchar()) != '\n')
    {
        // space, we ignore it
        if (c == 32) continue;
        // subtract '0' gives us the numeric value         
        if (c - '0' < 0) 
        {
            current_op = c;
            continue;
        }

        // if we have got a actual number we take the last operand and perform the magic
        c = c - '0';
        switch (current_op) {                                                        
        case '+':                                                           
            a += (float) c;
            break;                                                          
        case '-':                                                           
            a -= (float) c;                                                 
            break;                                                          
        case '*':                                                           
            a *= (float) c;                                                 
            break;                                                          
        case '/':                                                           
            a /= (float) c;                                                 
            break;  
        default:
            a = (float) c;                        
        }                                                         
    }

    printf("Value of expression: %.1f\n\n", a);

    // pause the console, must include stdlib.h
    system("pause");                       
    return 0;
}