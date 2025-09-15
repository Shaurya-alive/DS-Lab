#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int v) : val(v), next(0) {}
};
Node *build(int n)
{
    Node *h = 0;
    Node *t = 0;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        Node *p = new Node(v);
        if (!h)
            h = t = p;
        else
        {
            t->next = p;
            t = p;
        }
    }
    return h;
}
int countKey(Node *&head, int key)
{
    int c = 0;
    while (head && head->val == key)
    {
        Node *t = head;
        head = head->next;
        delete t;
        c++;
    }
    if (!head)
        return c;
    Node *p = head;
    while (p->next)
    {
        if (p->next->val == key)
        {
            Node *t = p->next;
            p->next = t->next;
            delete t;
            c++;
        }
        else
            p = p->next;
    }
    return c;
}
void print(Node *h)
{
    if (!h)
    {
        cout << "Empty\n";
        return;
    }
    while (h)
    {
        cout << h->val;
        if (h->next)
            cout << " ";
        h = h->next;
    }
    cout << "\n";
}
int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    Node *head = build(n);
    int key;
    cin >> key;
    int c = countKey(head, key);
    cout << "Count: " << c << "\n";
    cout << "Updated: ";
    print(head);
    return 0;
}
