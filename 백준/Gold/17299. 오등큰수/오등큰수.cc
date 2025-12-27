#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int n;
unordered_map<int, int> f;
vector<int> arr;
vector<int> ans;
stack<int> st;

int main() {
	cin >> n;
	arr.assign(n, 0);
	ans.assign(n, 0);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		f[num]++;
	}

	for (int i = n - 1; i >= 0; i--) {
		int num = arr[i];
		int fnum = f[num];

		while (!st.empty()) {
			if (fnum >= f[arr[st.top()]])
				st.pop();
			else
				break;
		}

		if (st.empty())
			ans[i] = -1;
		else
			ans[i] = arr[st.top()];
		st.push(i);
	}

	for (int a : ans)
		cout << a << ' ';
	cout << '\n';
}