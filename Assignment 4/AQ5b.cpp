#include <iostream>
using namespace std;

const int MAX2=1000;
int q[MAX2];
int f=0,r=0;

bool emptyq(){ return f==r; }
void enqueue(int x){ q[r++]=x; }
int dequeue(){ return q[f++]; }
int sizeq(){ return r - f; }

void push(int x){
    enqueue(x);
    int s = sizeq();
    for(int i=0;i<s-1;i++){
        enqueue(dequeue());
    }
}

int pop(){
    if(emptyq()) return -1;
    return dequeue();
}

int top(){
    if(emptyq()) return -1;
    return q[f];
}

int main(){
    int choice,x;
    while(true){
        cout<<"1.push 2.pop 3.top 4.exit\n";
        if(!(cin>>choice)) break;
        if(choice==1){ cin>>x; push(x); }
        else if(choice==2){ int v=pop(); if(v==-1) cout<<"Stack Empty\n"; else cout<<v<<"\n"; }
        else if(choice==3){ int v=top(); if(v==-1) cout<<"Stack Empty\n"; else cout<<v<<"\n"; }
        else if(choice==4) break;
    }
    return 0;
}
