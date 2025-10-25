#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void createList(int n) {
    Node *temp, *newNode;
    int val;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

bool isCircular(Node* head) {
    if (head == NULL) return false;
    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    int n;
    char choice;
    cout << "Enter number of nodes: ";
    cin >> n;
    createList(n);

    cout << "Make it circular? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head; // make circular
    }

    if (isCircular(head))
        cout << "The linked list is Circular." << endl;
    else
        cout << "The linked list is NOT Circular." << endl;

    return 0;
}
