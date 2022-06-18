#include<stdio.h>
#include<stdlib.h>
int n;

struct node
{
  int data;
  struct node *next;
};
struct node *chain[20];

int hash_function(int key, int n)
{
   return key%n;
}

int linear_prob(int key, int h[], int n)
{
   int index;
   index = hash_function(key,n);

   if(key == h[index])
      return index;

   else
   {
      int i=index % n;
      do
      {
         if(h[i]==0)
         {
           h[i]=key;
           return i;
         }

         else if(h[i]==key)
           return i;

         else
           i=(i+1)%n;
      }while(i != index);
      
      return -1;
  }
}                               

void display_linear(int h[], int n)
{
  printf("\n INDEX  :  KEY   \n");
  for(int i=0; i<n; i++)
    printf("     %d  :  %d \n",i,h[i]);
} 

void chaining(int key)
{
   int index;
   struct node *temp;
   temp = (struct node *)malloc(sizeof(struct node));
   temp->data = key;
   temp->next = NULL;

   index = hash_function(key,n);

   if(chain[index] == NULL)
      chain[index] = temp;

   else
   {
      struct node *temp1 = chain[index];
      while(temp1->next)
         temp1 = temp1->next;
      temp1->next = temp;
   }
} 

void display_chaining()
{
  printf("\n INDEX  :  KEY   \n");        
  for(int i=0; i<n; i++)
  {
     struct node *temp = chain[i];
     printf("     %d  :  ",i);
     while(temp)
     {
        printf("%d -> ",temp->data);
        temp = temp->next;
     }      
     printf(" NULL \n");
  }
}

void main()
{
   int ch,key,i,index,c;
   
   printf("\n Enter the size of hash table : ");
   scanf("%d", &n);

   int h[n];

   for(i=0;i<n;i++)
       h[i]=0;

   do
   {
     printf("\n 1-Linaer Probing \n 2-Chaining\n 0-Exit \n Enter your choice : ");
     scanf("%d",&ch);

     switch(ch)
     {
       case 1: printf("\n Enter the value : ");
               scanf("%d",&key);
               index=linear_prob(key,h,n);
               if(index==-1)
                  printf("\n Hash table is full !!! \n");
               else
                  printf("\n %d is stored at index %d\n",key,index);
               display_linear(h,n);
               break;

       case 2: printf("\n Enter the value : ");
               scanf("%d",&key);
               chaining(key);
               display_chaining();
               break;

       case 0: printf("\n Exiting !!! \n ");
               break;

       default:printf("\n Invalid choice !!!\n ");
    }
   }while(ch!=0);
}


