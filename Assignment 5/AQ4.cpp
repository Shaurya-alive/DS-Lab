#include <iostream>
using namespace std;
struct Node
{
    int v;
    Node *next;
    Node(int x) : v(x), next(0) {}
};
int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    Node *head = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = new Node(x);
        p->next = head;
        head = p;
    }
    if (!head)
    {
        cout << "Empty\n";
        return 0;
    }
    Node *t = head;
    while (t)
    {
        cout << t->v;
        if (t->next)
            cout << " ";
        t = t->next;
    }
    cout << "\n";
    return 0;
}
