#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50], c[50];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int size, L1, U1, L2, U2, i, j, k;

    // Step 1
    size = 1;

    // Step 2
    while (size < n) {

        // Step 3
        L1 = 0;
        k = 0;

        // Step 4
        while (L1 + size < n) {

            // Step 5
            U1 = L1 + size - 1;

            // Step 6
            L2 = U1 + 1;

            // Step 7
            if (L2 + size - 1 < n)
                U2 = L2 + size - 1;
            else
                U2 = n - 1;

            // Step 8
            i = L1;
            j = L2;

            // Step 9
            while (i <= U1 && j <= U2) {

                // Step 10
                if (a[i] < a[j]) {
                    c[k] = a[i];
                    k++;
                    i++;
                } else {
                    c[k] = a[j];
                    k++;
                    j++;
                }
            }

            // Step 11
            while (i <= U1) {
                c[k] = a[i];
                k++;
                i++;
            }

            // Step 15
            while (j <= U2) {
                c[k] = a[j];
                k++;
                j++;
            }

            // Step 19
            L1 = U2 + 1;
        }

        // Step 20
        while (k < n) {
            c[k] = a[k];
            k++;
        }

        // Step 22
        k = 0;

        // Step 24
        while (k < n) {
            a[k] = c[k];
            k++;
        }

        // Step 27
        size = size * 2;
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
