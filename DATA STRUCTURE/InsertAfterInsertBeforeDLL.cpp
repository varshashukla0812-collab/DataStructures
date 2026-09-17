#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LEFT;
    Node* RIGHT;
};

int main() {
    Node *FIRST = NULL, *LAST = NULL, *PTR, *P, *AVAIL;
    int X, Y, n, i, ch;

    // ----- Step 1: Create the initial list -----
    cout << "Enter number of initial nodes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> X;

        AVAIL = new Node;
        AVAIL->INFO = X;
        AVAIL->LEFT = LAST;
        AVAIL->RIGHT = NULL;

        if (FIRST == NULL) {
            FIRST = AVAIL;
            LAST = AVAIL;
        } else {
            LAST->RIGHT = AVAIL;
            LAST = AVAIL;
        }
    }

    cout << "\nInitial Doubly Linked List Created.\n";

    // ----- Step 2: Menu for insertions -----
    do {
        cout << "\n1) INSERT AFTER a node";
        cout << "\n2) INSERT BEFORE a node (any)";
        cout << "\n3) INSERT BEFORE FIRST node";
        cout << "\n4) DISPLAY LIST";
        cout << "\n5) EXIT";
        cout << "\nEnter your choice: ";
        cin >> ch;

        if (ch == 1) {   // INSERT AFTER a node
            cout << "Enter X (value after which to insert): ";
            cin >> X;

            PTR = FIRST;
            while (PTR != NULL && PTR->INFO != X)
                PTR = PTR->RIGHT;

            if (PTR == NULL)
                cout << "NOT FOUND\n";
            else {
                cout << "Enter Y (value to insert after " << X << "): ";
                cin >> Y;
                AVAIL = new Node;
                P = AVAIL;
                P->INFO = Y;
                P->LEFT = PTR;
                P->RIGHT = PTR->RIGHT;

                if (PTR->RIGHT != NULL)
                    PTR->RIGHT->LEFT = P;

                PTR->RIGHT = P;
                if (PTR == LAST)
                    LAST = P;

                cout << "Inserted after " << X << ".\n";
            }
        }

        else if (ch == 2) {   // INSERT BEFORE a node
            cout << "Enter X (value before which to insert): ";
            cin >> X;

            PTR = FIRST;
            while (PTR != NULL && PTR->INFO != X)
                PTR = PTR->RIGHT;

            if (PTR == NULL)
                cout << "NOT FOUND\n";
            else {
                cout << "Enter Y (value to insert before " << X << "): ";
                cin >> Y;
                AVAIL = new Node;
                P = AVAIL;
                P->INFO = Y;
                P->RIGHT = PTR;
                P->LEFT = PTR->LEFT;

                if (PTR->LEFT != NULL)
                    PTR->LEFT->RIGHT = P;
                PTR->LEFT = P;

                if (PTR == FIRST)
                    FIRST = P;

                cout << "Inserted before " << X << ".\n";
            }
        }

        else if (ch == 3) {   // INSERT BEFORE FIRST
            cout << "Enter Y (value to insert before first): ";
            cin >> Y;

            AVAIL = new Node;
            P = AVAIL;
            P->INFO = Y;
            P->LEFT = NULL;
            P->RIGHT = FIRST;

            if (FIRST != NULL)
                FIRST->LEFT = P;
            FIRST = P;
            if (LAST == NULL)
                LAST = P;

            cout << "Inserted before first node.\n";
        }

        else if (ch == 4) {   // DISPLAY LIST
            cout << "\nDoubly Linked List: ";
            PTR = FIRST;
            while (PTR != NULL) {
                cout << PTR->INFO << " ";
                PTR = PTR->RIGHT;
            }
            cout << "\n";
        }

        else if (ch == 5)
            cout << "Exiting...\n";

        else
            cout << "Invalid choice!\n";

    } while (ch != 5);

    return 0;
}
