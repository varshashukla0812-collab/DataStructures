#include <iostream>
using namespace std;

#define N 5  // size of queue

int QUEUE[N];
int FRONT = -1, REAR = -1;
int VALUE;

// Function to insert an element in circular queue
void QUEUEINSERT() {
    // Overflow condition
    if ((FRONT == 0 && REAR == N - 1) || (FRONT == REAR + 1)) {
        cout << "Queue Overflow!" << endl;
        return;
    }

    cout << "Enter a number to insert: ";
    cin >> VALUE;

    // First element insertion
    if (FRONT == -1 && REAR == -1) {
        FRONT = REAR = 0;
        QUEUE[REAR] = VALUE;
    }
    // If REAR is at end but space available in beginning
    else if (REAR == N - 1 && FRONT != 0) {
        REAR = 0;
        QUEUE[REAR] = VALUE;
    }
    // Normal insertion
    else {
        REAR = (REAR + 1) % N;
        QUEUE[REAR] = VALUE;
    }

    cout << "Inserted: " << VALUE << endl;
}

// Function to delete an element from circular queue
void QUEUEDELETE() {
    // Underflow condition
    if (FRONT == -1 && REAR == -1) {
        cout << "Queue Underflow!" << endl;
        return;
    }

    VALUE = QUEUE[FRONT];
    cout << "Deleted: " << VALUE << endl;

    // Only one element left
    if (FRONT == REAR) {
        FRONT = REAR = -1;
    }
    // If FRONT is at end
    else if (FRONT == N - 1)
        FRONT = 0;
    else
        FRONT = FRONT + 1;
}

// Function to display the queue
void DISPLAY() {
   int i;

    if (FRONT == -1 && REAR == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements are: ";

    i = FRONT;
    if (FRONT <= REAR) {
        while (i <= REAR) {
            cout << QUEUE[i] << " ";
            i = i + 1;
        }
    } else {
        // Print from FRONT to N-1
        while (i <= N - 1) {
            cout << QUEUE[i] << " ";
            i = i + 1;
        }
        i = 0;
        // Print from 0 to REAR
        while (i <= REAR) {
            cout << QUEUE[i] << " ";
            i = i + 1;
        }
    }
    cout << endl;
}


// Main function
int main() {
    int choice;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                QUEUEINSERT();
                break;
            case 2:
                QUEUEDELETE();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
