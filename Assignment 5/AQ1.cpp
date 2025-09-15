#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(0) {}
};
Node *head = 0;
void insertBegin(int x)
{
    Node *p = new Node(x);
    p->next = head;
    head = p;
}
void insertEnd(int x)
{
    Node *p = new Node(x);
    if (!head)
    {
        head = p;
        return;
    }
    Node *t = head;
    while (t->next)
        t = t->next;
    t->next = p;
}
void insertBefore(int key, int x)
{
    if (!head)
        return;
    if (head->val == key)
    {
        insertBegin(x);
        return;
    }
    Node *t = head;
    while (t->next && t->next->val != key)
        t = t->next;
    if (t->next)
    {
        Node *p = new Node(x);
        p->next = t->next;
        t->next = p;
    }
}
void insertAfter(int key, int x)
{
    Node *t = head;
    while (t && t->val != key)
        t = t->next;
    if (t)
    {
        Node *p = new Node(x);
        p->next = t->next;
        t->next = p;
    }
}
void deleteBegin()
{
    if (!head)
        return;
    Node *t = head;
    head = head->next;
    delete t;
}
void deleteEnd()
{
    if (!head)
        return;
    if (!head->next)
    {
        delete head;
        head = 0;
        return;
    }
    Node *t = head;
    while (t->next->next)
        t = t->next;
    delete t->next;
    t->next = 0;
}
void deleteValue(int key)
{
    if (!head)
        return;
    if (head->val == key)
    {
        deleteBegin();
        return;
    }
    Node *t = head;
    while (t->next && t->next->val != key)
        t = t->next;
    if (t->next)
    {
        Node *r = t->next;
        t->next = r->next;
        delete r;
    }
}
int searchNode(int key)
{
    Node *t = head;
    int pos = 1;
    while (t)
    {
        if (t->val == key)
            return pos;
        t = t->next;
        pos++;
    }
    return -1;
}
void displayList()
{
    if (!head)
    {
        cout << "Empty\n";
        return;
    }
    Node *t = head;
    while (t)
    {
        cout << t->val;
        if (t->next)
            cout << " ";
        t = t->next;
    }
    cout << "\n";
}
int main()
{
    int choice, x, key;
    while (true)
    {
        cout << "1.insBeg 2.insEnd 3.insBefore 4.insAfter 5.delBeg 6.delEnd 7.delVal 8.search 9.display 10.exit\n";
        if (!(cin >> choice))
            break;
        if (choice == 1)
        {
            cin >> x;
            insertBegin(x);
        }
        else if (choice == 2)
        {
            cin >> x;
            insertEnd(x);
        }
        else if (choice == 3)
        {
            cin >> key >> x;
            insertBefore(key, x);
        }
        else if (choice == 4)
        {
            cin >> key >> x;
            insertAfter(key, x);
        }
        else if (choice == 5)
            deleteBegin();
        else if (choice == 6)
            deleteEnd();
        else if (choice == 7)
        {
            cin >> key;
            deleteValue(key);
        }
        else if (choice == 8)
        {
            cin >> key;
            int p = searchNode(key);
            if (p == -1)
                cout << "Not Found\n";
            else
                cout << p << "\n";
        }
        else if (choice == 9)
            displayList();
        else if (choice == 10)
            break;
    }
    return 0;
}
