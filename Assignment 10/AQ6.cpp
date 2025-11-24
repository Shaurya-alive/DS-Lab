#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

void buildTree(Node* nodes[], int n){
    cout<<"Enter values of nodes : ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nodes[i]->val=x;
        nodes[i]->left=NULL;
        nodes[i]->right=NULL;
    }
    cout<<"Enter left and right child index for each node (-1 for NULL):\n";
    for(int i=0;i<n;i++){
        int l,r;
        cout<<"Node "<<i<<": ";
        cin>>l>>r;
        if(l!=-1) nodes[i]->left=nodes[l];
        if(r!=-1) nodes[i]->right=nodes[r];
    }
}

bool dfsCheck(Node* root,int used[],int key[],int HS){
    if(root==NULL) return false;
    int x=root->val;
    int h=x%HS;
    if(h<0) h+=HS;
    while(used[h] && key[h]!=x){
        h++;
        if(h==HS) h=0;
    }
    if(used[h] && key[h]==x) return true;
    used[h]=1;
    key[h]=x;
    if(dfsCheck(root->left,used,key,HS)) return true;
    if(dfsCheck(root->right,used,key,HS)) return true;
    return false;
}

int main(){
    const int MAXN = 1000;
    const int HS = 2003;

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n<=0){
        cout<<"No Duplicates";
        return 0;
    }

    Node* nodes[MAXN];
    for(int i=0;i<n;i++) nodes[i]=new Node;

    buildTree(nodes,n);

    int rootIndex;
    cout<<"Enter root index: ";
    cin>>rootIndex;
    Node* root=nodes[rootIndex];

    int used[HS],key[HS];
    for(int i=0;i<HS;i++) used[i]=0;

    bool dup=dfsCheck(root,used,key,HS);
    if(dup) cout<<"Duplicates Found";
    else cout<<"No Duplicates";
    return 0;
}
