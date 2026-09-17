#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LEFT;
    Node* RIGHT;
};

int main() {
    Node *FIRST = NULL, *LAST = NULL, *PTR, *AVAIL;
    int X, C, choice, n, val;

    cout << "Enter number of nodes to create: ";
    cin >> n;

    // --- CREATE INITIAL DOUBLY LINKED LIST FROM USER INPUT ---
    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> val;

        AVAIL = new Node;
        AVAIL->INFO = val;
        AVAIL->LEFT = LAST;
        AVAIL->RIGHT = NULL;

        if (FIRST == NULL)
            FIRST = AVAIL;
        else
            LAST->RIGHT = AVAIL;

        LAST = AVAIL;
    }

    cout << "\nInitial Doubly Linked List created successfully.\n";

    do {
        cout << "\n1) DELETE FIRST NODE";
        cout << "\n2) DELETE MIDDLE NODE (value X)";
        cout << "\n3) DISPLAY LIST";
        cout << "\n4) EXIT";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {  // DELETE FIRST NODE
            if (FIRST == NULL) {
                cout << "List is empty.\n";
            } else {
                PTR = FIRST;
                FIRST = FIRST->RIGHT;
                if (FIRST != NULL)
                    FIRST->LEFT = NULL;
                else
                    LAST = NULL;
                cout << "Deleted first node (" << PTR->INFO << ")\n";
                delete PTR;
            }
        }

        else if (choice == 2) {  // DELETE MIDDLE (any) NODE
            cout << "Enter value X to delete: ";
            cin >> X;
            PTR = FIRST;
            C = 0;

            while (PTR != NULL && PTR->INFO != X)
                PTR = PTR->RIGHT;

            if (PTR == NULL)
                cout << "NOT FOUND\n";
            else {
                cout << "Deleting node (" << PTR->INFO << ")\n";

                // If first node
                if (PTR == FIRST) {
                    FIRST = PTR->RIGHT;
                    if (FIRST != NULL)
                        FIRST->LEFT = NULL;
                    else
                        LAST = NULL;
                }
                // If last node
                else if (PTR == LAST) {
                    LAST = PTR->LEFT;
                    if (LAST != NULL)
                        LAST->RIGHT = NULL;
                }
                // Middle node
                else {
                    PTR->LEFT->RIGHT = PTR->RIGHT;
                    PTR->RIGHT->LEFT = PTR->LEFT;
                }
                delete PTR;
            }
        }

        else if (choice == 3) {  // DISPLAY LIST
            PTR = FIRST;
            cout << "List (forward): ";
            while (PTR != NULL) {
                cout << PTR->INFO << " ";
                PTR = PTR->RIGHT;
            }
            cout << "\n";
        }

        else if (choice == 4) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
