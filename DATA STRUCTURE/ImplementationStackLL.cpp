#include <iostream>
using namespace std;

// Node structure 
struct node {
    int info;      // INFO field
    node* link;    // LINK field
};

// LAST will hold the top of the stack 
node* LAST = nullptr;  
node* ptr = nullptr;    // working pointer

// Push X onto stack
void push(int x) {
    // Step 1: allocate a new node and set ptr to it
    ptr = new node;
    // Step 2: set INFO[ptr] = x
    ptr->info = x;
    // Step 3: link[ptr] = LAST (insert at front)
    ptr->link = LAST;
    // Step 4: LAST = ptr (new node becomes top)
    LAST = ptr;
    cout << x << " pushed onto stack.\n";
}

// Pop top element from stack
void popStack() {
    if (LAST == nullptr) {
        cout << "Stack UNDERFLOW (stack is empty).\n";
        return;
    }
    // ptr points to the node being popped (top)
    ptr = LAST;
    cout << "Popped: " << ptr->info << "\n";
    // move LAST to next node
    LAST = LAST->link;
    // free the popped node
    delete ptr;
    ptr = nullptr;
}

// Display stack (from top to bottom)
void display() {
    if (LAST == nullptr) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack (top -> bottom): ";
    ptr = LAST;
    while (ptr != nullptr) {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << "\n";
}

int main() {
    int choice, x;
    while (true) {
        cout << "\n--- Stack Using Linked List ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> x;
                push(x);
                break;
            case 2:
                popStack();
                break;
            case 3:
                display();
                break;
            case 4:
                // free remaining nodes before exit 
                while (LAST != nullptr) {
                    ptr = LAST;
                    LAST = LAST->link;
                    delete ptr;
                }
                cout << "Exiting.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
