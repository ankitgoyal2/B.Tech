/* program no:11
   program name: red black tree
   author name: Amit Kumar Singh
   roll no: 17103010
   date: 06/03/2019 */
#include<iostream>
using namespace std;
enum colour
{
    red,black
};
struct node
{
    int data;
    colour color;
    node*left,*right,*parent;
};
node*root;
node*b;
void insert(int);
void delete1(int);
void preorder(node*);
void inorder(node*);
void rotate_left(node*);
void rotate_right(node*);
void fix(node*);
void fix1(node*);
int main()
{
    int n,item;
    b=new node;
    b->color=black;
    root=b;
    cout<<"enter the no of items to insert ";
    cin>>n;
    cout<<"enter the items to insert ";
    while(n--)
    {
        cin>>item;
        insert(item);
    }
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"enter the item to delete ";
    cin>>item;
    delete1(item);
    inorder(root);
    cout<<"\n";
    preorder(root);
    return 0;
}
void inorder(node*p)
{
    if(p==b)
        return;
    inorder(p->left);
    cout<<p->data<<" "<<p->color<<"\n";
    inorder(p->right);
}
void preorder(node*p)
{
    if(p==b)
        return;
    cout<<p->data<<" ";
    preorder(p->left);
    preorder(p->right);
}
void rotate_left(node*p)
{
    node*a=p->right;
    p->right=a->left;
    if(a->left!=b)
        a->left->parent=p;
    a->parent=p->parent;
    if(p->parent==b)
        root=a;
    else if(p==p->parent->left)
        p->parent->left=a;
    else
        p->parent->right=a;
    a->left=p;
    p->parent=a;
}
void rotate_right(node*p)
{
    node*a=p->left;
    p->left=a->right;
    if(a->right!=b)
        a->right->parent=p;
    a->parent=p->parent;
    if(p->parent==b)
        root=a;
    else if(p==p->parent->left)
        p->parent->left=a;
    else
        p->parent->right=a;
    a->right=p;
    p->parent=a;
}
void insert(int a)
{
    node*p=root,*par=b,*temp;
    while(p!=b)
    {
        par=p;
        if(a<p->data)
            p=p->left;
        else
            p=p->right;
    }
    temp=new node;
    temp->data=a;
    temp->left=temp->right=b;
    temp->parent=par;
    temp->color=red;
    if(par==b)
        root=temp;
    else if(a<par->data)
        par->left=temp;
    else
        par->right=temp;
    fix(temp);
}
void fix(node*p)
{
    node*par,*grandpar,*uncle;
    while(p->parent->color==red)
    {
        par=p->parent;
        grandpar=par->parent;
        if(par==grandpar->left)
        {
            uncle=grandpar->right;
            if(uncle->color==red)
            {
                par->color=black;
                uncle->color=black;
                grandpar->color=red;
                p=grandpar;
            }
            else
            {
                if(p==par->right)
                {
                    rotate_left(par);
                    p=par;
                    par=p->parent;
                }
                rotate_right(grandpar);
                par->color=black;
                grandpar->color=red;
            }
        }
        else
        {
            uncle=grandpar->left;
            if(uncle->color==red)
            {
                par->color=black;
                uncle->color=black;
                grandpar->color=red;
                p=grandpar;
            }
            else
            {
                if(p==par->left)
                {
                    rotate_right(par);
                    p=par;
                    par=p->parent;
                }
                rotate_left(grandpar);
                par->color=black;
                grandpar->color=red;
            }
        }
    }
    root->color=black;
}
void delete1(int a)
{
    node*p=root,*s,*child;
    while(p!=b&&p->data!=a)
    {
        if(a<p->data)
            p=p->left;
        else
            p=p->right;
    }
    if(p==b)
    {
        cout<<"item not present";
        return;
    }
    if(p->left!=b&&p->right!=b)
    {
        s=p->right;
        while(s->left!=b)
            s=s->left;
        p->data=s->data;
        p=s;
    }
    if(p->left!=b)
        child=p->left;
    else
        child=p->right;
    child->parent=p->parent;
    if(p->parent==b)
        root=child;
    else if(p==p->parent->left)
        p->parent->left=child;
    else
        p->parent->right=child;
    if(child==root)
        child->color=black;
    else if(p->color==black)
    {
        if(child!=b)
            child->color=black;
        else
            fix1(child);
    }
}
void fix1(node*p)
{
    node*sib;
    while(p!=b)
    {
        if(p=p->parent->left)
        {
            sib=p->parent->right;
            if(sib->color==red)
            {
                rotate_left(p->parent);
                sib->color=black;
                p->parent->color=red;
                sib=p->parent->right;
            }
            if(sib->left->color==black&&sib->right->color==black)
            {
                sib->color=red;
                if(p->parent->color==red)
                {
                    p->parent->color=black;
                    return;
                }
                p=p->parent;
            }
            else
            {
                if(sib->right->color==black)
                {
                    sib->left->color=black;
                    sib->color=red;
                    rotate_right(sib);
                    sib=p->parent->right;
                }
                sib->color=p->parent->color;
                p->parent->color=black;
                sib->right->color=black;
                rotate_left(p->parent);
                return;
            }
        }
        else
        {
            sib=p->parent->left;
            if(sib->color==red)
            {
                rotate_right(p->parent);
                sib->color=black;
                p->parent->color=red;
                sib=p->parent->left;
            }
            if(sib->left->color==black&&sib->right->color==black)
            {
                sib->color=red;
                if(p->parent->color==red)
                {
                    p->parent->color=black;
                    return;
                }
                p=p->parent;
            }
            else
            {
                if(sib->left->color==black)
                {
                    sib->right->color=black;
                    sib->color=red;
                    rotate_left(sib);
                    sib=p->parent->left;
                }
                sib->color=p->parent->color;
                p->parent->color=black;
                sib->left->color=black;
                rotate_right(p->parent);
                return;
            }
        }
    }
}
