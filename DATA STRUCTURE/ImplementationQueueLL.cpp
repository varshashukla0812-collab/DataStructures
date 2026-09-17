#include <iostream>
using namespace std;

// Node structure 
struct node {
    int info;       // INFO field
    node* link;     // LINK field
};

// Global pointers
node* FRONT = nullptr;
node* REAR = nullptr;
node* ptr = nullptr;

// Function to insert element into queue
void insertionQueue(int x) {
    // Step 1: allocate new node (acts as AVAIL)
    ptr = new node;
    ptr->info = x;
    ptr->link = nullptr;

    // Step 2: if FRONT and REAR are NULL, first node in queue
    if (FRONT == nullptr && REAR == nullptr) {
        FRONT = ptr;
        REAR = ptr;
    } else {
        // Step 3: link the new node at the end of queue
        REAR->link = ptr;
        REAR = ptr;
    }
    cout << x << " inserted into queue.\n";
}

// Function to delete element from queue
void deleteQueue() {
    if (FRONT == nullptr && REAR == nullptr) {
        cout << "Queue UNDERFLOW (empty queue).\n";
        return;
    }

    // If there is only one element
    if (FRONT == REAR) {
        cout << "Deleted: " << FRONT->info << "\n";
        delete FRONT;
        FRONT = nullptr;
        REAR = nullptr;
    } else {
        // More than one element
        ptr = FRONT;
        cout << "Deleted: " << ptr->info << "\n";
        FRONT = FRONT->link;
        delete ptr;
    }
}

// Function to display the queue
void display() {
    if (FRONT == nullptr && REAR == nullptr) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements (FRONT -> REAR): ";
    ptr = FRONT;
    while (ptr != nullptr) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << "\n";
}

// Main function: 
int main() {
    int choice, x;

    while (true) {
        cout << "\n--- QUEUE USING LINKED LIST ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                insertionQueue(x);
                break;
            case 2:
                deleteQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                // Clean up memory before exit
                while (FRONT != nullptr) {
                    ptr = FRONT;
                    FRONT = FRONT->link;
                    delete ptr;
                }
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
