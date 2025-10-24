
/*Name  : Shaurya Ranjan
  RollNo:   1024030694*/

#include <iostream>
using namespace std;

void Display2D(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void Sort2D(int **arr, int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i][0] > arr[j][0] || (arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1]))
            {
                for (int k = 0; k < 3; k++)
                {
                    int t = arr[i][k];
                    arr[i][k] = arr[j][k];
                    arr[j][k] = t;
                }
            }
        }
    }
}

void Transpose(int **a, int **b, int n)
{
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    for (int i = 1; i < n; i++)
    {
        b[i][0] = a[i][1];
        b[i][1] = a[i][0];
        b[i][2] = a[i][2];
    }
    Sort2D(b, n);
}

void AddSparse(int **a, int **b, int **r)
{
    int i = 1, j = 1, k = 1;
    r[0][0] = a[0][0];
    r[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2])
    {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1])
        {
            int s = a[i][2] + b[j][2];
            if (s != 0)
            {
                r[k][0] = a[i][0];
                r[k][1] = a[i][1];
                r[k][2] = s;
                k++;
            }
            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1]))
        {
            r[k][0] = a[i][0];
            r[k][1] = a[i][1];
            r[k][2] = a[i][2];
            k++;
            i++;
        }
        else
        {
            r[k][0] = b[j][0];
            r[k][1] = b[j][1];
            r[k][2] = b[j][2];
            k++;
            j++;
        }
    }
    while (i <= a[0][2])
    {
        r[k][0] = a[i][0];
        r[k][1] = a[i][1];
        r[k][2] = a[i][2];
        k++;
        i++;
    }
    while (j <= b[0][2])
    {
        r[k][0] = b[j][0];
        r[k][1] = b[j][1];
        r[k][2] = b[j][2];
        k++;
        j++;
    }
    r[0][2] = k - 1;
}

void MultiplySparse(int **A, int **B, int **R)
{
    if (A[0][1] != B[0][0])
    {
        R[0][2] = 0;
        return;
    }
    int nB = B[0][2] + 1;
    int **BT = new int *[nB];
    for (int i = 0; i < nB; i++)
        BT[i] = new int[3];
    Transpose(B, BT, nB);

    R[0][0] = A[0][0];
    R[0][1] = B[0][1];
    int k = 1;
    int ra = 1;
    while (ra <= A[0][2])
    {
        int rA = A[ra][0];
        int endA = ra;
        while (endA <= A[0][2] && A[endA][0] == rA)
            endA++;
        int rb = 1;
        while (rb <= BT[0][2])
        {
            int rB = BT[rb][0];
            int endB = rb;
            while (endB <= BT[0][2] && BT[endB][0] == rB)
                endB++;
            int i = ra, j = rb, s = 0;
            while (i < endA && j < endB)
            {
                if (A[i][1] == BT[j][1])
                {
                    s += A[i][2] * BT[j][2];
                    i++;
                    j++;
                }
                else if (A[i][1] < BT[j][1])
                    i++;
                else
                    j++;
            }
            if (s != 0)
            {
                R[k][0] = rA;
                R[k][1] = rB;
                R[k][2] = s;
                k++;
            }
            rb = endB;
        }
        ra = endA;
    }
    R[0][2] = k - 1;
    for (int i = 0; i < nB; i++)
        delete[] BT[i];
    delete[] BT;
}

int main()
{
    int mat[4][4] = {{0, 8, 9}, {3, 0, 0}, {0, 0, 7}, {2, 4, 5}};
    int mat2[4][4] = {{1, 9, 0}, {7, 0, 0}, {0, 8, 9}, {0, 0, 0}};
    int n = 4, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
                c1++;
    int **sp1 = new int *[c1 + 1];
    for (int i = 0; i <= c1; i++)
        sp1[i] = new int[3];
    sp1[0][0] = n;
    sp1[0][1] = n;
    sp1[0][2] = c1;
    int k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != 0)
            {
                sp1[k][0] = i;
                sp1[k][1] = j;
                sp1[k][2] = mat[i][j];
                k++;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat2[i][j] != 0)
                c2++;
    int **sp2 = new int *[c2 + 1];
    for (int i = 0; i <= c2; i++)
        sp2[i] = new int[3];
    sp2[0][0] = n;
    sp2[0][1] = n;
    sp2[0][2] = c2;
    k = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat2[i][j] != 0)
            {
                sp2[k][0] = i;
                sp2[k][1] = j;
                sp2[k][2] = mat2[i][j];
                k++;
            }

    int **tr = new int *[c1 + 1];
    for (int i = 0; i <= c1; i++)
        tr[i] = new int[3];
    Transpose(sp1, tr, c1 + 1);

    int **add = new int *[50];
    for (int i = 0; i < 50; i++)
        add[i] = new int[3];
    AddSparse(sp1, sp2, add);

    int **mul = new int *[50];
    for (int i = 0; i < 50; i++)
        mul[i] = new int[3];
    MultiplySparse(sp1, sp2, mul);

    cout << "Sparse Matrix 1:\n";
    Display2D(sp1, c1 + 1);
    cout << "\nTranspose:\n";
    Display2D(tr, c1 + 1);
    cout << "\nAddition:\n";
    Display2D(add, add[0][2] + 1);
    cout << "\nMultiplication:\n";
    Display2D(mul, mul[0][2] + 1);

    for (int i = 0; i <= c1; i++)
        delete[] sp1[i];
    delete[] sp1;
    for (int i = 0; i <= c2; i++)
        delete[] sp2[i];
    delete[] sp2;
    for (int i = 0; i <= c1; i++)
        delete[] tr[i];
    delete[] tr;
    for (int i = 0; i < 50; i++)
        delete[] add[i];
    delete[] add;
    for (int i = 0; i < 50; i++)
        delete[] mul[i];
    delete[] mul;
    return 0;
}
