#include <iostream>
using namespace std;

int main() {
    int n, i, j, x;
    
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];   // simple array

    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    // -------- Insertion Sort Starts --------
    i = 1;                     // Step 1
    while (i < n) {            // Step 2
        x = a[i];              // Step 3
        j = i - 1;             // Step 4
        
        while (j >= 0) {       // Step 5
            if (a[j] > x) {    // Step 6
                a[j + 1] = a[j];
            } else {
                break;         // go to step 8
            }
            j = j - 1;         // Step 7
        }

        a[j + 1] = x;          // Step 8
        i = i + 1;             // Step 9
    }
    // -------- Insertion Sort Ends --------

    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
