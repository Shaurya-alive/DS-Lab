#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
};

Node* newNode(int k){
    Node* n=new Node;
    n->key=k;
    n->left=n->right=NULL;
    return n;
}

Node* insertNode(Node* root,int k){
    if(root==NULL) return newNode(k);
    if(k<root->key) root->left=insertNode(root->left,k);
    else if(k>root->key) root->right=insertNode(root->right,k);
    return root;
}

Node* searchRec(Node* root,int k){
    if(root==NULL || root->key==k) return root;
    if(k<root->key) return searchRec(root->left,k);
    return searchRec(root->right,k);
}

Node* searchIter(Node* root,int k){
    Node* cur=root;
    while(cur && cur->key!=k){
        if(k<cur->key) cur=cur->left;
        else cur=cur->right;
    }
    return cur;
}

Node* minNode(Node* root){
    while(root && root->left) root=root->left;
    return root;
}

Node* maxNode(Node* root){
    while(root && root->right) root=root->right;
    return root;
}

Node* successor(Node* root,int k){
    Node* cur=searchRec(root,k);
    if(!cur) return NULL;
    if(cur->right) return minNode(cur->right);
    Node* s=NULL;
    Node* a=root;
    while(a!=cur){
        if(k<a->key){
            s=a;
            a=a->left;
        }else a=a->right;
    }
    return s;
}

Node* predecessor(Node* root,int k){
    Node* cur=searchRec(root,k);
    if(!cur) return NULL;
    if(cur->left) return maxNode(cur->left);
    Node* p=NULL;
    Node* a=root;
    while(a!=cur){
        if(k>a->key){
            p=a;
            a=a->right;
        }else a=a->left;
    }
    return p;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main(){
    int n; 
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        root=insertNode(root,x);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    int k; cin>>k;

    cout<<(searchRec(root,k)?"Found(rec)":"Not found(rec)")<<endl;
    cout<<(searchIter(root,k)?"Found(iter)":"Not found(iter)")<<endl;

    cout<<"Min "<<minNode(root)->key<<endl;
    cout<<"Max "<<maxNode(root)->key<<endl;

    Node* s=successor(root,k);
    Node* p=predecessor(root,k);

    if(s) cout<<"Successor "<<s->key<<endl;
    else cout<<"No successor\n";

    if(p) cout<<"Predecessor "<<p->key<<endl;
    else cout<<"No predecessor\n";
}
