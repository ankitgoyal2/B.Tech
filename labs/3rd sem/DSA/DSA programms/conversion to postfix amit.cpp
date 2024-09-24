#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
using namespace std;
class stack
{
    int top;
    int a[10];
    public:
       stack(){top=-1;}
       void push(int);
       int pop();
       void display();
       int evalpostfix(string);
       string infix_postfix(string);
       int precedence(char);
};
void stack::push(int b)
{  if(top==9){
       cout<<"stack overflow";
       return;}
   top+=1;
   a[top]=b;
}
int stack:: pop()
{
    if(top==-1){
        cout<<"stack underflow";
        exit(1);}
    int c=a[top];
    top-=1;
    return(c);
}
void stack:: display()
{
    if(top==-1)
    {
        cout<<"stack empty";
        return;
    }
    cout<<"stack\n";
    for(int i=top;i>=0;i--)
        cout<<a[i]<<" ";
}
int stack::evalpostfix(string str)
{
  int i,a,b,c,d;
  for(i=0;i<str.length();i++)
  {
    if(str[i]>=48&&str[i]<=57)
         push(str[i]-48);
    else
    {   a=pop();
        b=pop();
        switch(str[i])
        {
            case '+':
                  c=b+a;
                  break;
            case '-':
                  c=b-a;
                  break;
            case '*':
                  c=b*a;
                  break;
            case '/':
                  c=b/a;
                  break;
            case '^':
                  c=pow(b,a);
        }
        push(c);
    }
  }
  d=pop();
  return d;
}
string stack::infix_postfix(string str)
{
    int i,k=0;
    char ch;
    char p[20];
    for(i=0;i<str.length();i++)
    {
        if(str[i]>=48&&str[i]<=57)
            p[k++]=str[i];
        else if(str[i]=='(')
            push(str[i]);
        else if(str[i]==')')
        {
            while(1)
            {
                ch=pop();
                if(ch=='(')
                    break;
                else
                    p[k++]=ch;
            }
        }
        else
        {
            while(1)
            {   if(a[top]=='('||precedence(a[top])<precedence(str.at(i)))
                   break;
                else
                {
                    ch=pop();
                    p[k++]=ch;
                }
            }
            push(str[i]);
        }
    }
    p[k]='\0';
    return p;
}
int stack::precedence(char c)
{
    switch(c)
    {
        case '+':
        case '-':
              return 1;
        case '*':
        case '/':
              return 2;
        case '^':
              return 3;
    }
}
int main()
{
   stack A;
   string s,t;
   char z='y';int a;
   while(z=='y')
   {
      cout<<"1.push\n"
        <<"2.pop\n"
        <<"3.display\n"
        <<"4.evalpostfix\n"
        <<"5.infix\n";
      int choice;
      cout<<"enter your choice ";
      cin>>choice;
      switch(choice)
     {
          case 1:
               cout<<"enter the item ";
               cin>>a;
               A.push(a);
               break;
          case 2:
               a=A.pop();
               cout<<"popped item is "<<a;
               break;
          case 3:
               A.display();
               break;
          case 4:
               cout<<"enter the expression";
               cin>>s;
               cout<<A.evalpostfix(s)<<"\n";
               break;
          case 5:
               cout<<"enter the infix expression";
               cin>>s;
               A.push('(');
               s+=")";
               t=A.infix_postfix(s);
               cout<<t;
     }
     cout<<"want to continue";
     z=getche();cout<<endl;
   }
   return 0;
}

