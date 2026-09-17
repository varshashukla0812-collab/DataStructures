#include <iostream>
using namespace std;

int main() {
    int DATA[50], N;

    cout << "Enter size of array: ";
    cin >> N;

    cout << "Enter " << N << " sorted elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> DATA[i];
    }

    int ITEM;
    cout << "Enter number to search: ";
    cin >> ITEM;

    
    int LB = 0;
    int UB = N - 1;
    int BEG = LB;
    int END = UB;
    int MID = (BEG + END) / 2;

    // Repeat while BEG <= END and DATA[MID] != ITEM
    while (BEG <= END && DATA[MID] != ITEM) {

        if (ITEM < DATA[MID]) {
            END = MID - 1;      // Search left half
        }
        else {
            BEG = MID + 1;      // Search right half
        }

        MID = (BEG + END) / 2;  // Update MID
    }

    // Step 6
    if (DATA[MID] == ITEM)
        cout << "Number found";
    else
        cout << "Number not found";

    return 0;
}
