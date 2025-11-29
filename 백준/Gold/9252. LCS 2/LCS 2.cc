#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int a_sz = a.size();
	int b_sz = b.size();

	vector<vector<int>> dp(a_sz + 1, vector<int>(b_sz + 1, 0));
	for(int i=1; i<a_sz+1; i++)
		for (int j = 1; j < b_sz + 1; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	stack<char> st;
	int i = a_sz, j = b_sz;
	while (i > 0 && j > 0) {
		if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
			st.push(b[j - 1]);
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j]) 
			i--;
		else 
			j--;
	}

	if (dp[a_sz][b_sz] == 0)
		cout << 0 << '\n';
	else
		cout << dp[a_sz][b_sz] << '\n';
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}