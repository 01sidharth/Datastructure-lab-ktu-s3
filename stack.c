#include <stdio.h>
int stack[50],choice1,choice2,a,n,top,i,opt,queue_array[100],front=-1,rear=-1,m,cqueue[100],l,x;
void push(void);
void pop(void);
void display1(void);
void enqueue(void);
void dequeue(void);
void display2(void);
void cenqueue(int[], int);
void cdequeue(int[]);
void display3(int[]);
int main()
{
    printf("\n 1.STACK\n 2.QUEUE\n 3.CIRCULAR QUEUE");
    printf("\n Enter the Choice:");
    scanf("%d",&choice1);
   switch(choice1)
   {
    case 1:  top=-1;
             printf("\n The size of the stack is:");
             scanf("%d",&n);
            do
         {
            printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
            printf("\n Enter the Choice:");
            scanf("%d",&choice2);
            switch(choice2)
           {
            case 1:  push();
                     display1();
                     break;
            case 2:  pop();
                     display1();
                     break;
                
            case 3:  display1();
                     break;
                
            case 4:  printf("\n exit point ");
                     break;
                
            default:  printf ("\n Please Enter a Valid Choice(1/2/3/4)");
           }
           printf("\nDo you want to perform another action?(1/0):");
           scanf("%d",&opt);
      }while(opt==1);
       break;
    case 2:    printf("\n The size of the Queue is:");
              scanf("%d",&m);
               do
         {   
        printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice2);
        switch(choice2)
        {
            case 1:  enqueue();
                     display2();
                     break;
            case 2:  dequeue();
                     display2();
                     break;
                
            case 3:  display2();
                     break;
                
            case 4:  printf("\n exit point ");
                     break;
                
            default:  printf ("\n Please Enter a Valid Choice(1/2/3/4)");
        }
           printf("\nDo you want to perform another action?(1/0):");
           scanf("%d",&opt);
          }while(opt==1); 
          break;
    case 3:       printf("\n The size of the Circular Queue is:");
              scanf("%d",&l);
               do
         {   
        printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d",&choice2);
        switch(choice2)
        {
            case 1:  printf("\nEnter number: ");
                     scanf("%d", &x);
                     cenqueue(cqueue, x);
                     display3(cqueue);
                     break;
            case 2:  cdequeue(cqueue);
                     display3(cqueue);
                     break;
                
            case 3:  display3(cqueue);
                     break;
                
            case 4:  printf("\n exit point ");
                     break;
                
            default:  printf ("\n Please Enter a Valid Choice(1/2/3/4)");
        }
           printf("\nDo you want to perform another action?(1/0):");
           scanf("%d",&opt);
          }while(opt==1); 
          break;  
    default :    printf ("\n Please Enter a Valid Choice(1/2/3)");  
    printf("\nDo you want to perform another action?(1/0):");
           scanf("%d",&opt);
   }while(opt==1); 
}
void push()
{
    if(top>=n-1)
    {
        printf("\nstack is full");
        
    }
    else
    {
        printf(" Enter a value to push:");
        scanf("%d",&a);
        top++;
        stack[top]=a;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n Stack is empty");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}
void display1()
{
    if(top>=0)
    {
        printf("\n The elements in STACK are : ");
        for(i=0; i<=top; i++)
            printf(" %d  ",stack[i]);
    }
    else
    {
        printf("\n stack is empty");
    }
   
}
void enqueue()
{
    int add_item;
    if (rear == m - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        front=0;
        printf("Insert the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 
 
void dequeue()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} 
 
void display2()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 

void cenqueue(int cqueue[], int item)
{
    if ((front == 0 && rear == l - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == l - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    cqueue[rear] = item;
}

void cdequeue(int cqueue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", cqueue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", cqueue[front]);
        front++;
    }
}

void display3(int cqueue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < l; i++)
        {
            printf("%d ", cqueue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue[i]);
    }
}


