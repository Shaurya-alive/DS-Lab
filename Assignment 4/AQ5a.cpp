#include <iostream>
using namespace std;

const int MAX=1000;
int q1[MAX], q2[MAX];
int f1=0,r1=0,f2=0,r2=0;

bool empty1(){ return f1==r1; }
bool empty2(){ return f2==r2; }
void enqueue1(int x){ q1[r1++]=x; }
int dequeue1(){ return q1[f1++]; }
void enqueue2(int x){ q2[r2++]=x; }
int dequeue2(){ return q2[f2++]; }

void push(int x){ enqueue1(x); }
int pop(){
    if(empty1()) return -1;
    while(r1 - f1 > 1) enqueue2(dequeue1());
    int val = dequeue1();
    while(!empty2()) enqueue1(dequeue2());
    f2 = r2 = 0;
    return val;
}
int top(){
    if(empty1()) return -1;
    while(r1 - f1 > 1) enqueue2(dequeue1());
    int val = dequeue1();
    enqueue2(val);
    while(!empty2()) enqueue1(dequeue2());
    f2 = r2 = 0;
    return val;
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
