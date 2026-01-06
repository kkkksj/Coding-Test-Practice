#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	string formula;
	cin >> formula;

	stack<char> st;
	string ans = "";

	for (char c : formula) {
		if (c >= 'A' && c <= 'Z')
			ans += c;
		else if (c == '(')
			st.push(c);
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (c == '*' || c == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!st.empty() && st.top() != '(') {
				ans += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
    
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans << '\n';
}