#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string ReturnScore(int idx, int n) {
	if (idx <= n * 0.1)
		return "A+";
	else if (idx <= n * 0.2)
		return "A0";
	else if (idx <= n * 0.3)
		return "A-";
	else if (idx <= n * 0.4)
		return "B+";
	else if (idx <= n * 0.5)
		return "B0";
	else if (idx <= n * 0.6)
		return "B-";
	else if (idx <= n * 0.7)
		return "C+";
	else if (idx <= n * 0.8)
		return "C0";
	else if (idx <= n * 0.9)
		return "C-";
	else
		return "D0";
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n, k;
		cin >> n >> k;

		vector<pair<double, int>> info(n);
		for (int i = 0; i < n; i++) {
			int mid, final, ass;
			cin >> mid >> final >> ass;
			double score = mid * 0.35 + final * 0.45 + ass * 0.2;
			info[i] = { score, i+1 };
		}

		sort(info.begin(), info.end(), greater<pair<double, int>>());

		string ans;
		for (int i = 0; i < n; i++) 
			if (info[i].second == k)
				ans = ReturnScore(i+1, n);
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}