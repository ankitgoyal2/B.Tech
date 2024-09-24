#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left,*right;
};
struct stack1
{
    int top,size1;
    node **ptr;
};
stack1* create_stack(int k)
{
    stack1 *n;
    n=new stack1;
    n->top=-1;
    n->size1=k;
    n->ptr=new node* [k];
    return n;
}
int isfull(stack1 *n)
{
    if(n->top==n->size1-1)
        return 1;
    else
        return 0;
}
int isempty(stack1 *n)
{
    if(n->top==-1)
        return 1;
    else
        return 0;
}
void push(node *k,stack1 *n)
{
    if(!isfull(n))
    {
        n->top++;
        n->ptr[n->top]=k;
    }
}
node* pop(stack1 *n)
{
    if(!isempty(n))
    {
        n->top--;
        return n->ptr[n->top+1];
    }
    else
    {
        node *k='\0';
        return k;
    }
}

    node* create_node(int a)
    {
        node *n;
        n=new node;
        n->info=a;
        n->left='\0';
        n->right='\0';
        return n;
    }
    void set_node(node *a,node *root)
    {
        if(a->info<root->info)
        {
            if(root->left=='\0')
            root->left=a;
            else
                set_node(a,root->left);
        }
        else
        {
            if(root->right=='\0')
            root->right=a;
            else
                set_node(a,root->right);
        }
    }
    node** find_node(int a,node *r)    //recursive
    {
        if(a<r->info)
            return find_node(a,r->left);
        else if(a>r->info)
            return find_node(a,r->right);
        else
            return &r;
    }
   /* void put_address(node *n,node *a,node *r)
    {
        if(n==r)
            r=a;
        else if(n->info<r->info)
            put_address(n,a,r->left);
        else
            put_address(n,a,r->right);
    }     */
  /*   node** find_node(int a,node *r)   //non recursive
     {
         while(1)
         {
             if(a<r->info)
                r=r->left;
             else if(a>r->info)
                r=r->right;
             else if(a==r->info||r=='\0')
                break;
         }
         return &r;
     }    */
    void delete_node(int k,node *r)
    {
        node *n,*a;
        node **x;
        x=find_node(k,r);
        cout<<"hello\n";
        n=*x;
         cout<<"hello\n";
       if(n->left=='\0'&&n->right=='\0')
       {
           cout<<"hello1\n";
           a=n;
           n='\0';
           delete a;
       }
       else if(n->left=='\0'||n->right=='\0')
       {
           cout<<"hello2\n";
           if(n->left=='\0')
           {
               a=n;
               n=n->right;
               delete a;
           }
           else
           {
               a=n;
               n=n->left;
               delete a;
           }
       }
       else
       {
           cout<<"hello3\n";
               node *pre='\0';
               a=n->left;
               while(a->right!='\0')
               {
                   pre=a;
                   a=a->right;
               }
               n->info=a->info;
               if(pre=='\0')
                n->left=a->left;
               else
                pre->right=a->left;
               delete a;
       }

    }
    void preorder_display(node *a)  //using recurssion
    {
        cout<<a->info<<" ";         //process node
        if(a->left!='\0')
            preorder_display(a->left);
        if(a->right!='\0')
            preorder_display(a->right);
    }
    void preorder(node *n)      //using stack
    {
        stack1 *s;
        s=create_stack(20);
        while(n!='\0')
        {
            cout<<n->info<<" ";    //process node
            if(n->right!='\0')
                push(n->right,s);
            if(n->left!='\0')
                n=n->left;
            else
                n=pop(s);
        }
    }
    void inorder(node *n)    //using stack
    {
        stack1 *s;
        s=create_stack(20);
   abc: while(n->left!='\0')
        {
            push(n,s);
            n=n->left;
        }
        while(n!='\0')
        {
            cout<<n->info<<" ";      //process node
            if(n->right!='\0')
            {
              n=n->right;
              goto abc;
             }
             else
                n=pop(s);
        }
    }

int main()
{
    node *root,*p;
    cout<<"enter root node info\n";
    int a,k=0;
    cin>>a;
    root=create_node(a);
    cout<<"Press 1 to add a node\nPress 2 to delete a node\nPress 3 for display\n";
    cout<<"Press 4 for exit\n";
    cout<<"enter choice\n";
    cin>>k;
    while(k!=4)
    {
        switch(k)
        {
        case 1:
            cout<<"enter node info\n";
            cin>>a;
            p=create_node(a);
            set_node(p,root);
            break;
        case 2:
            cout<<"enter node info\n";
            cin>>a;
            delete_node(a,root);
            break;
        case 3:
            inorder(root);
            cout<<"\n";
            break;
        }
        cout<<"enter choice\n";
        cin>>k;
    }
}
