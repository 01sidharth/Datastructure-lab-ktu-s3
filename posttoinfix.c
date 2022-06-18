#include<stdio.h>
#include<ctype.h>

int top=-1;
char stack[50];

void push(char c)
{ 
     top=top+1;
     stack[top]=c;
}

char pop()
{ 
     return (stack[top--]);
}

int precidence(char n)
{
 if(n=='+'||n=='-')
  return 1;
 else if(n=='*'||n=='/')
  return 2;
 else if(n=='^')
  return 3;
 else 
  return 0;
}


int eval(char *postfix)
{
 char ch;
 int i=0,a,b;
 while((ch=postfix[i++])!='\0')
 {
  if(isdigit(ch))
   push(ch-'0');
  else
  {
   b=pop();
   a=pop();
   switch(ch)
   {
     case '+':push(a+b);
              break;
     case '-':push(a-b);
              break;
     case '*':push(a*b);
              break;
     case '/':push(a/b);
              break;
    }
  }
}
return stack[top];
}



void main()
{
  char infix[50];
  char postfix[50];
  printf("\n Enter the infix expression : \n");
  scanf("%s",infix);

 int i,j;
 char e;
 char x;

 i=0;j=0;  

 while((e=infix[i])!='\0')
 {
   if(e=='(')
    push(e);

    else if(isalnum(e))
    {
      postfix[j]=e;
      j++;
    }

     else if (e==')')
     {
       while(stack[top]!='(')
         postfix[j++]=pop();
       x=pop();
     }

     else 
     {
       while( precidence(stack[top]) >=  precidence(e))
         postfix[j++]=pop();
       push(e);
     }
    i++;
 }
 while (top!=-1)
   postfix[j++]=pop();
 postfix[j]='\0';
 printf("\nThe postfix expression is : ");
 printf("%s",postfix);
 printf("\nResult of postfix expression is : %d\n",eval(postfix) );
}


