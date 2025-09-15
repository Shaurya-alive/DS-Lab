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
    Node *tail = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *p = new Node(x);
        if (!head)
            head = tail = p;
        else
            tail->next = p, tail = p;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow)
        cout << slow->v << "\n";
    return 0;
}
