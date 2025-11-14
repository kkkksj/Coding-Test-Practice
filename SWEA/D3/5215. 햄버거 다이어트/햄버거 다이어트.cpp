#include<iostream>
#include<vector>

using namespace std;

int n, l;
vector<pair<int, int>> list;
int ans = 0;

void Back(int idx, int sum_kcal, int sum_score) {
	if (sum_kcal <= l) {
		ans = max(ans, sum_score);
		for (int i = idx+1; i < n; i++) 
			Back(i, sum_kcal + list[i].second, sum_score + list[i].first);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> l;
		list.assign(n, pair<int, int> ());
		for (int i = 0; i < n; i++) {
			int score, kcal;
			cin >> score >> kcal;

			list[i] = { score, kcal };
		}

		ans = 0;
		Back(-1, 0, 0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}