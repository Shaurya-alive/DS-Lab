#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node *head = NULL;

void insertNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
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

void deleteNode(int value) {
    Node *temp = head;
    while (temp) {
        if (temp->data == value) {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

void searchNode(int value) {
    Node *temp = head;
    while (temp) {
        if (temp->data == value) {
            cout << "Node found\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node not found\n";
}

void display() {
    Node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; insertNode(value); break;
            case 2: cout << "Enter value to delete: "; cin >> value; deleteNode(value); break;
            case 3: cout << "Enter value to search: "; cin >> value; searchNode(value); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
