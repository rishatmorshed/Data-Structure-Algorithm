#include <stdio.h>
void Call_By_Value(int num1)
{
num1=42;
printf("\nInside Function, Number is %d", num1);
}

int main()
{
int num;
num=24;
printf("\nBefore Function, Number is %d", num);
Call_By_Value(num);
printf("\nAfter Function, Number is %d\n", num);
return 0;
}
