#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    const int HS = 2003;
    Node* nodes[1000];
    int used[HS];
    unsigned long long key[HS];

    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    if(n<=0){
        cout<<"Contains loop: false";
        return 0;
    }

    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        nodes[i]=new Node;
        cin>>nodes[i]->data;
        nodes[i]->next=NULL;
        if(i>0) nodes[i-1]->next=nodes[i];
    }

    int pos;
    cout<<"Enter index to link last node to (-1 for no loop): ";
    cin>>pos;
    if(pos>=0 && pos<n) nodes[n-1]->next=nodes[pos];

    for(int i=0;i<HS;i++) used[i]=0;

    Node* cur=nodes[0];
    bool loop=false;

    while(cur){
        unsigned long long addr=(unsigned long long)(cur);
        int h=(int)(addr%HS);
        while(used[h] && key[h]!=addr){
            h++;
            if(h==HS) h=0;
        }
        if(used[h] && key[h]==addr){
            loop=true;
            break;
        }else{
            used[h]=1;
            key[h]=addr;
        }
        cur=cur->next;
    }

    cout<<"Contains loop: "<<(loop?"true":"false");
    return 0;
}
