#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
struct arraystack
{
    int top,cap;
    node **no;
};
arraystack* create(int n)
{
    arraystack *head=(arraystack*)malloc(sizeof(arraystack));
    head->top=-1;
    head->cap=n;
   // head->base=0;
    head->no=(node**)malloc(sizeof(int)*n);
    return head;
}
int full(arraystack *head)
{
    if(head->top==(head->cap)-1)
        return 1;
    return 0;

}
int blank(arraystack *head)
{
    if(head->top==-1)
        return 1;
    return 0;
}
void push(arraystack *head,node *n)
{
    if(!full(head))
    {
        head->top++;
        head->no[head->top]=n;
    }
}
node* pop(arraystack *head)
{
    node *n;
    if(!blank(head))
    {
        n=head->no[head->top];
        head->top--;
        return n;
    }
}
node** btfind(node **head,int n)
{
    if(*head==NULL)
        return head;
    else if(n>(*head)->data)
         return btfind(&((*head)->right),n);
    else if(n<(*head)->data)
         return btfind(&((*head)->left),n);
    //else if(n==head->data)
      //  return &head;
}
void insertion(node **head,int n)
{
    node **temp=btfind(head,n);
    *temp=new node;
    (*temp)->left=NULL;
    (*temp)->right=NULL;
    (*temp)->data=n;
}
void inorder(node *head)
{
    arraystack *s=create(10);
    if(head!=NULL)
        push(s,head);
    while(!blank(s))
    {
        while(head->left!=NULL)
        {
            push(s,head->left);
            head=head->left;
        }
        if(blank(s))
            break;
        head=pop(s);
        cout<<head->data<<" ";
        while(head->right==NULL)
        {
            if(blank(s))
            break;
            head=pop(s);
            cout<<head->data<<" ";
        }
        if(head->right!=NULL)
        {
        head=head->right;
        push(s,head);
        }
         if(blank(s))
            break;
    }
}
void preorder(node *head)
{
    arraystack *s=create(10);
    if(head==NULL)
        cout<<"tree is empty :";
    else
    {
        push(s,head);
        cout<<head->data<<" ";
        while(!blank(s))
        {
           while(head->left!=NULL)
           {
               head=head->left;
               push(s,head);
               cout<<head->data<<" ";
           }
           head=pop(s);
           if(head->right!=NULL)
           {
               head=head->right;
               push(s,head);
               cout<<head->data<<" ";
           }
        }

    }

}
void postorder(node *head)
{
    arraystack *s=create(10);
    node *temp=NULL;
    if(head==NULL)
        cout<<"tree is empty ";
    else
    {
        do
        {
            while(head!=NULL)
            {
                push(s,head);
                head=head->left;
            }
            head=NULL;
            while(head==NULL && !blank(s))
            {
                head=s->no[s->top];
                if(head->right==NULL || head->right ==temp)
                {
                    cout<<head->data<<" ";
                    pop(s);
                    temp=head;
                    head=NULL;
                }
                else
                    head=head->right;
            }
        }while(!blank(s));
    }
}
int main()
{

    int n,i;
    cout<<"enter no. of nodes and then data:\n";
    cin>>n;
    node *head=NULL;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        insertion(&head,x);
    }
    cout<<"preorder traversal:\n";
    preorder(head);
    cout<<"\n";
    cout<<"postorder traversal:\n";
    postorder(head);
    cout<<"\n";
    cout<<"inorder traversal:\n";
    inorder(head);
}
