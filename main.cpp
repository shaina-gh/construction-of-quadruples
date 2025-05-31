#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

// Struct for a quadruple
struct Quadruple {
    string op;
    string arg1;
    string arg2;
    string result;
};

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char &c : infix) {
        if (isalnum(c)) {
            postfix += c;  // If it's a number/variable, add to postfix
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Remove '('
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Generate Intermediate Code (Quadruples)
vector<Quadruple> generateQuadruples(string postfix) {
    stack<string> s;
    vector<Quadruple> quadruples;
    int tempCount = 1;

    for (char &c : postfix) {
        if (isalnum(c)) {
            string operand(1, c);
            s.push(operand);  // Push operand to stack
        } else if (isOperator(c)) {
            string arg2 = s.top(); s.pop();
            string arg1 = s.top(); s.pop();
            string temp = "T" + to_string(tempCount++);  // Create temporary variable

            // Create quadruple
            Quadruple quad;
            quad.op = string(1, c);
            quad.arg1 = arg1;
            quad.arg2 = arg2;
            quad.result = temp;
            quadruples.push_back(quad);

            s.push(temp);  // Push result back to stack
        }
    }

    return quadruples;
}

// Print quadruples
void printQuadruples(const vector<Quadruple>& quadruples) {
    cout << "\nQuadruples:\n";
    for (const auto &quad : quadruples) {
        cout << "(" << quad.op << ", " << quad.arg1 << ", " << quad.arg2 << ", " << quad.result << ")\n";
    }
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Step 1: Convert to Postfix
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    // Step 2: Generate Quadruples
    vector<Quadruple> quadruples = generateQuadruples(postfix);

    // Print the quadruples
    printQuadruples(quadruples);

    return 0;
}
