//ID:1024030694 AQ4

#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.pop();
            }
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                result += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        result += s.pop();
    }
    return result;
}

int main() {
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}