#include <iostream>
using namespace std;

int main(){
    const int MAX = 100;
    int n,m;
    int adj[MAX][MAX];
    int i,j;

    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j]=0;

    cout<<"Enter edges (u v) for undirected graph, 0-based:\n";
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    int start;
    cout<<"Enter start vertex for BFS: ";
    cin>>start;

    int visited[MAX];
    for(i=0;i<n;i++) visited[i]=0;

    int q[MAX];
    int front=0,rear=0;

    q[rear++]=start;
    visited[start]=1;

    cout<<"BFS: ";
    while(front<rear){
        int u=q[front++];
        cout<<u<<" ";
        for(int v=0;v<n;v++){
            if(adj[u][v] && !visited[v]){
                visited[v]=1;
                q[rear++]=v;
            }
        }
    }
    return 0;
}
