#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node *LINK;
};

int main() {
    Node *START = NULL, *PTR, *AVAIL, *P;
    int x, ch;

    do {
        cout << "\n1. INSERT FIRST\n2. INSERT LAST\n3. DISPLAY\n4. EXIT\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1: // INSERT FIRST
                cout << "Enter number: ";
                cin >> x;
                AVAIL = new Node;
                PTR = AVAIL;
                PTR->INFO = x;
                if (START == NULL) {
                    START = PTR;
                    START->LINK = NULL;
                } else {
                    P = START;
                    START = PTR;
                    START->LINK = P;
                }
                break;

            case 2: // INSERT LAST
                cout << "Enter number: ";
                cin >> x;
                AVAIL = new Node;
                PTR = AVAIL;
                PTR->INFO = x;
                PTR->LINK = NULL;
                if (START == NULL)
                    START = PTR;
                else {
                    P = START;
                    while (P->LINK != NULL)
                        P = P->LINK;
                    P->LINK = PTR;
                }
                break;

            case 3: // DISPLAY
                PTR = START;
                cout << "\nLinked List: ";
                while (PTR != NULL) {
                    cout << PTR->INFO << " ";
                    PTR = PTR->LINK;
                }
                cout << endl;
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (ch != 4);

    return 0;
}
