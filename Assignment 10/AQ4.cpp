#include <iostream>
using namespace std;

int main(){
    const int MAXN = 1000;
    const int HS = 2003;
    int n;
    int a[MAXN];
    int used[HS];
    int key[HS];
    int val[HS];

    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<HS;i++){
        used[i]=0;
        val[i]=0;
    }

    for(int i=0;i<n;i++){
        int x=a[i];
        int h=x%HS;
        if(h<0) h+=HS;
        while(used[h] && key[h]!=x){
            h++;
            if(h==HS) h=0;
        }
        if(!used[h]){
            used[h]=1;
            key[h]=x;
            val[h]=1;
        }else val[h]++;
    }

    int ansFound=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        int h=x%HS;
        if(h<0) h+=HS;
        while(used[h] && key[h]!=x){
            h++;
            if(h==HS) h=0;
        }
        if(used[h] && val[h]==1){
            ansFound=1;
            ans=x;
            break;
        }
    }

    if(ansFound) cout<<"First non-repeating: "<<ans;
    else cout<<"No non-repeating element";
    return 0;
}
