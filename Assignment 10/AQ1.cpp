#include <iostream>
using namespace std;

int main(){
    const int MAXN = 1000;
    const int HS = 2003;
    int n;
    int a[MAXN];
    int used[HS];
    int key[HS];

    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<HS;i++) used[i]=0;

    bool dup=false;
    for(int i=0;i<n && !dup;i++){
        int x=a[i];
        int h=x%HS;
        if(h<0) h+=HS;
        while(used[h] && key[h]!=x){
            h++;
            if(h==HS) h=0;
        }
        if(used[h] && key[h]==x) dup=true;
        else{
            used[h]=1;
            key[h]=x;
        }
    }

    cout<<"Contains duplicate: "<<(dup?"true":"false");
    return 0;
}
