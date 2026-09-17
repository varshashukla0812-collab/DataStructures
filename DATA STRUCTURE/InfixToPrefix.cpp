#include <iostream>
#include <stack>
using namespace std;

// Check if character is letter or digit (operand)
bool isOperand(char c) {
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

// Check if operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '$' || c == '%');
}

// Operator precedence
int precedence(char op) {
    if (op == '^'|| op == '%' || op == '$') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix → postfix (uses char array)
void infixToPostfix(char infix[], char postfix[]) {
    stack<char> st;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix[j++] = st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();   // pop '('
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix[j++] = st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix[j++] = st.top();
        st.pop();
    }

    postfix[j] = '\0';   // end of string
}

// Reverse a char array
void reverseCharArray(char arr[]) {
    int start = 0;
    int end = 0;

    while (arr[end] != '\0') end++; // find length
    end--; // last character

    while (start < end) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Convert infix → prefix (without <string>)
void infixToPrefix(char infix[], char prefix[]) {
    // 1. Reverse infix
    reverseCharArray(infix);

    // 2. Swap '(' and ')'
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // 3. Convert reversed infix → postfix
    char postfix[100];
    infixToPostfix(infix, postfix);

    // 4. Reverse postfix → prefix
    for (int i = 0; postfix[i] != '\0'; i++) {
        prefix[i] = postfix[i];
        prefix[i + 1] = '\0';
    }

    reverseCharArray(prefix);
}

int main() {
    char infix[100], prefix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPrefix(infix, prefix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
