#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data,state;
};
struct graph
{
    int v,e,**matrix;
    node **nodes;
};
graph* create()
{
    graph *temp=new graph;
    int i,j,x;
    cout<<"enter the no. of vertices :";
    cin>>temp->v;
    temp->matrix=(int**)malloc(sizeof(int)*(temp->v));
    for(i=0;i<temp->v;i++)
        temp->matrix[i]=new int[temp->v];
    int mat[temp->v][temp->v];
    temp->nodes=(node**)malloc(sizeof(node)*temp->v);
    for(i=0;i<temp->v;i++)
    {
        node *y=new node;
        cout<<"enter the data of node :";
        cin>>y->data;
        y->state=0;
        temp->nodes[i]=y;
    }
    for(i=0;i<temp->v;i++)
        for(j=0;j<temp->v;j++)
            temp->matrix[i][j]=0;
    cout<<"enter the no of edges :";
    cin>>temp->e;
    cout<<"enter source and destination of edges:";
    for(x=0;x<temp->e;x++)
    {
        cin>>i>>j;
        cout<<"enter weight :";
        int k;
        cin>>k;
        temp->matrix[i-1][j-1]=k;
    }
    return temp;
}
int minDistance(int dist[], bool sptSet[],int n)
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
int print(int dist[], int n)
{
   cout<<("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      cout<<i<<" distance ="<<dist[i]<<" \n";
}
void dijkstra(graph* head, int src)
{
    int V=head->v;
     int dist[V];
     bool sptSet[V];
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet,head->v);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && head->matrix[u][v] && dist[u] != INT_MAX
                                       && dist[u]+head->matrix[u][v] < dist[v])
            dist[v] = dist[u] + head->matrix[u][v];
     }
     print(dist, V);
}
int main()
{

    graph *head=create();
    dijkstra(head, 0);
    return 0;
}
