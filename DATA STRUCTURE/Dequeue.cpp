#include <iostream>
using namespace std;

#define N 5   // Size of the queue

int FRONT = -1;
int REAR = -1;
int ARR[N];

// Function to display the queue
void display() {
    if (FRONT == -1) {
        cout << "\nQueue is EMPTY!\n";
        return;
    }

    cout << "\nQueue elements: ";
    int i = FRONT;
    while (true) {
        cout << ARR[i] << " ";
        if (i == REAR)
            break;
        i = (i + 1) % N;  // Move circularly
    }
    cout << endl;
}

// Function to check if queue is full
bool isFull() {
    return (FRONT == 0 && REAR == N - 1) || (FRONT == REAR + 1);
}

// Function to check if queue is empty
bool isEmpty() {
    return FRONT == -1;
}

// Insert from FRONT
void insertFront(int VALUE) {
    if (isFull()) {
        cout << "\nOVERFLOW! Cannot insert " << VALUE << " at FRONT.\n";
        return;
    }

    if (FRONT == -1) {  // Queue is empty
        FRONT = REAR = 0;
    } 
    else if (FRONT == 0) { // Wrap around
        FRONT = N - 1;
    } 
    else {
        FRONT = FRONT - 1;
    }

    ARR[FRONT] = VALUE;
    cout << "\nInserted " << VALUE << " at FRONT.\n";
}

// Insert from REAR
void insertRear(int VALUE) {
    if (isFull()) {
        cout << "\nOVERFLOW! Cannot insert " << VALUE << " at REAR.\n";
        return;
    }

    if (FRONT == -1) {  // Queue is empty
        FRONT = REAR = 0;
    } 
    else if (REAR == N - 1) { // Wrap around
        REAR = 0;
    } 
    else {
        REAR = REAR + 1;
    }

    ARR[REAR] = VALUE;
    cout << "\nInserted " << VALUE << " at REAR.\n";
}

// Delete from FRONT
void deleteFront() {
    if (isEmpty()) {
        cout << "\nUNDERFLOW! Queue is empty.\n";
        return;
    }

    cout << "\nDeleted element from FRONT: " << ARR[FRONT] << endl;

    if (FRONT == REAR) {  // Only one element
        FRONT = REAR = -1;
    } 
    else if (FRONT == N - 1) { // Wrap around
        FRONT = 0;
    } 
    else {
        FRONT = FRONT + 1;
    }
}

// Delete from REAR
void deleteRear() {
    if (isEmpty()) {
        cout << "\nUNDERFLOW! Queue is empty.\n";
        return;
    }

    cout << "\nDeleted element from REAR: " << ARR[REAR] << endl;

    if (FRONT == REAR) { // Only one element
        FRONT = REAR = -1;
    } 
    else if (REAR == 0) { // Wrap around
        REAR = N - 1;
    } 
    else {
        REAR = REAR - 1;
    }
}

// Main menu
int main() {
    int choice, value;

    while (true) {
        cout << "\n=== DOUBLE ENDED QUEUE MENU ===";
        cout << "\n1. Insert at FRONT";
        cout << "\n2. Insert at REAR";
        cout << "\n3. Delete from FRONT";
        cout << "\n4. Delete from REAR";
        cout << "\n5. Display Queue";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at FRONT: ";
                cin >> value;
                insertFront(value);
                display();
                break;

            case 2:
                cout << "Enter value to insert at REAR: ";
                cin >> value;
                insertRear(value);
                display();
                break;

            case 3:
                deleteFront();
                display();
                break;

            case 4:
                deleteRear();
                display();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "\nExiting program...\n";
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
