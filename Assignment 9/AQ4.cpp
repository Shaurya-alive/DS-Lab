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

    cout<<"Enter edges (u v w) for undirected weighted graph, 0-based:\n";
    for(i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w<adj[u][v]){
            adj[u][v]=w;
            adj[v][u]=w;
        }
    }

    int start;
    cout<<"Enter start vertex for Prim: ";
    cin>>start;

    int key[MAX],parent[MAX],inMST[MAX];

    for(i=0;i<n;i++){
        key[i]=INF;
        parent[i]=-1;
        inMST[i]=0;
    }
    key[start]=0;

    for(int k=0;k<n-1;k++){
        int u=-1;
        for(i=0;i<n;i++){
            if(!inMST[i] && (u==-1 || key[i]<key[u])) u=i;
        }
        inMST[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v]!=INF && !inMST[v] && adj[u][v]<key[v]){
                key[v]=adj[u][v];
                parent[v]=u;
            }
        }
    }

    int total=0;
    cout<<"MST edges (u v w):\n";
    for(int v=0;v<n;v++){
        if(parent[v]!=-1){
            cout<<parent[v]<<" "<<v<<" "<<key[v]<<"\n";
            total+=key[v];
        }
    }
    cout<<"Total weight: "<<total;
    return 0;
}
