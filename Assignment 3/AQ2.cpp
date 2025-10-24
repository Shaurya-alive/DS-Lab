//ID:1024030694 AQ2

#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(char c) {
        top++;
        arr[top] = c;
    }
    char pop() {
        char c = arr[top];
        top--;
        return c;
    }
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}