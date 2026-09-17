#include <iostream>
using namespace std;

#define N 5  // Size of Queue

int main() {
    int ARR[N];
    int FRONT = -1, REAR = -1;
    int VALUE, choice;

    while (true) {
        cout << "\n----- QUEUE MENU -----\n";
        cout << "1. INSERT\n";
        cout << "2. DELETE\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // INSERTION
        if (choice == 1) {
            if (REAR == N - 1) {
                cout << "OVERFLOW! Queue is full.\n";
            } else {
                cout << "Enter a number to insert: ";
                cin >> VALUE;
                REAR = REAR + 1;
                ARR[REAR] = VALUE;

                if (FRONT == -1)
                    FRONT = 0;

                cout << VALUE << " inserted into queue.\n";
            }
        }

        // DELETION
        else if (choice == 2) {
            if (FRONT == -1 && REAR == -1) {
                cout << "UNDERFLOW! Queue is empty.\n";
            } 
            else if (FRONT == REAR) {
                VALUE = ARR[FRONT];
                cout << "Deleted value: " << VALUE << endl;
                FRONT = -1;
                REAR = -1;
            } 
            else {
                VALUE = ARR[FRONT];
                cout << "Deleted value: " << VALUE << endl;
                FRONT = FRONT + 1;
            }
        }

        // DISPLAY
        else if (choice == 3) {
            if (FRONT == -1 && REAR == -1) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Queue elements are: ";
                for (int i = FRONT; i <= REAR; i++) {
                    cout << ARR[i] << " ";
                }
                cout << endl;
            }
        }

        // EXIT
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
