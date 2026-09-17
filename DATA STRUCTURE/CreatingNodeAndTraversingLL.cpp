#include <iostream>
using namespace std;

struct Node {
    int INFO;     // Data part
    Node* LINK;   // Pointer part
};

int main() {
    Node *START = NULL, *PTR, *AVAIL, *LAST = NULL;
    int x, n;

    cout << "Enter the number of nodes to create: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> x;

        // Step 2: Allocate new node (AVAIL)
        AVAIL = new Node;

        // Step 3: Create node (INFO & LINK)
        AVAIL->INFO = x;
        AVAIL->LINK = NULL;

        // Step 4: If START is NULL, first node
        if (START == NULL) {
            START = AVAIL;
            LAST = AVAIL;
        } else {
            // Step 5: Link new node to the last node
            LAST->LINK = AVAIL;
            LAST = AVAIL;
        }
    }

    // Step 6: Traversing the Linked List
    cout << "\nLinked List Elements:\n";
    PTR = START;

    while (PTR != NULL) {
        cout << PTR->INFO << " ";
        PTR = PTR->LINK;
    }

    cout << endl;
    return 0;
}
