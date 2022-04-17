#include<stdio.h>


struct node{
    int data;
    struct node *next;
};

void addFirst(struct node **head, int val)
{
    struct node *newnode =(struct node *) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = *head;
    *head = newnode;
}

void display(struct node **head)
{
    struct node *temp;
    temp = head;
    while (temp!= NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node *head = NULL;
    int data,i,size;
    printf("Enter the size of the list: ");
    scanf("%d",& size);
    for(i = 0; i<size; i++)
    {
        /*printf("Enter the value of the node %d : ", i+1);
        scanf("%d", &data);*/
        addFirst(&head, data);
    }

    display(head);
    return 0;

}
