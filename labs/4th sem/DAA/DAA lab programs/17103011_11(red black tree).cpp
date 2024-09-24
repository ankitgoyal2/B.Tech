/*
PROGRAM NAME = WRITE A PROGRAM TO IMPLEMENT INSERTION AND DELETION IN RED BLACK TREE
ROLL NO. = 17103011
NAME = ANKIT GOYAL
DATE = 06/03/2019  */

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    char colour;
    node *left,*right,*parent;
};
node *root='\0';
void insert_node(node *&root,node *p1)
{
   if(root=='\0')
    root=p1;
   else
   {
        if(p1->info<root->info)
        {
            if(root->left=='\0')
            {
                p1->parent=root;
                root->left=p1;
            }
            else
                insert_node(root->left,p1);
        }
        else
        {
            if(root->right=='\0')
            {
                p1->parent=root;
                root->right=p1;
            }
            else
                insert_node(root->right,p1);
        }
   }
}
void rotate_left(node *t)
{
    node *child=t->left;
    t->left=child->right;
    if(t->left!='\0')
        t->left->parent=t;
    child->right=t;
    node *temp=t->parent;
    t->parent=child;
    if(temp=='\0')
    {
        child->parent='\0';
        root=child;
    }
    else if(temp->left==t)
    {
        temp->left=child;
        child->parent=temp;
    }
    else
    {
        temp->right=child;
        child->parent=temp;
    }
}
void rotate_right(node *t)
{
    node *child=t->right;
    t->right=child->left;
    if(t->right!='\0')
        t->right->parent=t;
    child->left=t;
    node *temp=t->parent;
    t->parent=child;
    if(temp=='\0')
    {
        child->parent='\0';
        root=child;
    }
    else if(temp->left==t)
    {
        temp->left=child;
        child->parent=temp;
    }
    else
    {
        temp->right=child;
        child->parent=temp;
    }
}
void set_node(node *&root,node *&t)
{
    if(t->parent=='\0')
    {
        t->colour='b';
        return;
    }
    while(t->parent!='\0'&&t->parent->colour!='b')
    {
        node *uncle,*par=t->parent,*g_par=t->parent->parent;
        if(g_par->left==par)
            uncle=g_par->right;
        else
            uncle=g_par->left;
        if(uncle!='\0'&&uncle->colour=='r')
        {
            par->colour='b';
            uncle->colour='b';
            g_par->colour='r';
            t=g_par;
        }
        else
        {
            if(g_par->left==par)
            {
                if(par->right==t)
                {
                    t=t->parent;
                    rotate_right(t);
                }
                t->parent->colour='b';
                g_par->colour='r';
                rotate_left(g_par);
            }
            else
            {
                if(par->left==t)
                {
                    t=t->parent;
                    rotate_left(t);
                }
                t->parent->colour='b';
                g_par->colour='r';
                rotate_right(g_par);
            }
        }
    }
    root->colour='b';
}
void delete_node(node *&v)
{
    node *u;
    if(v->left!='\0'&&v->right!='\0')
    {
        node *n=v->right;
        while(n->left!='\0')
            n=n->left;
        u=n;
    }
    else if(v->left=='\0'&&v->right=='\0')
    {
        u='\0';
    }
    else if(v->left=='\0'||v->right=='\0')
    {
        if(v->left=='\0')
        {
            u=v->right;
        }
        else
        {
            u=v->left;
        }
    }


}
void print_tree(node *root)
{
    if(root->left!='\0')
        print_tree(root->left);
    cout<<root->info<<" "<<root->colour<<"\n";
    if(root->right!='\0')
        print_tree(root->right);
}
int main()
{
    int i,choice,temp1,temp2,hash;
    node *p1,*p2;
    cout<<"press 1 for insert element\npress 2 for searching element\n";
    cout<<"press 3 for delete element\npress 4 for print tree\npress 5 for exit\nenter choice\n";
    cin>>choice;
    while(choice!=5)
    {
        switch(choice)
        {
        case 1:
            cout<<"enter number\n";
            cin>>temp1;
            p1=new node;
            p1->info=temp1;
            p1->left=p1->right=p1->parent='\0';
            p1->colour='r';
            insert_node(root,p1);
            set_node(root,p1);
            break;
        case 2:
            cout<<"enter no. to search\n";
            cin>>temp1;
            p1=root;
            while(p1!='\0'&&p1->info!=temp1)
            {
                if(p1->info<temp1)
                    p1=p1->right;
                if(p1->info>temp1)
                    p1=p1->left;
            }
            if(p1=='\0')
                cout<<temp1<<" is not present in the tree\n";
            else
            {
                cout<<p1->info<<" "<<p1->colour<<" "<<p1->parent<<"\n";
            }
            break;
        case 3:
            cout<<"enter number\n";
            cin>>temp1;
            p1=root;
            while(p1!='\0'&&p1->info!=temp1)
            {
                if(p1->info<temp1)
                    p1=p1->right;
                if(p1->info>temp1)
                    p1=p1->left;
            }
            if(p1=='\0')
                cout<<temp1<<" is not present in the tree\n";
            else
                delete_node(p1);
            break;
        case 4:
            print_tree(root);
            cout<<"\n";
            break;
        default:
            cout<<"invalid choice\n";
        }
        cout<<"enter choice\n";
        cin>>choice;
    }
}
