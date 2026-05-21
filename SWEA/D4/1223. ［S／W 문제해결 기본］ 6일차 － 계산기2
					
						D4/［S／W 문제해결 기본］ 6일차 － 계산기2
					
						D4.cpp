#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int test_case = 1; test_case <= 10; test_case++) {
        int N;
        string expr;

        cin >> N;
        cin >> expr;

        stack<char> opStack;
        string postfix = "";

        for (char ch : expr) {
            if (ch >= '0' && ch <= '9') {
                postfix += ch;
            }
            else if (ch == '+') {
                while (!opStack.empty()) {
                    postfix += opStack.top();
                    opStack.pop();
                }

                opStack.push(ch);
            }
            else if (ch == '*') {
                while (!opStack.empty() && opStack.top() == '*') {
                    postfix += opStack.top();
                    opStack.pop();
                }

                opStack.push(ch);
            }
        }

        while (!opStack.empty()) {
            postfix += opStack.top();
            opStack.pop();
        }

        stack<int> numStack;

        for (char ch : postfix) {
            if (ch >= '0' && ch <= '9') {
                numStack.push(ch - '0');
            }
            else {
                int b = numStack.top();
                numStack.pop();

                int a = numStack.top();
                numStack.pop();

                if (ch == '+') {
                    numStack.push(a + b);
                }
                else if (ch == '*') {
                    numStack.push(a * b);
                }
            }
        }

        cout << "#" << test_case << " " << numStack.top() << "\n";
    }

    return 0;
}