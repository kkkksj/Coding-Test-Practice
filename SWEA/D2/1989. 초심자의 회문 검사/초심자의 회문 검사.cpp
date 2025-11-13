#include<iostream>
#include<stack>

using namespace std;

bool IsPal(string word) {
	int n = word.size();
	stack<char> st;

	for (int i = 0; i < n; i++) {
		if (n % 2 == 1 && i == n / 2)
			continue;
		if (st.empty() || st.top() != word[i])
			st.push(word[i]);
		else
			st.pop();
	}
	if (st.empty())
		return 1;
	return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string word;
		cin >> word;

		bool ans = IsPal(word);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}