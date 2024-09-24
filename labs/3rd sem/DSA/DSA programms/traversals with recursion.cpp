#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
struct arrayqueue
{
    int top,base,cap;
    node **no;
};
arrayqueue* create(int n)
{
    arrayqueue *temp=(arrayqueue*)malloc(sizeof(arrayqueue));
    temp->top=-1;
    temp->base=-1;
    temp->cap=n;
    temp->no=(node**)malloc(sizeof(int)*n);
    return temp;
}
int full(arrayqueue *head)
{
    if((head->top+1)%(head->cap)==(head->base))
        return 1;
    else
        return 0;
}
int blank(arrayqueue *head)
{
    if(head->top == -1 && head->base==-1)
        return 1;
    else
        return 0;
}
void enqueue(arrayqueue *head,node *n)
{
    if(!full(head))
    {
        head->top=((head->top)+1)%(head->cap);
        head->no[head->top]=n;
        if(head->base==-1)
            head->base=head->top;
    }
}
node* dequeue(arrayqueue *head)
{
    if(!blank(head))
    {
        node *n=head->no[head->base];
        if(head->base==head->top)
        {
            head->base=head->top=-1;
        }
        else
            head->base =((head->base)+1)%(head->cap);
        return n;
    }
}
node** btfind(node **head,int n);
void insertion(node **head,int n)
{
    node **temp=btfind(head,n);
    *temp=new node;
    (*temp)->left=NULL;
    (*temp)->right=NULL;
    (*temp)->data=n;
}
void preorder(node *head)
{
    if(head==NULL)
        cout<<"tree is empty  ";
    else
    {
        cout<<head->data<<" ";
        if(head->left!=NULL)
        preorder(head->left);
        if(head->right!=NULL)
        preorder(head->right);
    }
}
void postorder(node *head)
{
    if(head==NULL)
        cout<<"empty tree\n";
    else
    {
        if(head->left!=NULL)
            postorder(head->left);
        if(head->right!=NULL)
            postorder(head->right);
        cout<<head->data<<" ";
    }
}
void inorder(node *head)
{
    if(head->left!=NULL)
        inorder(head->left);
    cout<<head->data<<" ";
    if(head->right!=NULL)
        inorder(head->right);
}
void levelorder(node *head)
{
    if(head==NULL)
        cout<<"tree is empty";
    else
    {
        arrayqueue *q=create(10);
        cout<<head->data<<" ";
        if(head->left!=NULL)
            enqueue(q,head->left);
        if(head->right!=NULL)
            enqueue(q,head->right);
        while(!blank(q))
        {
            node *temp=dequeue(q);
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                enqueue(q,temp->left);
            if(temp->right!=NULL)
                enqueue(q,temp->right);

        }
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
node* findmax(node *head)
{
    node *temp1=head;
    if(head==NULL)
        cout<<"tree is empty";
    else
    {
        arrayqueue *q=create(10);
        if(head->left!=NULL)
            enqueue(q,head->left);
        if(head->right!=NULL)
            enqueue(q,head->right);
        while(!blank(q))
        {
            node *temp=dequeue(q);
            if(temp1->data<temp->data)
                temp1=temp;
            if(temp->left!=NULL)
                enqueue(q,temp->left);
            if(temp->right!=NULL)
                enqueue(q,temp->right);

        }
    }
    return temp1;
}
node* deletion(node *head,int n)
{
    if(head==NULL)
    {
        cout<<"no such element is there \n";
    }
    else if(head->data>n)
        head->left=deletion(head->left,n);
    else if(head->data<n)
        head->right=deletion(head->right,n);
    else if(head->data==n)
    {
        if(head->left!=NULL && head->right!=NULL)
        {
            node *temp=findmax(head->left);
            head->data=temp->data;
            head->left=deletion(head->left,head->data);
        }
        else
        {
            node *temp=head;
            if(head->left==NULL)
                head=head->right;
            else if(head->right==NULL)
                head=head->left;
            free(temp);
        }
    }
    return head;
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
    cout<<"\n";
    cout<<"levelorder traversal:\n";
    levelorder(head);
}
