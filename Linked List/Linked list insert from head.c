#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next;
};

void addFirst(struct node **head, int value);
void display(struct node* head);
int main()
{
	int item, size;
	struct node* head = NULL;
	printf("Enter how many node you want to Insert: ");
	scanf_s("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		printf("Enter data in %dst node: ", i);
		scanf_s("%d", &item);
		addFirst(&head, item);
	}
	display(head);
}

void addFirst(struct node **head,int value)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = *head;
	*head = newnode;
}

void display(struct node*head)
{
	struct node* temp;
	int i=1;
	temp = head;
	while (temp != NULL)
	{
		printf("Data in node %d = %d\n", i, temp->data);
		temp = temp->next;
		i++;
	}
}
