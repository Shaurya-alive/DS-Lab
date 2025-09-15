#include <iostream>
using namespace std;

int main(){
    int n;
    if(!(cin>>n)) return 0;
    int a[200];
    for(int i=0;i<n;i++) cin>>a[i];
    int half = n/2;
    for(int i=0;i<half;i++){
        cout<<a[i]<<" "<<a[half + i];
        if(i!=half-1) cout<<" ";
    }
    cout<<"\n";
    return 0;
}
