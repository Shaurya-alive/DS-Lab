#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node* newNode(int x){
    Node* n=new Node;
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

Node* buildTree(){
    int x;
    cout<<"Enter root value (-1 for none): ";
    cin>>x;
    if(x==-1) return NULL;

    Node* root=newNode(x);
    queue<Node*> q;
    q.push(root);

    cout<<"Enter left and right child for each node (-1 for none):\n";

    while(!q.empty()){
        Node* cur=q.front(); q.pop();
        int l,r;
        cout<<"Children of "<<cur->data<<": ";
        cin>>l>>r;

        if(l!=-1){
            cur->left=newNode(l);
            q.push(cur->left);
        }
        if(r!=-1){
            cur->right=newNode(r);
            q.push(cur->right);
        }
    }
    return root;
}

bool ok(Node* root,long mn,long mx){
    if(!root) return true;
    if(root->data<=mn || root->data>=mx) return false;
    return ok(root->left,mn,root->data) &&
           ok(root->right,root->data,mx);
}

int main(){
    Node* root=buildTree();
    cout<<"Is BST: "<<(ok(root,-10000000000LL,10000000000LL)?"YES":"NO");
}
