#include <iostream>
using namespace std;

struct Edge{
    int u,v,w;
};

int findSet(int x,int parent[]){
    if(parent[x]==x) return x;
    parent[x]=findSet(parent[x],parent);
    return parent[x];
}

int main(){
    const int MAXE = 100;
    const int MAXV = 100;

    int n,m;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;

    Edge e[MAXE];
    cout<<"Enter edges (u v w) for undirected weighted graph, 0-based:\n";
    for(int i=0;i<m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

    for(int i=0;i<m-1;i++){
        for(int j=0;j<m-1-i;j++){
            if(e[j].w>e[j+1].w){
                Edge t=e[j];
                e[j]=e[j+1];
                e[j+1]=t;
            }
        }
    }

    int parent[MAXV],rankArr[MAXV];
    for(int i=0;i<n;i++){
        parent[i]=i;
        rankArr[i]=0;
    }

    Edge mst[MAXV];
    int mstCount=0;
    int total=0;

    for(int i=0;i<m;i++){
        int a=findSet(e[i].u,parent);
        int b=findSet(e[i].v,parent);
        if(a!=b){
            if(rankArr[a]<rankArr[b]) parent[a]=b;
            else if(rankArr[b]<rankArr[a]) parent[b]=a;
            else{
                parent[b]=a;
                rankArr[a]++;
            }
            mst[mstCount++]=e[i];
            total+=e[i].w;
        }
    }

    cout<<"MST edges (u v w):\n";
    for(int i=0;i<mstCount;i++){
        cout<<mst[i].u<<" "<<mst[i].v<<" "<<mst[i].w<<"\n";
    }
    cout<<"Total weight: "<<total;
    return 0;
}
