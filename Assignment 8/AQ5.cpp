#include <iostream>
using namespace std;

void heapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && a[l]>a[largest]) largest=l;
    if(r<n && a[r]>a[largest]) largest=r;
    if(largest!=i){
        int t=a[i]; a[i]=a[largest]; a[largest]=t;
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        int t=a[0]; a[0]=a[i]; a[i]=t;
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[100];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];

    heapSort(a,n);

    cout<<"Increasing: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    cout<<"\nDecreasing: ";
    for(int i=n-1;i>=0;i--) cout<<a[i]<<" ";
}
