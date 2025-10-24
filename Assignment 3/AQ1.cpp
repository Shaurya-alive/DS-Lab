//ID:1024030694 AQ1

#include <iostream>
#define MAX_SIZE 10
using namespace std;

class stack{
private:
    int arr[MAX_SIZE];
    int top; 
public:
    stack(){
        top=-1;
    }
    bool isFull(){
        return top==MAX_SIZE-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int n){
        arr[++top]=n;
        cout<<n<<"  is pushed to the stack"<<endl;
    }
    int pop(){
        return arr[top--];
    }
    int peek(){
        return arr[top];
    }
    void display(){
        cout<<endl;
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<endl;
    }


}; 
int main(){
    stack happy;

    happy.push(190);
    cout<<happy.peek()<<endl;
    happy.push(10);
    happy.push(30);
    happy.push(45);
    happy.push(80);
    happy.push(20);
    cout<<happy.peek()<<endl;
    happy.pop();
    cout<<happy.peek()<<endl;
    happy.pop();
    happy.pop();
    happy.display();
    cout<<happy.peek()<<endl;

}