#include<iostream>
#include<string.h>
using namespace std;
class book
{
    char book_name[20],author_name[20];
    int copies;
public:
    book()
    {
        cout<<"enter book details\n";
        cout<<"enter book name,author name and number of copies\n";
        cin>>book_name>>author_name>>copies;
    }
    int search_book(char a[],char b[])
    {
         cout<<"hello\n";
        if(strcmp(a,book_name)&&strcmp(b,author_name))
        {
            cout<<"hello\n";
            return 1;
        }
        else
            return 0;
    }
    void lend()
    {
        if(copies>0)
            copies--;
        else
            cout<<"Book is not available\n";
    }
    void return_book()
    {
        copies++;
    }
    void display()
    {
        cout<<"\nBook name="<<book_name<<"\nAuthor="<<author_name<<"\nAvailable copies="<<copies<<endl<<endl;
    }
} ;
int main()
{
    int x,y,k,i;
    char book1[20],author[20];
    cout<<"enter number of books\n";
    cin>>x;
    book a[x];
    cout<<"\nPress 1 to search a book\nPress 2 to lend a book\nPress 3 to return a book\n";
    cout<<"Press 4 to exit\n";
    cout<<"enter choice\n";
    cin>>y;
    while(y!=4)
    {
        cout<<"enter book name and author name\n";
        cin>>book1>>author;
        i=0,k=0;
        switch(y)
        {
        case 1:
            while(i!=x&&k!=1)
            {
                k=a[i].search_book(book1,author);
                i++;
            }
            if(k==1)
                cout<<"Book found\n";
            else
                cout<<"Book not found\n";
            break;
        case 2:
            while(i!=x&&k!=1)
            {
                k=a[i].search_book(book1,author);
                i++;
            }
            if(k==1)
            {
                i=i-1;
                a[i].lend();
            }
            else
                cout<<"Book not found\n";
            break;
        case 3:
            while(i!=x&&k!=1)
            {
                k=a[i].search_book(book1,author);
                i++;
            }
            if(k==1)
            {
                i=i-1;
                a[i].return_book();
            }
            else
                cout<<"Book not found\n";
            break;
        }
        cout<<"enter choice\n";
        cin>>y;
    }
}
