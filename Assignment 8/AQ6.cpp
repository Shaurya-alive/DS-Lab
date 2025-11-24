#include <iostream>
using namespace std;

void sw(int &a,int &b){
    int t=a; a=b; b=t;
}

void up(int h[],int i){
    while(i>0){
        int p=(i-1)/2;
        if(h[p]<h[i]){
            sw(h[p],h[i]);
            i=p;
        }else break;
    }
}

void down(int h[],int n,int i){
    while(true){
        int l=2*i+1,r=2*i+2,g=i;
        if(l<n && h[l]>h[g]) g=l;
        if(r<n && h[r]>h[g]) g=r;
        if(g!=i){
            sw(h[i],h[g]);
            i=g;
        }else break;
    }
}

int main(){
    int h[100],n=0,c;

    cout<<"Menu:\n";
    cout<<"1 Insert\n2 Get Max\n3 Extract Max\n4 Display Heap\n5 Exit\n";

    while(true){
        cout<<"Enter choice: ";
        cin>>c;

        if(c==1){
            int x;
            cout<<"Enter value: ";
            cin>>x;
            h[n]=x;
            up(h,n);
            n++;
        }
        else if(c==2){
            cout<<"Current max: ";
            if(n==0) cout<<"Empty\n";
            else cout<<h[0]<<endl;
        }
        else if(c==3){
            cout<<"Extracted: ";
            if(n==0) cout<<"Empty\n";
            else{
                cout<<h[0]<<endl;
                h[0]=h[n-1];
                n--;
                down(h,n,0);
            }
        }
        else if(c==4){
            cout<<"Heap: ";
            if(n==0) cout<<"Empty\n";
            else{
                for(int i=0;i<n;i++) cout<<h[i]<<" ";
                cout<<endl;
            }
        }
        else if(c==5) break;
    }
}
