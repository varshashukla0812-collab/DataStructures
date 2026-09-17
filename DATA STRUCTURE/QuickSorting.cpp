#include <iostream>
using namespace std;

struct Bound {
    int LB, UB;
};

// ---------- Partition Algorithm ----------
int Partition(Bound P, int a[])
{
    int down = P.LB;
    int up   = P.UB;
    int x = a[down];     // pivot element

    while (down <= up)
    {
        while (a[down] <= x)   // move down forward
            down++;

        while (a[up] > x)      // move up backward
            up--;

        if (down < up)         // swap if needed
            swap(a[down], a[up]);
    }

    // finally swap pivot with a[up]
    swap(a[P.LB], a[up]);

    return up;   // return pivot final position
}

// ---------- Iterative Quick Sort ----------
void QuickSort(int a[], int n)
{
    Bound stack[50];
    int top = -1;

    Bound P;
    P.LB = 0;
    P.UB = n - 1;

    // push initial range
    stack[++top] = P;

    // run while stack not empty
    while (top != -1)
    {
        // pop
        P = stack[top--];

        while (P.LB < P.UB)
        {
            int j = Partition(P, a);

            // Decide which subarray is larger
            if ((j - P.LB) > (P.UB - j))
            {
                // Left side is larger
                Bound temp;
                temp.LB = P.LB;
                temp.UB = j - 1;
                stack[++top] = temp;  // push left part

                P.LB = j + 1;   // only sort right part now
            }
            else
            {
                // Right side is larger
                Bound temp;
                temp.LB = j + 1;
                temp.UB = P.UB;
                stack[++top] = temp;  // push right part

                P.UB = j - 1;   // only sort left part now
            }
        }
    }
}

// ---------- Main Function ----------
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    QuickSort(a, n);

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
