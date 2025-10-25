#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertNode(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(int value) {
    if (head == NULL) return;
    Node *curr = head, *prev = NULL;
    do {
        if (curr->data == value) {
            if (curr == head && curr->next == head) {
                head = NULL;
                delete curr;
                return;
            }
            if (curr == head) {
                Node *last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                delete curr;
                return;
            }
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

void searchNode(int value) {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node *temp = head;
    do {
        if (temp->data == value) {
            cout << "Node found\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Node not found\n";
}

void display() {
    if (head == NULL) {
        cout << "List empty\n";
        return;
    }
    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
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
