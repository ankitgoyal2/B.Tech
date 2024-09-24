#include<iostream>
#include<string.h>
using namespace std;
class book;
struct date
{
    int dd,mm,yyyy;
};
class member
{
    int id;
    char name[20];
public:
    friend book;
    member()
    {
        cout<<"enter name and member id\n";
        cin>>name>>id;
    }

    int search_member(int a)
    {
        if(id==a)
            return 1;
        else
            return 0;
    }
    void display()
    {
        cout<<"\nName = "<<name<<"\nMember id = "<<id<<"\n";
    }
};
class book
{
    char book_name[20],author_name[20];
    static int c;
    int bookid,n,memberid;
    date dol,dor;
public:
    friend member;
    book()
    {
        n=1;
        memberid=-1;
        cout<<"enter book details\n";
        cout<<"enter book name,author name and book id\n";
        cin>>book_name>>author_name>>bookid;
    }
    void lend(member &b)
    {
        if(n==1)
        {
            memberid=b.id;
            cout<<b.id<<"\n";
            cout<<"enter date of lend in dd,mm,yyyy\n";
            cin>>dol.dd>>dol.mm>>dol.yyyy;
            n--;
            c+=1;
        }
        else
            cout<<"Book is not available\n";
    }
    void return_book()
    {
        n=1;
        cout<<"enter date of return in dd,mm,yyyy\n";
        cin>>dor.dd>>dor.mm>>dor.yyyy;
        int x,y,z;
        z=dor.yyyy-dol.yyyy;
        y=(dor.mm-dol.mm)+z*12;
        x=(dor.dd-dol.dd)+y*30;

        cout<<"Total charges = "<<x<<"\n";
        c-=1;
        memberid=-1;
    }
    int search_book(int a)
    {
        if(bookid==a)
            return 1;
        else
            return 0;
    }
    void display()
    {
        cout<<"\nBook name="<<book_name<<"\nAuthor="<<author_name<<"\nBook id="<<bookid<<"\n";
        cout<<"remaining copies = "<<n<<"\n";
        cout<<"total number of issued books = "<<c<<"\n";
        cout<<"Member id = "<<memberid<<"\n";
    }
} ;
int book::c=0;

int main()
{
    book a[5];
    member b[3];
    cout<<"\nPress 1 to lend a book\nPress 2 to return a book\nPress 3 for display book details\n";
    cout<<"Press 4 for display member's details\nPress 5 to exit\n";
    cout<<"enter choice\n";
    int y;
    int i,j,k,l,m;
    cin>>y;
    while(y!=5)
    {
        switch(y)
        {
        case 1:
            cout<<"enter book id and member id\n";
            cin>>i>>j;
            k=0;
            while(k<=4)
            {
                l=a[k].search_book(i);
                if(l==1)
                    break;
                k++;
            }
            m=0;
            while(m<=2)
            {
                l=b[m].search_member(j);
                if(l==1)
                    break;
                m++;
            }
            a[k].lend(b[m]);
            break;
        case 2:
            cout<<"enter book id\n";
            cin>>i;
            k=0;
            while(k<=4)
            {
                l=a[k].search_book(i);
                if(l==1)
                    break;
                k++;
            }
            a[k].return_book();
            break;
        case 3:
            k=1;
            while(k!=6)
            {
                a[k-1].display();
                k++;
            }
            break;
        case 4:
            k=1;
            while(k!=4)
            {
                b[k-1].display();
                k++;
            }
            break;
        }
        cout<<"enter choice\n";
        cin>>y;
    }
}
