#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int addFirst(struct node **head);
void addMid(struct node **head, int value);
void addEnd(struct node **head, int value);
void display(struct node* head);

struct node{
	int data;
	struct node* next;
}head;


int main()
{
	struct node* head = NULL;
	int item, size{}, ch;
	do
	{
		printf("\nPress 1 to Insert node from head:\n");
		printf("Press 2 to Insert node from middle:\n");
		printf("Press 3 to Insert node from End:\n");
		printf("Press 4 for Display the Linked List:\n");
		printf("Enter your Choice: ");
		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1: printf("\nData Insertion from Head:\n");
			size = addFirst(&head);
			break;
		case 2: printf("\nData Insertion form Middle:\n");
			addMid(&head, size);
			break;
		case 3: printf("\nData Insertion from End:\n");
			addEnd(&head, size);
			break;
		case 4: printf("\nDisplay List Data:\n");
			display(head);
			break;
		default: printf("Invalid Input!!!");
			break;
		}

	} while (ch!=0);
	 {
		_getch();
	 }
}

int addFirst(struct node** head)
{
	int item, size;
	struct node* newnode;
	printf("Enter how many node you want to Insert: ");
	scanf_s("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter data for %dst node to inserted from Head: ", i);
		scanf_s("%d", &item);
		newnode->data = item;
		newnode->next = *head;
		*head = newnode;
	}
	printf("\n");
	return size;
}

void addMid(struct node** head, int size)
{
	int posi, value, i, j=1;
	struct node* newnode, * temp;
	if (*head == NULL)
	{
		printf("\nThe list is Empty please choose option (1)\n");
	}
	else
	{
		for (i = 1; i < 2; i++)
		{
			printf("Enter the position for Insert new node: ");
			scanf_s("%d", &posi);
			if (posi > size)
			{
				printf("Invalid Position!!!");
			}
			else
			{
				temp = *head;
				while (j<posi)  // This is find the position for where temp stop
				{
					temp = temp->next;
					j++;
				}
				newnode = (struct node*)malloc(sizeof(struct node));
				printf("Enter data for %dst node to Inserted from Middle: ", i);
				scanf_s("%d", &value);
				newnode->data = value;
				newnode->next = temp->next;
				temp->next = newnode;
			}
		}
	}
}

void addEnd(struct node** head, int size)
{
	int data;
	struct node* newnode, *temp;
	if (*head == NULL)
	{
		printf("\nThe list is Empty please choose option (1)\n");
	}
	else
	{
		for (int i = 1; i <= size; i++)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			printf("Enter data for %dst node to Inserted from last: ", i);
			scanf_s("%d", &data);
			newnode->data = data;
			newnode->next = 0;
			temp = *head;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	printf("\n");
}



void display(struct node*head)
{
	struct node* temp;
	int i=1;
	temp = head;
	if (head == NULL)
	{
		printf("List is Empty!!!");
	}
	else
	{
		while (temp != NULL)
		{
			printf("Data in node %d = %d\n", i, temp->data);
			temp = temp->next;
			i++;
		}

	}
}