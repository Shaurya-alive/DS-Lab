#include <iostream>
using namespace std;

const int MAX = 100;
int q[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Full\n";
        return;
    }
    if (isEmpty()) front = 0;
    q[++rear] = x;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue Empty\n";
        return -1;
    }
    int val = q[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}

int peek() {
    if (isEmpty()) {
        cout << "Queue Empty\n";
        return -1;
    }
    return q[front];
}

void display() {
    if (isEmpty()) {
        cout << "Queue Empty\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";
}

int main() {
    int choice, x;
    while (true) {
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        if (choice == 1) { cin >> x; enqueue(x); }
        else if (choice == 2) { int v = dequeue(); if (v != -1) cout << v << "\n"; }
        else if (choice == 3) { int v = peek(); if (v != -1) cout << v << "\n"; }
        else if (choice == 4) display();
        else if (choice == 5) break;
    }
    return 0;
}
