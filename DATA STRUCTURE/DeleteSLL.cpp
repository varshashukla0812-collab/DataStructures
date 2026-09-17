#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    Node *START = NULL, *PTR, *PREV, *AVAIL;
    int x, c = 0, n, i;

    // ----- Create initial linked list -----
    cout << "Enter number of nodes: ";
    cin >> n;

    for (i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> x;
        AVAIL = new Node;
        AVAIL->INFO = x;
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

    // ----- Deletion operation -----
    cout << "\nEnter number (X) to delete: ";
    cin >> x;

    PREV = NULL;
    PTR = START;
    c = 0;

    // Step 5: Search the node
    while (PTR != NULL) {
        if (PTR->INFO == x) {
            c = c + 1;
            break;
        } else {
            PREV = PTR;
            PTR = PTR->LINK;
        }
    }

    // Step 7: If not found
    if (c == 0) {
        cout << "\nNOT FOUND\n";
    }
    else {
        // Step 8: Delete node
        if (PTR == START) {
            START = START->LINK;
        } else {
            PREV->LINK = PTR->LINK;
        }

        // Step 9 & 10: Free node
        PTR->LINK = AVAIL;
        AVAIL = PTR;
        delete PTR;

        cout << "\nNode deleted successfully.\n";
    }

    // ----- Display updated list -----
    cout << "\nLinked List after deletion:\n";
    PTR = START;
    while (PTR != NULL) {
        cout << PTR->INFO << " ";
        PTR = PTR->LINK;
    }
    cout << endl;

    return 0;
}
