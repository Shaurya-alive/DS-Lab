
/*Name : Shaurya Ranjan
  RollNo:   1024030694*/

#include<iostream>
using namespace std;

int Binary_Search(int *arr, int n, int target){
    int low=0;
    int high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]==target){
            return mid;
        }
        
        else if(arr[mid]>target){
            high=mid-1;
        }
        
        else{
            low=mid+1;
        }
    }
    
    return -1;
}

int main()
{
    int arr[6]={10,20,30,40,50,60};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    int targ=50;
    int ind = Binary_Search(arr,n,targ);
    cout<<"The index of Element to be found is: ";
    cout<<ind;
    return 0;
}
