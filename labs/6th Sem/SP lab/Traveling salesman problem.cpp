#include <bits/stdc++.h>
using namespace std;

int travllingSalesmanProblem(int** graph,int s,int n)
{
	vector<int> vertex;
	for(int i=0;i<n;i++)
    {
        if(i!=s)
        {
            vertex.push_back(i);
        }
    }
	int min_path=INT_MAX;
	do {
		int current_pathweight=0;
		int k=s;
		for(int i=0;i<vertex.size();i++)
        {
			current_pathweight += graph[k][vertex[i]];
			k=vertex[i];
		}
		current_pathweight += graph[k][s];
		min_path = min(min_path,current_pathweight);
	}
	while(next_permutation(vertex.begin(),vertex.end()));

	return min_path;
}

int main()
{
    int n,i,j;
    cout<<"enter number of cities\n";
    cin>>n;
    cout<<"enter the distances\n";
    int **matrix=new int*[n];
    for(i=0;i<n;i++)
    {
        matrix[i]=new int[n];
    }
    int v=0;
     for(i=0;i<n;i++)
    {
        for(j=v;j<n;j++)
        {
            if(i==j)
            {
                matrix[i][j]=0;
            }
            else
            {
                cin>>matrix[i][j];
                matrix[j][i]=matrix[i][j];
            }
        }
        v++;
    }
	int s = 0;
	cout << travllingSalesmanProblem(matrix,s,n)<<"\n";
	return 0;
}

