#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node *head = NULL;

void insertNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void sizeList() {
    int count = 0;
    Node *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    cout << "Size of Doubly Linked List: " << count << endl;
}

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertNode(val);
    }
    sizeList();
}
