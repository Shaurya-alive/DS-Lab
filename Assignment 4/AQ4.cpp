#include <iostream>
using namespace std;

int main(){
    int count[256] = {0};
    char q[1000];
    int front=0, rear=0;
    char ch;
    bool firstOutput=true;
    while(cin>>ch){
        count[(unsigned char)ch]++;
        q[rear++]=ch;
        while(front<rear && count[(unsigned char)q[front]]>1) front++;
        if(!firstOutput) cout<<" ";
        if(front==rear) cout<<-1;
        else cout<<q[front];
        firstOutput=false;
    }
    cout<<"\n";
    return 0;
}
