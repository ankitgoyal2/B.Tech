#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left,*right;
};

    node* create_node(int a)
    {
        node *n;
        n=new node;
        n->info=a;
        n->left='\0';
        n->right='\0';
        return n;
    }

    int i=1,m=-1;

    void set_node(node *a,node *root)
    {
        if(a->info=<root->info)
        {
            i++;
            if(root->left=='\0')
            root->left=a;
            else
                set_node(a,root->left);
        }
        else
        {
            i++;
            if(root->right=='\0')
            root->right=a;
            else
                set_node(a,root->right);
        }
    }

int main()
{
    node *root,*p;
    int a,n,k;
    cin>>n;
    k=n;
    cin>>a;
    root=create_node(a);
    n=n-1;
    while(n--)
    {
        cin>>a;
        p=create_node(a);
        set_node(p,root);
        if(i>m)
            m=i;
        i=1;
    }
    if(k==1)
        cout<<"1";
    else
        cout<<m;
}
