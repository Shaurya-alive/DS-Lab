//ID:1024030694 AQ3

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

bool isBalanced(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;
    if (isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}