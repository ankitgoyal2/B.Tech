#include<bits/stdc++.h>
using namespace std;
struct graph
{
    int v,e;
    int **adj;
};
graph* create_graph()
{
    int i,j,x,y,z;
    graph *G;
    G=new graph;
    cout<<"enter no. of nodes and edges: ";
    cin>>G->v>>G->e;
    G->adj=(int**)malloc(sizeof(int*)*G->v);
    for(i=0;i<G->v;i++)
        G->adj[i]=(int*)malloc(sizeof(int)*G->v);
    for(i=0;i<G->v;i++)
    {
        for(j=0;j<G->v;j++)
        {
            if(i==j)
                G->adj[i][j]=0;
            else
                G->adj[i][j]=10000;
        }
    }
    cout<<"enter starting node and ending node and weight for all edge: ";
    for(i=0;i<G->e;i++)
    {
        cin>>x>>y>>z;
        G->adj[x][y]=z;
    }
    return G;
}
void warshall(graph *G)
{
    int i,j,k;
    for(k=0;k<G->v;k++)
    {
        for(i=0;i<G->v;i++)
        {
            for(j=0;j<G->v;j++)
            {
                if(G->adj[i][j]>G->adj[i][k]+G->adj[k][j])
                    G->adj[i][j]=G->adj[i][k]+G->adj[k][j];
            }
        }
    }
    cout<<"matrix showing shortest path of each pair of node\n";
    for(i=0;i<G->v;i++)
    {
        for(j=0;j<G->v;j++)
        {
            cout<<setw(10)<<G->adj[i][j]<<"     ";
        }
        cout<<"\n";
    }
}
main()
{
    graph *G;
    G=create_graph();
    warshall(G);
}
