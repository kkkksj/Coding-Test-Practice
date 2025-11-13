#include<iostream>
#include<stack>

using namespace std;

bool IsRight(string input) {
	stack<char> st;
	for (char c : input) {
		if (st.empty())
			st.push(c);
		else if (c == ')' && st.top() == '(')
			st.pop();
		else if (c == '}' && st.top() == '{')
			st.pop();
		else if (c == ']' && st.top() == '[')
			st.pop();
		else if (c == '>' && st.top() == '<')
			st.pop();
		else
			st.push(c);
	}
	return st.empty();
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		string input;
		cin >> input;

		bool ans = IsRight(input);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}