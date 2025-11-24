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

Node* minNode(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* deleteNode(Node* root,int k){
    if(root==NULL) return root;
    if(k<root->key) root->left=deleteNode(root->left,k);
    else if(k>root->key) root->right=deleteNode(root->right,k);
    else{
        if(root->left==NULL){
            Node* t=root->right;
            delete root;
            return t;
        }
        else if(root->right==NULL){
            Node* t=root->left;
            delete root;
            return t;
        }
        Node* t=minNode(root->right);
        root->key=t->key;
        root->right=deleteNode(root->right,t->key);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int l=maxDepth(root->left), r=maxDepth(root->right);
    return (l>r?l:r)+1;
}

int minDepth(Node* root){
    if(!root) return 0;
    int l=minDepth(root->left), r=minDepth(root->right);
    if(!root->left || !root->right) return (l>r?l:r)+1;
    return (l<r?l:r)+1;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

int main(){
    int n,x,d;
    cout<<"Enter number of elements: ";
    cin>>n;

    Node* root=NULL;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }

    cout<<"Inorder before delete: ";
    inorder(root);
    cout<<endl;

    cout<<"Max depth before delete: "<<maxDepth(root)<<endl;
    cout<<"Min depth before delete: "<<minDepth(root)<<endl;

    cout<<"Enter value to delete: ";
    cin>>d;

    root=deleteNode(root,d);

    cout<<"Inorder after delete: ";
    inorder(root);
    cout<<endl;

    cout<<"Max depth after delete: "<<maxDepth(root)<<endl;
    cout<<"Min depth after delete: "<<minDepth(root)<<endl;
}
