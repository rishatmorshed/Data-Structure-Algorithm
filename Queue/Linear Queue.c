#include<stdio.h>
#include<conio.h>
#define size 5     // This is called marco definition
int queue[size];  // here we are use static memory location using array
int front = -1;
int rear = -1;

void enqueue()
{
	int data;
	printf("Enter data in queue: ");
	scanf_s("%d", &data);
	if (rear == size-1)
	{
		printf("\nQueue is full\n");
	}
	else if (front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = data;
	}
	else
	{
		rear++;
		queue[rear] = data;
	}
}

void dequeue()
{
	if (front == -1 && rear == -1)
	{
		printf("\nQueue is empty\n");
	}
	else if (rear == front)
	{
		rear = front = -1;
	}
	else
	{
		printf("\nDequeue item is = %d\n", queue[front]);
		front++;
	}
}
void peek()
{
	if (front == -1 && rear == -1)
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		printf("\nPeek data is = %d\n", queue[front]);
	}
}
void display()
{
	printf("\n");
	for (int i = front; i <= rear; i++)
	{
		printf("Data available in the queue : %d\n", queue[i]);
	}
}
void main()
{
	int choice;
	do
	{
		printf("\npress 1 for Enqueue");
		printf("\npress 2 for Dequeue");
		printf("\npress 3 for peek data");
		printf("\npress 4 for Display data");
		printf("\nEnter your choice: ");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: enqueue();
			break;
		case 2: dequeue();
			break;
		case 3: peek();
			break;
		case 4: display();
			break;
		default: printf("\nInvalid Input!!!\n");
			break;
		}

	} while (choice != 0);  
	{
		_getch();
	}
	
}





