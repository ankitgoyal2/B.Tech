#include<iostream>
#include<stdlib.h>
using namespace std;

int wait(int sem)
{
	return --sem;
}

int signal(int sem)
{
	return ++sem;
}

int mutex=1;
int full=0;
int empty=8;
int no=0;

void consumer(int n)
{
	mutex=wait(mutex);
    full=wait(full);
	cout<<"Consumer "<<n<<" consumes item "<<no<<endl;
	no--;
	empty=signal(empty);
	mutex=signal(mutex);
}

void producer(int n)
{
	mutex=wait(mutex);
	empty=wait(empty);
	no++;
	full=signal(full);
	cout<<"Producer "<<n<<" produces the item "<<no<<endl;
	mutex=signal(mutex);
}

int main()
{
	int n;
	cout<<"press 1 for Producer 1\npress 2 for Producer 2\npress 3 for Consumer 1\npress 4 for Consumer 2\npress 5 for Exit\n";
	cout<<"Enter your choice\n";
	while(1)
	{
		cin>>n;
		switch(n)
		{
			case 1:
			    if((mutex==1)&&(empty!=0))
                    producer(1);
                else
                    cout<<"Buffer is full. you can not produce!!\n";
                break;

            case 2:
                if((mutex==1)&&(empty!=0))
                    producer(2);
                else
                    cout<<"Buffer is full. you can not produce!!\n";
                break;

			case 3:
			    if((mutex==1)&&(full!=0))
                    consumer(1);
                else
                    cout<<"Buffer is empty. you can not consume!!\n";
                break;

            case 4:
                if((mutex==1)&&(full!=0))
                    consumer(2);
                else
                    cout<<"Buffer is empty. you can not consume!!\n";
                break;

			case 5:
                exit(0);
                break;
		}
	}
	return 0;
}
