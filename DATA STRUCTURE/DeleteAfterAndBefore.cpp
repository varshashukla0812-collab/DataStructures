#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LEFT;
    Node* RIGHT;
};

int main() {
    Node *FIRST = NULL, *LAST = NULL, *PTR, *P, *AVAIL;
    int n, val, choice, X;

    // --- Create initial doubly linked list from user ---
    cout << "Enter number of nodes to create: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;
        AVAIL = new Node;        // allocate new node
        AVAIL->INFO = val;
        AVAIL->LEFT = LAST;
        AVAIL->RIGHT = NULL;
        if (FIRST == NULL) FIRST = AVAIL;
        else LAST->RIGHT = AVAIL;
        LAST = AVAIL;
    }
    cout << "Initial list created.\n";

    do {
        cout << "\nMenu:\n";
        cout << "1) DELETE AFTER X\n";
        cout << "2) DELETE BEFORE X\n";
        cout << "3) DISPLAY FORWARD\n";
        cout << "4) DISPLAY REVERSE\n";
        cout << "5) EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {               // DELETE AFTER X
            cout << "Enter X (node value to search): ";
            cin >> X;
            PTR = FIRST;
            while (PTR != NULL && PTR->INFO != X)
                PTR = PTR->RIGHT;

            if (PTR == NULL) {
                cout << "NOT FOUND (no node with value X)\n";
            } else if (PTR->RIGHT == NULL) {
                cout << "No node exists after X to delete.\n";
            } else {
                P = PTR->RIGHT;   // node to be deleted (after PTR)
                cout << "Deleting node after " << X << " (value " << P->INFO << ")\n";

                // Link PTR to P->RIGHT
                PTR->RIGHT = P->RIGHT;
                if (P->RIGHT != NULL) {
                    P->RIGHT->LEFT = PTR;
                } else {
                    // Deleted node was LAST
                    LAST = PTR;
                }

                // optional: keep AVAIL as free pointer (matches notes)
                AVAIL = P;
                delete P;
            }
        }
        else if (choice == 2) {          // DELETE BEFORE X
            cout << "Enter X (node value to search): ";
            cin >> X;
            PTR = FIRST;
            while (PTR != NULL && PTR->INFO != X)
                PTR = PTR->RIGHT;

            if (PTR == NULL) {
                cout << "NOT FOUND (no node with value X)\n";
            } else if (PTR->LEFT == NULL) {
                cout << "No node exists before X to delete.\n";
            } else {
                P = PTR->LEFT;   // node to be deleted (before PTR)
                cout << "Deleting node before " << X << " (value " << P->INFO << ")\n";

                // Link PTR to P->LEFT
                PTR->LEFT = P->LEFT;
                if (P->LEFT != NULL) {
                    P->LEFT->RIGHT = PTR;
                } else {
                    // Deleted node was FIRST
                    FIRST = PTR;
                    PTR->LEFT = NULL;
                }

                AVAIL = P;
                delete P;
            }
        }
        else if (choice == 3) {          // DISPLAY FORWARD
            cout << "List (forward): ";
            PTR = FIRST;
            while (PTR != NULL) {
                cout << PTR->INFO << " ";
                PTR = PTR->RIGHT;
            }
            cout << "\n";
        }
        else if (choice == 4) {          // DISPLAY REVERSE
            cout << "List (reverse): ";
            PTR = LAST;
            while (PTR != NULL) {
                cout << PTR->INFO << " ";
                PTR = PTR->LEFT;
            }
            cout << "\n";
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    // free remaining nodes (clean up)
    PTR = FIRST;
    while (PTR != NULL) {
        P = PTR->RIGHT;
        delete PTR;
        PTR = P;
    }

    return 0;
}
