#include <stdio.h>
#include<stdlib.h>
void display();
void create_linkedlist(int);
void insertatbeginning(int);
void insertattheend(int);
void insertatanyposition(int,int);
void deletefrombeginning();
void deletefromend();
void deletefromspecifiedposition(int);
struct node
{
    int data;
    struct node *link;
}*Node;

void main()
{
    int n,choice,data;
    do{
        printf("Linked List Operations\n");
        printf("1.Create a linked list.\n");
        printf("2.Display.\n");
        printf("3.Insert at beginning.\n");
        printf("4.Insert at end.\n");
        printf("5.Insert at a specified position.\n");
        printf("6.Delete from beginning.\n");
        printf("7.Delete from end.\n");
        printf("8.Delete from a specified position.\n");
        printf("9.Exit.\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nCreate a linked list");
            printf("\nEnter number of nodes in the linked list:");
            scanf("%d",&n);
            create_linkedlist(n);
            break;
            case 2:
            printf("\nDisplay");
            display();
            break;
            case 3:
            printf("\nInsert at beginning");
            printf("\nEnter data to be inserted at the beginning:");
            scanf("%d",&data);
            insertatbeginning(data);
            break;
            case 4:
            printf("\nInsert at end");
            printf("\nEnter data to insert at the end:");
            scanf("%d",&data);
            insertattheend(data);
            break;
            case 5:
            printf("\nInsert at a specified position");
            printf("\nEnter position to insert data at:");
            scanf("%d",&n);
            printf("\nEnter data to be inserted at position %d:",n);
            scanf("%d",&data);
            insertatanyposition(n,data);
            break;
            case 6:
            printf("\nDelete from beginning\n");
            deletefrombeginning();
            break;
            case 7:
            printf("\nDelete from end\n");
            deletefromend();
            break;
            case 8:
            printf("\nDelete from a specified position\n");
            printf("\nEnter a position to delete the data from:");
            scanf("%d",&n);
            deletefromspecifiedposition(n);
            break;
            case 9:
            printf("\nExiting...");
            break;
            default:
            printf("\nInvalid Option");
        }
        
    }while(choice!=9);
}

void create_linkedlist(int size)
{
    struct node *ptr,*tmp;
    int i,data;
    Node=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted at node 1:");
    scanf("%d",&data);
    Node->data=data;
    Node->link=NULL;
    tmp=Node;
    for(i=2;i<=size;i++)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        if(ptr==NULL)
        {
            printf("\nList is full\n");
            break;
        }
        else
        {
            printf("\nEnter data to be inserted at node %d:",i);
            scanf("%d",&data);
            
            ptr->data=data;
            ptr->link=NULL;
            tmp->link=ptr;
            tmp=tmp->link;
        }
    }
}

void insertatbeginning(int element)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = element;
    newNode->link = Node;
    Node = newNode;
}

void insertattheend(int element)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = element;
    newNode->link = NULL;

    struct node *temp = Node;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newNode;
}

void insertatanyposition(int position,int element)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = element;

    struct node *temp = Node;

    for(int i=2; i < position; i++) {
        if(temp->link != NULL) {
            temp = temp->link;
        }
    }
    newNode->link = temp->link;
    temp->link = newNode;
}

void deletefrombeginning()
{
    Node = Node->link;
}

void deletefromend()
{
    struct node* temp = Node;
    while(temp->link->link!=NULL){
        temp = temp->link;
    }
    temp->link = NULL;
}

void deletefromspecifiedposition(int position)
{
    struct node* temp = Node;
    for(int i=2; i< position; i++) {
        if(temp->link!=NULL) {
            temp = temp->link;
    }
    }
    temp->link = temp->link->link;
}
void display()
{
    struct node *temp;
    if(Node==NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        temp=Node;
        printf("\nLinked list data:\n");
        while(temp!=NULL)
        {
            printf("[%d]->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
    }
}

