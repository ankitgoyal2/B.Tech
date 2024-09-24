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



    /*
     char x[1005]={'\0'};
    int j=0,y;
    void show()
    {
       int  i=0;
       while(x[i]!='\0')
       {
       cout<<x[i]<<" ";
       x[i]='\0';
       i++;
       }
       cout<<"\n";
    }
    void mirror(int a,node *r)
    {

        int k=0;
        if(a==r->info)
        {
            k=1;
            y=j;
            j=9000;
        }
        if(k==0)
        {
            if(r->left!='\0')
                {
                    x[j]='L';
                    j++;
                    mirror(a,r->left);
                }
            if(r->right!='\0')
               {
                   x[j]='R';
                   j++;
                    mirror(a,r->right);
               }
            if(k==0)
            {
                j--;
                x[j]='\0';
            }
        }
    }

    this while loop would be inside the main function

    while(q--)
    {
        j=0;
        cin>>a;
        mirror(a,root);
        show();
    }


    */
    void set_node(int a,node *p,node *r,char c)
    {
        int k=0;
        if(a==r->info)
        {
            k=1;
            if(c=='l')
                r->left=p;
            else
                r->right=p;
        }
        if(k==0)
        {
            if(r->left!='\0')
                set_node(a,p,r->left,c);
            if(r->right!='\0')
                set_node(a,p,r->right,c);
        }
    }
int main()
{
    node *root,*p;
    int n,a,b,i,j,k;
    char c;
    cout<<"enter total number of nodes\n";
    cin>>n;
    cout<<"enter root node\n";
    cin>>a;
    root=create_node(a);
    k=n;
    k=k-1;
    while(k--)
    {
        cout<<"enter parent node,node info and side(l or r)\n";
        cin>>a>>b>>c;
        p=create_node(b);
        set_node(a,p,root,c);
    }

}
