#include<stdio.h>
int n,item;
void binsearch(int arr[20],int item)
{
    int flag=0,low=0,mid,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
        {
            flag=1;
            break;
        }
        else if(arr[mid]<=item)
            low=mid+1;
        else
            high=mid-1;
    }
    check(flag,mid+1);
}
void linearsearch(int arr[20],int item)
{
    int i=0,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            flag=1;
            break;
        }
    }
    check(flag,i+1);
}
void check(int flag,int i)
{
    if(!flag)
        printf("Element Not Found!");
    else
        printf("Element '%d' is present at position %d\n",item,i);
}
void main()
{
    int arr[20],i=0,ch;
    printf("Enter the Size of Array:\n");
    scanf("%d",&n);
    printf("Enter the Array Elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the Element to be Searched:\n");
    scanf("%d",&item);
    printf("\n1.Linear Search\n2.Binary Search\n");
    printf("\nEnter the Choice :\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
           linearsearch(arr,item);
           break;
    case 2:
            binsearch(arr,item);
            break;
    default:
            printf("Invalid Choice");
            break;
    }

}
	

