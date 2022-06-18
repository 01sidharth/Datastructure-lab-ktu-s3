#include<stdio.h>
int n;
void display(int x[], int n)
{
  for(int i=1 ;i<=n; i++)
   printf(" %d ",x[i]);
  printf("\n");
}

int selectmin(int a[], int i, int n)
{
  int min, minLoc, l, r;
  l=i;
  r=n;
  min=a[l];
  minLoc=l;

  for(i=l+1; i<=r; i++)
  {
   if(min>a[i])
   {
     min=a[i];
     minLoc=i;
   }
  }
  return(minLoc);
}

void SelectSort(int x[], int n)
{
  int i, temp, j;
  for(i=1 ;i<=n-1; i++)
  {
    j= selectmin(x,i,n);
    if(i!=j)
    {
     temp=x[i];
     x[i]=x[j];
     x[j]=temp;
    }
  }
}

void InsertionSort( int x[], int n)
{
 int y[n], j, i, flag, p, k;
 y[1]=x[1];

 for(j=2; j<=n; j++)
 { 
  k=x[j];
  flag=1;
  i=j-1;

  while(flag==1)
  {
   if(k<y[i])
   {
     i=i-1;
     if(i==0)
       flag=0;
   }
   else
    flag=0;
  }

  p=j;
  while(p>i+1)
  {
    y[p]=y[p-1];
    p=p-1;
  }

  y[i+1]=k;
 }

}


void create_heap(int x[], int n, int y[])
{
 int i=1, j, temp;
 while(i<=n)
 {

   y[i]=x[i];
   j=i;
 
   while(j>1)
   {
     if(y[j]>y[j/2])
     {
       temp = y[j];
       y[j] = y[j/2];
       y[j/2]=temp;
       j=j/2;
     }
 
     else
       j=1;
   }
  
   i=i+1;
 }
}
void remove_max(int x[], int i)
{
  int temp;
  
  temp=x[i];
  x[i]=x[1];
  x[1]=temp;

}

void rebuild_heap(int x[], int i)
{
  if(i==1)
    return;

  int j, flag, lc, rc, temp;

  j=1;
  flag=1;
   
  while(flag==1)
  {
    lc=2*j;
    rc=2*j+1;

    if(rc<=i)
    {
      if(x[j]<=x[lc]) 
      {
        if(x[lc]<=x[rc])
        {
          temp = x[j];
          x[j] = x[rc];
          x[rc]= temp;
          j=rc;
        }

        else
        {
          temp = x[j];
          x[j] = x[lc];
          x[lc]= temp;
          j=lc;
        }
      }

      else if(x[j]<=x[rc] && x[rc]>=x[lc])
      {
          temp = x[j];
          x[j] = x[rc];
          x[rc]= temp;
          j=rc;
      }
    
      else
         flag=0;
    }

   else if(lc<=i)
   {
      if(x[j]<=x[lc])
      {      
         temp = x[j];
         x[j] = x[lc];
         x[lc]= temp;
          j=lc;
      }
      else
         flag=0;
   }

   else
     flag=0;
  }
}

void HeapSort(int x[], int n, int y[])
{
 create_heap(x,n,y);
 for(int i=n ;i>1; i--)
 {
   remove_max(y,i);
   rebuild_heap(y,i-1);
 }
}

int Partition(int x[], int left, int right)
{
  int loc=left, temp;
  while(left<right)
  {
    while(x[loc] <= x[right] && loc<right)  
     right--;

    if(x[loc]>x[right])
    {
      temp=x[loc];
      x[loc]=x[right];
      x[right]=temp;
      loc=right;
      left++;
    }

    while(x[loc] >= x[left] && loc>left)  
     left++;

    if(x[loc]<x[left])
    {
      temp=x[loc];
      x[loc]=x[left];
      x[left]=temp;
      loc=left;
      right--;
    }
   }
   return loc;
}

void QuickSort(int x[], int first, int last)
{
  int p;
  if(first<last)
  {
    p= Partition(x,first,last);
    QuickSort(x,first,p-1);
    QuickSort(x,p+1,last);
  }

  return;
}

void Merge(int x[], int l, int mid, int r)
{
  int C[r],m;
  int i=l, j=mid+1, k=l;

  while(i<=mid && j<=r)
  {
    if(x[i]<=x[j])
    {
      C[k]=x[i];
      i++;
      k++;
    }
  
    else
    {
      C[k]=x[j];
      j++;
      k++;
    }
  }

  if(i>mid && j<=r)
  {
    for(m=j;m<=r;m++)
    {
      C[k]=x[m];
      k++;
    } 
  }

  else if(i<=mid && j>r)
  {
    for(m=i;m<=mid;m++)
    {
      C[k]=x[m];
      k++;
    } 
  }

  for(m=l;m<=k-1;m++)
   x[m]=C[m];
}  

void MergeSort(int x[], int l, int r)
{
 if(r<=l)
  return;
 else
 {
   int mid = (l+r)/2;
   MergeSort(x,l,mid);
   MergeSort(x,mid+1,r);
   Merge(x,l,mid,r);
 }
}


int main()
{
 int c,  i;
 printf("\n Enter the number of elements : ");
 scanf("%d",&n);

 int x[n],y[n];

 printf("\n Enter the array elements : \n");
 for(i=1; i<=n;i++)
  scanf(" %d",&x[i]);

 printf("\n The array is : ");
 for(i=1; i<=n;i++)
  printf("%d ",x[i]);
  printf("\n");
 
 do
 {
   printf("\n 1-Selection Sort \n 2-Insertion Sort \n 3-Quick Sort\n 4-Merge Sort\n 5-Heap Sort\n 0-EXIT\n Enter Your Choice : ");
   scanf("%d",&c);

   switch(c)
   {
    case 1 : printf("\n Selection sort : "); 
             SelectSort(x,n);
             display(x,n);
             break;

    case 2 : printf("\n Insertion sort : "); 
             InsertionSort(x,n);
             display(x,n);
             break;

    case 3 : printf("\n Quick sort : ");
             QuickSort(x,1,n);
             display(x,n);
             break;

    case 4 : printf("\n Merge sort : ");
             MergeSort(x,1,n);
             display(x,n);
             break;	

    case 5 : printf("\n Heap sort : ");
             HeapSort(x,n,y);
             display(y,n);
             break;	
	
    case 0 : printf("\n Exiting !!!\n");
             break;

    default: printf("\n Enter valid choice !!!\n");
   }
 }while(c!=0);
}
