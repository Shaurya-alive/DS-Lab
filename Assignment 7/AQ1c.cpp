#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) cin>>a[i];
    bubbleSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}

