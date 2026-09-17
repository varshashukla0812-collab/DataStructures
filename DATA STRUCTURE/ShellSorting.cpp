#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int span, k, i, j, x;

    // Step 1
    span = n / 2;

    // Step 2
    while (span >= 1) {

        // Step 3
        k = 0;

        // Step 4
        while (k < span) {

            // Step 5
            i = k + span;

            // Step 6
            while (i < n) {

                // Step 7
                x = a[i];

                // Step 8
                j = i - span;

                // Step 9
                while (j >= 0) {

                    // Step 10
                    if (a[j] > x) {
                        a[j + span] = a[j];   // Step 10 then-part
                    } else {
                        break;               // go to step 12
                    }

                    // Step 11
                    j = j - span;
                }

                // Step 12
                a[j + span] = x;

                // Step 13
                i = i + span;
            }

            // Step 14
            k = k + 1;
        }

        // Step 15
        span = span / 2;
    }

    // Print sorted array
    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
