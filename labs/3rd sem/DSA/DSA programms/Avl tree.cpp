#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left,*right;
    int bal;
};
    node* create_node(int a)
    {
        node *n;
        n=new node;
        n->info=a;
        n->left='\0';
        n->right='\0';
        n->bal=0;
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
    node* find_node(int a,node *r)
    {
        if(r->left->info==a||r->right->info==a)
            return r;
        else if(a<r->info)
            return find_node(a,r->left);
        else if(a>r->info)
            return find_node(a,r->right);
    }
    void delete_node(int k,node *r)
    {
        node *n,*a,*p;
        int y=0;
        p=find_node(k,r);
        cout<<"hello\n";
        n=p->left;
        if(k!=n->info)
        {
            n=p->right;
            y=1;
        }
       if(n->left=='\0'&&n->right=='\0')
       {
           cout<<"hello1\n";
           delete n;
           if(y==0)
            p->left='\0';
           else
            p->right='\0';
       }
       else if(n->left=='\0'||n->right=='\0')
       {
           cout<<"hello2\n";
           if(n->left=='\0')
           {
               if(y==0)
                 p->left=n->right;
               else
                 p->right=n->right;
               delete n;
           }
           else
           {
               if(y==0)
                 p->left=n->left;
               else
                 p->right=n->left;
               delete n;
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
    int maximum(int a,int b)
    {
        if(a>=b)
            return a;
        return b;
    }
    int height(node *r)
    {
        if(r==NULL)
        {
            return 0;
        }
        return(1+maximum(height(r->left),height(r->right)));
    }
    void factor(node *root)
       {
           if(root!=NULL)
            root->bal=height(root->left)-height(root->right);
           if(root->left!=NULL)
            factor(root->left);
           if(root->right!=NULL)
            factor(root->right);
       }
       node* find_(node *r,int a)
       {
           node *p='\0';
           while(a!=r->info)
           {
             if(r->bal==2||r->bal==-2)
              p=r;
              if(r->info<a)
                r=r->right;
              if(r->info>a)
                r=r->left;
           }
           return p;
       }
    void preorder_display(node *a)
    {
        cout<<a->info<<" ";
        if(a->left!='\0')
            preorder_display(a->left);
        if(a->right!='\0')
            preorder_display(a->right);
    }
    void rotate_rr(node *par,node *p,int x)
    {
        if(x==1)
            {
                par->left=p->right;
                p->right=par->left->left;
                par->left->left=p;
            }
            else
            {
                par->right=p->right;
                p->right=par->right->left;
                par->right->left=p;
            }
    }
    void rotate_ll(node *par,node *p,int x)
    {
        if(x==1)
            {
                par->left=p->left;
                p->left=par->left->right;
                par->left->right=p;
            }
            else
            {
                par->right=p->left;
                p->left=par->right->right;
                par->right->right=p;
            }
    }
    void rotate_(node *p,node *root,int a)
    {
        node *par,*n;
        int x=0;   //right child
        par=find_node(p->info,root);
        if(par->info>p->info)
            x=1;  //left child
        if(p->info<a&&p->right->info<a)    //rr
        {
            rotate_rr(par,p,x);
        }
        else if(p->info>a&&p->right->info>a)  //ll
        {
            rotate_ll(par,p,x);
        }
        else if(p->info<a&&p->right->info>a)  //rl
        {
            rotate_ll(par,p,x);
            rotate_rr(par,p,x);
        }
        else if(p->info>a&&p->right->info<a)  //lr
        {
            rotate_rr(par,p,x);
            rotate_ll(par,p,x);
        }
    }

int main()
{
    node *root,*p;
    cout<<"enter root node info\n";
    int a,k=0;
    cin>>a;
    root=create_node(a);
    cout<<"Press 1 to add a node\nPress 2 to delete a node\nPress 3 for display preorder traversal\n";
    cout<<"press 4 for height of tree\nPress 5 for exit\n";
    cout<<"enter choice\n";
    cin>>k;
    while(k!=5)
    {
        switch(k)
        {
        case 1:
            cout<<"enter node info\n";
            cin>>a;
            p=create_node(a);
            set_node(p,root);
            factor(root);
            p=find_(root,a);
            if(p!=NULL)
            {
                rotate_(p,root,a);
            }
            break;
        case 2:
            cout<<"enter node info\n";
            cin>>a;
            delete_node(a,root);
            break;
        case 3:
            preorder_display(root);
            cout<<"\n";
            break;
        case 4:
            a=height(root);
            cout<<a<<"\n";
        }
        cout<<"enter choice\n";
        cin>>k;
    }
}


