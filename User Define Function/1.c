#include <stdio.h>
void addNumbers();         // function prototype

int main()
{

    addNumbers();        // function call
    return 0;
}

void addNumbers()         // function definition
{
    int n1, n2, result;

    printf("Enters two numbers: ");
    scanf("%d %d",&n1,&n2);

    result = n1+n2;
    printf("%d", result);                  // return statement
}
