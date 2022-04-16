#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int data;
	struct node* left, * right;
};

struct node* create()
{
	int data;
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data (press -1 for no child): ");
	scanf_s("%d", &data);
	if (data == -1)
	{
		return 0;
	}
	else
	{
		newnode->data = data;
		printf("Enter data for left child: %d\n", data);
		newnode->left = create();
		printf("Enter data for right child: %d\n", data);
		newnode->right = create();
		return newnode;
	}
}
void main()
{
	struct node* root;
	root = create();
}