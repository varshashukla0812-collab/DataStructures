#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];   // array

    cout << "Enter " << n << " elements:\n";
    for (int k = 0; k < n; k++) {
        cin >> a[k];
    }

    int i = 0, j, c;  

    while (i < n - 1) {
        j = i + 1;

        while (j < n) {
            if (a[i] > a[j]) {
                c = a[i];      // swapping
                a[i] = a[j];
                a[j] = c;
            }
            j = j + 1;
        }

        i = i + 1;
    }

    cout << "Sorted array: ";
    for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }

    return 0;
}
