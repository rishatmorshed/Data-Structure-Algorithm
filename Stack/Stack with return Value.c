#include<stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(top == MAXSIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek()
{
    return stack[top];

}
int pop()
{
    int data;
    if(!isFull())
    {
        data = stack[top];
        top--;
        return data;
    }
    else
    {
        printf("\nStack is Underflow");
    }
}
int push(int data)
{
    if(!isFull())
    {
        top= top+1;
        stack[top] = data;
    }
    else
    {
        printf("\nStack is Overflow");
    }
}
int main()
{
    int i;
    push(10);
    push(20);
    push(30);

    for(i = top; i>=0; i--)
    {
        printf("Data %d = %d\n", i, stack[i]);
    }
    int pk = peek();
    printf("peek data = %d\n", pk);
//    while(!isEmpty())
//    {
//        int data = pop();        // this is for pop value and print data.
//        printf("%d\n", data);
//    }

}