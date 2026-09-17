#include <iostream>
#include <stack>
using namespace std;

// Function to check if character is letter or digit
bool isOperand(char c) {
    // A-Z or a-z or 0-9
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return true;

    return false;
}

// Function to return operator precedence
int precedence(char op) {
    if (op == '^' || op == '%' || op == '$')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '$' || c == '%');
}

// Convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for (char c : infix) {

        if (isOperand(c)) {               // operand → directly add
            postfix += c;
        }
        else if (c == '(') {              // '(' → push to stack
            st.push(c);
        }
        else if (c == ')') {              // ')' → pop until '('
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();                 // pop '('
        }
        else if (isOperator(c)) {         // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0;
}
