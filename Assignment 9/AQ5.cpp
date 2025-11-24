#include <iostream>
using namespace std;

int main(){
    const int MAX = 100;
    const int INF = 1000000000;

    int n,m;
    int adj[MAX][MAX];
    int i,j;

    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adj[i][j]=INF;

    cout<<"Enter edges (u v w) for directed weighted graph, 0-based:\n";
    for(i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w<adj[u][v]) adj[u][v]=w;
    }

    int s;
    cout<<"Enter source vertex: ";
    cin>>s;

    int dist[MAX],visited[MAX];

    for(i=0;i<n;i++){
        dist[i]=INF;
        visited[i]=0;
    }
    dist[s]=0;

    for(int k=0;k<n;k++){
        int u=-1;
        for(i=0;i<n;i++){
            if(!visited[i] && (u==-1 || dist[i]<dist[u])) u=i;
        }
        if(u==-1 || dist[u]==INF) break;
        visited[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v]!=INF && dist[u]+adj[u][v]<dist[v]){
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }

    cout<<"Distances from source:\n";
    for(i=0;i<n;i++){
        cout<<"Vertex "<<i<<": ";
        if(dist[i]==INF) cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    return 0;
}
