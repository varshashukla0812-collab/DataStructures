#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    Node *START = NULL, *PTR, *AVAIL, *P, *PREV;
    int ch, x, y;

    // Create an initial linked list
    int n;
    cout << "Enter number of initial nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> y;

        AVAIL = new Node;
        AVAIL->INFO = y;
        AVAIL->LINK = NULL;

        if (START == NULL)
            START = AVAIL;
        else {
            PTR = START;
            while (PTR->LINK != NULL)
                PTR = PTR->LINK;
            PTR->LINK = AVAIL;
        }
    }

    do {
        cout << "\n1) INSERT AFTER\n2) INSERT BEFORE\n3) DISPLAY\n4) EXIT\nChoice: ";
        cin >> ch;

        if (ch == 1) {                // INSERT AFTER
            cout << "Enter X (value to search): ";
            cin >> x;
            PTR = START;
            while (PTR != NULL && PTR->INFO != x)
                PTR = PTR->LINK;
            if (PTR == NULL) {
                cout << "NOT FOUND\n";
            } else {
                cout << "Enter Y (value to insert after " << x << "): ";
                cin >> y;
                P = new Node;
                P->INFO = y;
                P->LINK = PTR->LINK;
                PTR->LINK = P;
                cout << "Inserted after " << x << ".\n";
            }
        }
        else if (ch == 2) {           // INSERT BEFORE
            cout << "Enter X (value to search): ";
            cin >> x;
            PTR = START; PREV = NULL;
            while (PTR != NULL && PTR->INFO != x) {
                PREV = PTR;
                PTR = PTR->LINK;
            }
            if (PTR == NULL) {
                cout << "NOT FOUND\n";
            } else {
                cout << "Enter Y (value to insert before " << x << "): ";
                cin >> y;
                P = new Node;
                P->INFO = y;
                if (PTR == START) {    // insert before first node
                    P->LINK = START;
                    START = P;
                } else {               // insert before middle/last
                    P->LINK = PTR;
                    PREV->LINK = P;
                }
                cout << "Inserted before " << x << ".\n";
            }
        }
        else if (ch == 3) {           // DISPLAY
            cout << "List: ";
            PTR = START;
            while (PTR != NULL) {
                cout << PTR->INFO << " ";
                PTR = PTR->LINK;
            }
            cout << "\n";
        }
        else if (ch == 4) {
            cout << "Exiting.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (ch != 4);

    return 0;
}
