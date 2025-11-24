#include <iostream>
using namespace std;

void improvedSelection(int a[], int n)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mn = l, mx = l;
        for (int i = l; i <= r; i++)
        {
            if (a[i] < a[mn])
                mn = i;
            if (a[i] > a[mx])
                mx = i;
        }
        int t = a[l];
        a[l] = a[mn];
        a[mn] = t;
        if (mx == l)
            mx = mn;
        t = a[r];
        a[r] = a[mx];
        a[mx] = t;
        l++;
        r--;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    improvedSelection(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
