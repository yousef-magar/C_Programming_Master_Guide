```c
#include <stdio.h>

int main(){

    // Calculator Program

    char operator = '\0';
    double number01 = 0.0;
    double number02 = 0.0;
    double result = 0.0;

    printf("Enter the First number: ");
    scanf("%.2lf", &number01);

    printf("Enter the Operator (+ - * /): ");
    scanf(" %c", &operator);  // Clear \n from input buffer.

    printf("Enter the Second number: ");
    scanf("%.2lf", &number02);

    switch (operator)
    {
        case '+':
            result = number01 + number02;
            break;
        case '-':
            result = number01 - number02;
            break;
        case '*':
            result = number01 * number02;
            break;
        case '/':
            if(number02 == 0)
            {
                printf("U cann't divide by zero\n");
            }
            else
            {
                result = number01 / number02;
            }
            break;
        
        default:
            printf("Invalid Operator\n");
            break;
    }

    printf("Result = %.2lf", result);
    return 0;
}
```
