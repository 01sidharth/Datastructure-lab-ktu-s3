#include<stdio.h>
#include<stdlib.h>
# define size 20
struct node
{
 char val;
 struct node *lc;
 struct node *rc;
};




void root(char x[])
{
 char ch;
 printf("\n Enter the root node value : ");
 scanf(" %c",&ch);
 x[1]=ch;

}

int search(char ch[],int index, char key)
{
 int temp;
 int i=index;

 if(i>size)
  return 0;

 else
 {
  if(ch[i] == key)
   return i;
  
  if(2*i>size)
    return 0;

  else
  {
    temp=search(ch,2*i,key);

    if(temp!=0)
     return temp;

    else
    {
      if(2*i+1>size)
        return 0;
      else
        return search(ch,2*i+1,key);
    }
  }
 }
}

    
void insert(char ch[],char data)
{
 int l,n;
 char key;
 printf(" Enter the parent to search : ");
 scanf(" %c",&key); 

 l=search(ch,1,key);
 if(l==0)
  printf("\n Search unsuccessful !!!\n");

 if(ch[2*l]=='\0' || ch[2*l+1]=='\0')
 {
  printf("\n Enter option in which data has to be inserted 1-Left, 2-Right : ");  
  scanf("%d",&n); 
  
  if(n==1)
  { 
   if(ch[2*l]=='\0')
    ch[2*l]=data;
   else
    printf("\n Insertion not possible at left \n");
  }

  if(n==2)
  {
   if(ch[2*l+1]=='\0')
    ch[2*l+1]=data;
   else
    printf("\n Insertion not possible at right \n");
  }
 }

 else
  printf("\n Insertion not possible !!!\n");
}

void delete(char ch[], char key)
{
 int l,i;
 int p=0;
 l=search(ch,1,key);

  if(l==0)
    printf("\n Search unsuccessful !!!\n");

  if((ch[2*l]=='\0') && (ch[2*l+1]=='\0'))
  {
    p=1;
    ch[l]='\0';
    printf("\n Deleted successfully !!!\n");  
  }
  else
    printf("\n Node is not a leaf node \n");

  if(p==0)
    printf("\n Node does not exit : No Deletio \n");
}

void display(char ch[], int index, int level)
{
 int i=index, j;
 if(i<size)
 {
   if((2*i)+1<size)
    display(ch,((2*i)+1),level+1);
   printf("\n");

  for(j=0 ; j<level; j++)
   printf("\t");

  printf(" %c",ch[i]);

   if((2*i)<size)
    display(ch,(2*i),level+1);
 }
}

void inorder(char ch[],int index)
{
 int i=index;
 if(ch[i]!='\0')
 {
  inorder(ch,2*i);
  printf(" %c ",ch[i]);
  inorder(ch,2*i+1);
 }

}

void preorder(char ch[],int index)
{
 int i=index;
 if(ch[i]!='\0')
 {
  printf(" %c ",ch[i]);
  preorder(ch,2*i);
  preorder(ch,2*i+1);
 }

}

void postorder(char ch[],int index)
{
 int i=index;
 if(ch[i]!='\0')
 {
  postorder(ch,2*i);
  postorder(ch,2*i+1);
  printf(" %c ",ch[i]);
 }

}



void root_ll(struct node *head)
{
 char ch;
 printf("\n Enter the root node value : ");
 scanf(" %c",&ch);
 head->val=ch;

}

struct node *search_ll(struct node *head, char key)
{
 struct node *ptr, *temp;
 ptr=head;
 if(ptr->val != key)
 {
   if(ptr->lc != NULL)
   {
    temp=search_ll(ptr->lc,key);
 
    if(temp!=NULL)
    return temp;
   
    else
    {
     temp=search_ll(ptr->rc,key);
     return temp;
    }
   }
 } 
 else
  return ptr;
}

void insert_ll(struct node *head,char data)
{
 char key;int n;
 printf(" Enter the parent to search : ");
 scanf(" %c",&key); 
 struct node *ptr, *new;
 ptr=search_ll(head,key);

 if(ptr==NULL)
  printf("\n Search unsuccessful !!!\n");

 new=malloc(sizeof(struct node));
 new->val=data;
 new->lc=NULL;
 new->rc=NULL;

 if(ptr->lc==NULL || ptr->rc==NULL)
 {
  printf("\n Enter option in which data has to be inserted 1-Left, 2-Right : ");  
  scanf("%d",&n); 
  
  if(n==1)
  { 
   if(ptr->lc==NULL)
   {
    ptr->lc=new;
  }
   else
    printf("\n Insertion not possible at left \n");
  }

  if(n==2)
  {
   if(ptr->rc==NULL)
   {
    ptr->rc=new;
   }
   else
    printf("\n Insertion not possible at right \n");
 }
}

 else
  printf("\n Insertion not possible !!!\n");
}

void display_ll(struct node *head, int level)
{
 int j;
 struct node *ptr;
 ptr=head;

  if(ptr->rc!=NULL)
    display_ll(ptr->rc,level+1);
   printf("\n");

  for(j=0 ; j<level; j++)
   printf("\t");

  printf(" %c",ptr->val);

  if(ptr->lc!=NULL)
    display_ll(ptr->lc,level+1);
} 

void inorder_ll(struct node *head)
{
 struct node *ptr;

 ptr=head;
 
 if(ptr->lc!=NULL)
  inorder_ll(ptr->lc);
 printf(" %c ",ptr->val);
 if(ptr->rc!=NULL)
  inorder_ll(ptr->rc);
}

void preorder_ll(struct node *head)
{
 struct node *ptr;

 ptr=head;

 printf(" %c ",ptr->val); 
 if(ptr->lc!=NULL)
  preorder_ll(ptr->lc);
 if(ptr->rc!=NULL)
  preorder_ll(ptr->rc);
}

void postorder_ll(struct node *head)
{
 struct node *ptr;

 ptr=head;

 if(ptr->lc!=NULL)
  postorder_ll(ptr->lc);
 if(ptr->rc!=NULL)
  postorder_ll(ptr->rc);
 printf(" %c ",ptr->val); 
}

struct node *delete_ll(struct node *head, char key)
{
 struct node *ptr=head;
 if(ptr==NULL)
  return (NULL);
 ptr->lc=delete_ll(ptr->lc,key);
 ptr->rc=delete_ll(ptr->rc,key);

 if((ptr->val==key) && (ptr->lc==NULL) && (ptr->rc==NULL))
  return(NULL);
 return ptr;
}

/*struct node *search_parent(struct node *head, char key)
{
 struct node *ptr, *parent, *ptr1, *ptr2, *temp; char temp1;

 parent=head;

 ptr1=parent->lc;
 ptr2=parent->rc;
 temp1=ptr1->val;
 
 if(temp1 != key)
 {
    temp=search_parent(ptr1,key);

    if(temp != NULL)
      return parent;

    else
    {
      temp=search_parent(ptr2,key);
      return parent;
    }
  }
  else
    return parent;
}

void delete_ll(struct node *head, char key)
{
 struct node *ptr, *parent, *ptr1, *ptr2;

 ptr=head;

 parent=search_ll(ptr,key);

 if(ptr==NULL)
  printf("\n Tree empty\n");

 if(parent!=NULL)
 {
   ptr1=parent->lc;
   ptr2=parent->rc;
  
   if(ptr1->val == key)
   {
     if((ptr1->lc==NULL ) && (ptr1->rc==NULL))
      parent->lc=NULL;

     else
      printf("\n Node does not exit : No Deletion \n");
   }

   else
   {
     if((ptr2->lc==NULL ) && (ptr2->rc==NULL))
       parent->rc=NULL;

     else
       printf("\n Node does not exit : No Deletion \n");
   }
 }
 else
  printf("\n Node with data does not exit : Deletion fails!\n");
}*/


void tree_array()
{
 int c1,c2;
 char key,data;
 char ch[20];
 
 for(int i=0;i<20;i++)
 ch[i]='\0';

 root(ch);
 
   
 do
 {
  printf("\n 1-Insert a new node \n 2-Search \n 3-Delete a node \n 4-Display \n 5-Inorder Traverse \n 6-Preorder Traverse \n 7-Postorder Traverse \n 0-Exit\n");
  printf("\n Enter your choice : ");
  scanf("%d",&c1);

  switch(c1)
  {
    case 1 : printf("\n Inserting a new node ");
             printf("\n Enter the data to insert : ");
             scanf(" %c",&data);   
             insert(ch,data);
             break;

    case 2 : printf("\n Enter the data to search : ");
             scanf(" %c",&key);
             int r = search(ch,1,key);

             if(r==0)
              printf("\n Value is not present in the tree!\n");
             else
               printf("\n Value is present in the tree!\n");
             break;
 
    case 3 : printf("\n Deleting a  node \n");
             printf("\n Enter the data to delete : ");
             scanf(" %c",&data); 
             delete(ch,data); 
             break;

    case 4 : printf("\n Displaying : \n");
             display(ch,1,0);
             printf("\n");
             break;

    case 5 : printf("\n\n Inorder Traverse \n");
             inorder(ch,1);
             printf("\n");
             break;

    case 6 : printf("\n\n Preorder Traverse \n");
             preorder(ch,1);
             printf("\n");
             break;

    case 7 : printf("\n\n Postorder Traverse \n");
             postorder(ch,1);
             printf("\n");
             break;
    
    case 0 : printf("\n Exiting !!!");
             break;
   }
  }while(c1!=0);
}

void tree_list()
{
 int c2;char data,key;
 struct node *head,*r;
 head=malloc(sizeof(struct node));
 root_ll(head);

 do
 {
  printf("\n 1-Insert a new node \n 2-Search \n 3-Delete a node \n 4-Display\n 5-Inorder Traverse \n 6-Preorder Traverse \n 7-Postorder Traverse \n 0-Exit");
  printf("\n Enter your choice : ");
  scanf("%d",&c2);

  switch(c2)
  {
    case 1 : printf("\n Inserting a new node ");
             printf("\n Enter the data to insert : ");
             scanf(" %c",&data);   
             insert_ll(head,data);
             break;

   case 2 : printf("\n Enter the data to search : ");
            scanf(" %c",&key);
             r =search_ll(head,key);
            if(r==NULL)
             printf("\n Value is not present in the tree!\n");
            else
              printf("\n Value is present in the tree!\n");
            break;

   case 3 : printf("\n Deleting a  node \n");
            printf("\n Enter the data to delete : ");
            scanf(" %c",&data); 
            delete_ll(head,data); 
            break;

  case 4 : printf("\n Displaying : \n");
           display_ll(head,0);
           printf("\n");
           break;

  case 5 : printf("\n Inorder Traverse \n");
           inorder_ll(head);
           printf("\n");
           break;

  case 6 : printf("\n Preorder Traverse \n");
           preorder_ll(head);
           printf("\n");
           break;

  case 7 : printf("\n Postorder Traverse \n");
           postorder_ll(head);
           printf("\n");
           break;

  case 0 : printf("\n Exiting !!!");
           break;
  }
 }while(c2!=0);
}
 

int main()
{
 int c;
 do
 {
   printf("\n 1-Binary Operations using aray \n 2-Binary Operations using linked list \n 0-Exit\n");
   printf("\n Enter your choice : ");
   scanf("%d",&c);
   
   switch(c)
   {
   case 1: tree_array();
           break;
   case 2: tree_list();
           break;
   case 0: printf("\n Exiting !!!");
           break;
   }
 }while(c!=0);
return 0;
}      

