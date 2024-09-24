#include<bits/stdc++.h>
using namespace std;
struct graph
{
    int v,e;
    int **adj;
};
graph* create_graph()
{
    int i,j,x,y;
    graph *G;
    G=new graph;
    cout<<"enter no. of nodes and edges: ";
    cin>>G->v>>G->e;
    G->adj=(int**)malloc(sizeof(int*)*G->v);
    for(i=0;i<G->v;i++)
        G->adj[i]=(int*)malloc(sizeof(int)*G->v);
    for(i=0;i<G->v;i++)
        for(j=0;j<G->v;j++)
            G->adj[i][j]=0;
    cout<<"enter starting node and ending node for all edge: ";
    for(i=0;i<G->e;i++)
    {
        cin>>x>>y;
        G->adj[x][y]=1;
        G->adj[y][x]=1;
    }
    return G;
}
main()
{
    int ch;
    graph *G;
    G=create_graph();

    while(1)
    {
        cout<<"1 for insertion of edge\n 2 for deletion of edge\n 3 to display matrix\n enter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            int x,y;
            cout<<"enter starting node and ending node for all edge: ";
            cin>>x>>y;
            if(G->adj[x][y]==0)
                {G->adj[x][y]=1;G->adj[y][x]=1;}
            else
                cout<<"already present\n";
            break;
        case 2:
            cout<<"enter starting node and ending node for all edge: ";
            cin>>x>>y;
            if(G->adj[x][y]==1)
                {G->adj[x][y]=0;G->adj[y][x]=0;}
            else
                cout<<"already not present\n";
            break;
        case 3:
            cout<<"adjency matrix is \n";
            for(int i=0;i<G->v;i++)
            {
                for(int j=0;j<G->v;j++)
                {
                    cout<<G->adj[i][j]<<"   ";
                }
                cout<<"\n";
            }
            break;
        default:
            cout<<"invalid choice\n";
        }
    }
}
