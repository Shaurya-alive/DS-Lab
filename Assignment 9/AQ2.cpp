#include <iostream>
using namespace std;

const int MAX = 100;
int n;
int adj[MAX][MAX];
int visitedDFS[MAX];

void dfs(int u){
    visitedDFS[u]=1;
    cout<<u<<" ";
    for(int v=0;v<n;v++){
        if(adj[u][v] && !visitedDFS[v]){
            dfs(v);
        }
    }
}

int main(){
    int m;
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

    for(i=0;i<n;i++) visitedDFS[i]=0;

    int start;
    cout<<"Enter start vertex for DFS: ";
    cin>>start;

    cout<<"DFS: ";
    dfs(start);
    return 0;
}
