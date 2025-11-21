#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<int> arr;
int ans = 0;

void Back(int cnt, int sum) {
	if (cnt == n) {
		if (sum == k)
			ans++;
		return;
	}

	Back(cnt + 1, sum);
	Back(cnt + 1, sum + arr[cnt]);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> k;
		arr.assign(n, 0);
		
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		ans = 0;
		Back(0, 0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}