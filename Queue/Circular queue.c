#include<stdio.h>
#include<conio.h>
#define size 5
int queue[size];
int front = -1;
int rear = -1;

void enqueue()
{
	int data;
	printf("Enter data in queue: ");
	scanf_s("%d", &data);
	if ((rear + 1) % size == front)  /* this is for circular queue. 
									 1st condition check queue empty or not*/
	{
		printf("\nQueue is Full\n");
	}
	else if (front == -1 && rear == -1)  /*2nd condition when queue is empty and 
										 you want to insert 1st data*/
	{
		front = rear = 0;
		queue[rear] = data;
	}
	else
	{
		rear = (rear + 1) % size;   /*3rd condition for when some data present in queue
									and you want to insert more*/
		                             // find rear index for circular queue
		queue[rear] = data;			// insert data into rear index
	}
}

void dequeue()
{
	if (front == -1 && rear == -1)
	{
		printf("\nQueue is empty\n");
	}
	else if (rear == front)  /* if rear and front point same index that means only one
							    element left in queue */
	{
		rear = front = -1;
	}
	else
	{
		printf("\nDequeue item is = %d\n", queue[front]);
		front = (front + 1) % size;
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
	int i = front;
	while (i != rear)
	{
		printf("\n");
		printf("Data present in the Queue = %d", queue[i]);
		i = (i + 1) % size;
	}
	printf("\nData present in the Queue = %d", queue[i]);  /*This print rest element of 
														   the queue*/
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