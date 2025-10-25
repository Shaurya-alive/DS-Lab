#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *prev, *next;
};

Node *head = NULL;

void insertNode(char ch) {
    Node *newNode = new Node;
    newNode->data = ch;
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

void checkPalindrome() {
    if (head == NULL) {
        cout << "Empty list\n";
        return;
    }
    Node *start = head, *end = head;
    while (end->next)
        end = end->next;
    while (start != end && end->next != start) {
        if (start->data != end->data) {
            cout << "Not Palindrome\n";
            return;
        }
        start = start->next;
        end = end->prev;
    }
    cout << "Palindrome\n";
}

int main() {
    int n;
    char ch;
    cout << "Enter number of characters: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter character: ";
        cin >> ch;
        insertNode(ch);
    }
    checkPalindrome();
}
