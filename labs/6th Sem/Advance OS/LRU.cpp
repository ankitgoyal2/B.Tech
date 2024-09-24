#include<bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
	set<int> s;
	map<int, int> indexes;
	int page_faults = 0;
	for (int i=0; i<n; i++)
	{
		if (s.size() < capacity)
		{
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}
		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int lru = INT_MAX, val;
				set<int>::iterator it;
				for ( it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}
				s.erase(val);
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}
	}
	return page_faults;
}

int main()
{
	int n;
    cout<<"enter no. of pages: ";
    cin>>n;
	int pages[n];
	cout<<"enter page numbers\n";
	for(int i=0;i<n;i++)
        cin>>pages[i];
	int capacity;
	cout<<"enter capacity: ";
	cin>>capacity;
	cout << pageFaults(pages, n, capacity);
	return 0;
}

