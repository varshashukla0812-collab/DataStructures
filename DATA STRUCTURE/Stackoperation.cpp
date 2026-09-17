#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of the stack

int main() {
    int stack[MAX];   // Stack array
    int top = -1;     // Initialize top to -1 (empty stack)
    int ITEM, choice;

    while (true) {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            // PUSH operation
            case 1:
                if (top == MAX - 1) {
                    cout << "Stack Overflow! Cannot push more elements.\n";
                } 
                else {
                    cout << "Enter element to PUSH: ";
                    cin >> ITEM;
                    top = top + 1;
                    stack[top] = ITEM;
                    cout << ITEM << " pushed into the stack.\n";
                }
                break;

            // POP operation
            case 2:
                if (top == -1) {
                    cout << "Stack Underflow! No elements to pop.\n";
                } 
                else {
                    ITEM = stack[top];
                    top = top - 1;
                    cout << ITEM << " popped from the stack.\n";
                }
                break;

            // DISPLAY operation
            case 3:
                if (top == -1) {
                    cout << "Stack is empty.\n";
                } 
                else {
                    cout << "Current Stack: ";
                    for (int i = 0; i <= top; i++) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            // EXIT
            case 4:
                cout << "Exiting program. Thank you!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
