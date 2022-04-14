#include<stdio.h>
#include<conio.h>
#include "Source.h"
#define size 3	  // This is called Macro defination.
int stack[size];  //Declare globaly size. Because inside function it would be constant value like Stack[5]
int top = -1;

void push()
{
	int data;
	printf("Enter data in Stack: ");
	scanf_s("%d", &data);
	if (top == size - 1)
	{
		printf("\nStack Overflow!!!\n");
	}
	else
	{
		top++;
		stack[top] = data;
	}
}
void pop()
{
	int item;
	if (top == -1)
	{
		printf("\nStack Underflow!!!\n");
	}
	else
	{
		item = stack[top];
		top--;
		printf("Pop item is: %d\n", item);
	}
}
void peek()
{
	if (top == -1)
	{
		printf("\nStack is Empty!!!\n");
	}
	else
	{
		printf("\nTop data is currently: %d\n", stack[top]);
	}
}
void display()
{
	for (int i = top; i >= 0; i--)
	{
		printf("\nData in stack is: %d\n", stack[i]);
	}
}

void main()
{
	int ch;
	//clearerr_s;
	do
	{
		printf("\nFor push press 1: ");
		printf("\nFor pop press 2: ");
		printf("\nFor peek press 3: ");
		printf("\nFor display press 4: ");
		printf("\nEnter your choice:");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1: push();
			break;
		case 2: pop();
			printf("\nNow Data in the stack is:\n");
		case 4: display();
			break;
		case 3: peek();
			break;
		default: printf("Invalid Input!!!");
			break;
		}

	} while (ch!=0);
	_getch();
}