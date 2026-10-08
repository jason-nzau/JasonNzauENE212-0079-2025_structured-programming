#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    double num1, num2;
    char operate;
    printf("Enter your problem here: ");
    scanf("%lf %c %lf", &num1, &operate, &num2);
    if (operate == '+') printf("Result: %lf\n", num1 + num2);
    if (operate == '-') printf("Result: %lf\n", num1 - num2);
    if (operate == '*') printf("Result: %lf\n", num1 * num2);
    if (operate == '/') printf("Result: %lf\n", num1 / num2);
    return 0;
}
