#include <iostream>
using namespace std;

int main() {
    int n, i, j, c;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[50];  // assuming max 50 elements for simplicity

    cout << "Enter " << n << " elements: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Bubble Sort starts here
    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
            }
        }
    }

    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
