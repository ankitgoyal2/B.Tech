#include<iostream>
#include<conio.h>
#define SIZE 10
using namespace std;
class node {
	public:
	int data[SIZE];
	node *next;
    node()
    {
        for(int p=0; p<SIZE; p++)
            data[p] = 0;
        next = NULL;
    }
    node(int v[], int n1)
    {
        for(int s = 0; s < n1; s++)
            data[s] = v[s];
        next = NULL;
    }
    friend class process;
}*start=NULL;
int main() {
	int n, events, sent, receive, sentE, recE, commLines = 0;
	node *temp;
	node *proc[SIZE];	//array of processes
	cout<<"Enter no. of processes: ";
	cin>>n;
	int arr[n] = {0};	//representation of data
	for(int i = 0; i < n; i++)
    {	//number of processes
		for(int v = 0; v < n; v++)
        {
			arr[v] = 0;
		}
		cout<<"Enter no. of events in process "<<i+1<<": ";
		cin>>events;
		for(int j = 1; j <= events; j++)
		{
			arr[i] = j;
			node *newnode = new node(arr,n);
			if(start == NULL)
			{
				start = newnode;
				temp = start;
			}
            else
            {
				temp->next = newnode;
				temp = temp->next;
			}
		}
		proc[i] = start;
		start = NULL;
	}
	cout<<"\nEnter the number of communication lines: \n";
	cin>>commLines;
	node *tempS, *tempR;
	for(int i = 0; i < commLines; i++)
    {
		cout<<"Enter sending process,sending event,receiving process,receiving event \n";
		cin>>sent>>sentE>>receive>>recE;
		tempS = proc[sent - 1];
		tempR = proc[receive - 1];
		for(int j = 1; j < sentE; j++)
			tempS = tempS->next;
        node *preRecNode=NULL;
		for(int k = 1; k < recE; k++)
        {
            preRecNode=tempR;
            tempR = tempR->next;
        }
        for(int j = 0; j < n; j++)
			tempR->data[j] = (tempR->data[j] < tempS->data[j]) ? tempS->data[j] : tempR->data[j];
        while(tempR->next!=NULL)
        {
                preRecNode=tempR;
                tempR=tempR->next;
                for(int j = 0; j < n; j++)
                {
                    if(preRecNode!=NULL)
                        tempR->data[j] = (tempR->data[j] < preRecNode->data[j]) ? preRecNode->data[j] : tempR->data[j];
                }
        }
	}
	cout<<"The resulting vectors are:\n";
	for(int k = 0; k < n; k++)
	{
		cout<<"Process "<<k + 1<<": ";
		node *temp1 = proc[k];
		while(temp1)
		{
			cout<<"(";
			for(int f = 0; f < n - 1; f++)
                cout<<temp1->data[f]<<",";
			cout<<temp1->data[n-1]<<")";
			temp1 = temp1->next;
		}
		cout<<endl;
	}
	return 0;
}

