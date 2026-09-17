#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LEFT;
    Node* RIGHT;
};

int main() {
    Node *FIRST = NULL, *LAST = NULL, *PTR, *AVAIL;
    int x, c, ch;

    do {
        cout << "\n1) INSERT\n2) SEARCH\n3) FORWARD DISPLAY\n4) REVERSE DISPLAY\n5) EXIT\nEnter your choice: ";
        cin >> ch;

        switch(ch) {

            // ---------------- INSERTION ----------------
            case 1:
                cout << "Enter number (X): ";
                cin >> x;

                AVAIL = new Node;       // Step 2: ptr = AVAIL
                PTR = AVAIL;
                PTR->INFO = x;          // Step 4: INFO[ptr] = x
                PTR->LEFT = LAST;       // Step 5: LEFT[ptr] = LAST
                PTR->RIGHT = NULL;      // Step 6: RIGHT[ptr] = NULL

                if (FIRST == NULL && LAST == NULL) { // Step 7: first node condition
                    FIRST = PTR;
                    LAST = PTR;
                } else {
                    LAST->RIGHT = PTR;
                    LAST = PTR;
                }

                cout << "Node inserted.\n";
                break;

            // ---------------- SEARCH ----------------
            case 2:
                cout << "Enter number (X) to search: ";
                cin >> x;
                PTR = FIRST;
                c = 0;

                while (PTR != NULL) {   // Step 4: repeat while ptr ≠ NULL
                    if (PTR->INFO == x) {
                        c = c + 1;      // Step 5: c = c + 1
                        break;
                    } else {
                        PTR = PTR->RIGHT; // move forward
                    }
                }

                if (c == 0)
                    cout << "NOT FOUND\n";
                else
                    cout << "FOUND\n";
                break;

            // ---------------- FORWARD DISPLAY ----------------
            case 3:
                cout << "Forward Display: ";
                PTR = FIRST;
                while (PTR != NULL) {
                    cout << PTR->INFO << " ";
                    PTR = PTR->RIGHT;
                }
                cout << endl;
                break;

            // ---------------- REVERSE DISPLAY ----------------
            case 4:
                cout << "Reverse Display: ";
                PTR = LAST;
                while (PTR != NULL) {
                    cout << PTR->INFO << " ";
                    PTR = PTR->LEFT;
                }
                cout << endl;
                break;

            // ---------------- EXIT ----------------
            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 5);

    return 0;
}
