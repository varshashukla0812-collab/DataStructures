#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Enter size of array: ";
    cin >> N;

    int A[N];
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int x, i = 0, C = 0;

    cout << "Enter number to search: ";
    cin >> x;

    // Repeat step 4 while i < N
    while (i < N) {
        if (A[i] == x) {   // If A[i] = x
            C = C + 1;     // increase C
            break;         // go to step 5 (stop loop)
        }
        else {
            i = i + 1;     // i = i + 1
        }
    }

    // Step 5
    if (C == 0)
        cout << "Number not found";
    else
        cout << "Number found";

    return 0;
}
