#include <iostream>
using namespace std;

int main(){
    const int MAXN = 1000;
    const int HS = 2003;
    int n,m;
    int A[MAXN],B[MAXN];
    int used[HS];
    int key[HS];

    cout<<"Enter size of first array: ";
    cin>>n;
    cout<<"Enter elements of first array: ";
    for(int i=0;i<n;i++) cin>>A[i];

    cout<<"Enter size of second array: ";
    cin>>m;
    cout<<"Enter elements of second array: ";
    for(int i=0;i<m;i++) cin>>B[i];

    for(int i=0;i<HS;i++) used[i]=0;

    for(int i=0;i<n;i++){
        int x=A[i];
        int h=x%HS;
        if(h<0) h+=HS;
        while(used[h] && key[h]!=x){
            h++;
            if(h==HS) h=0;
        }
        if(!used[h]){
            used[h]=1;
            key[h]=x;
        }
    }

    cout<<"Common elements: ";
    bool first=true;
    for(int i=0;i<m;i++){
        int x=B[i];
        int h=x%HS;
        if(h<0) h+=HS;
        while(used[h] && key[h]!=x){
            h++;
            if(h==HS) h=0;
        }
        if(used[h] && key[h]==x){
            if(!first) cout<<" ";
            cout<<x;
            first=false;
        }
    }
    return 0;
}
