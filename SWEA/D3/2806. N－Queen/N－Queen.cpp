#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n;
int ans = 0;
vector<bool> visited1;     
vector<bool> visited2;   
vector<bool> visited3;   

void DFS(int r) {
	if (r == n)
		ans++;
	else {
		for (int c = 0; c < n; c++) {
			if (visited1[c] || visited2[r + c] || visited3[r - c + (n - 1)])
				continue;
			
			visited1[c] = true;
			visited2[r + c] = true;
			visited3[r - c + (n - 1)] = true;

			DFS(r+1);

			visited1[c] = false;
			visited2[r + c] = false;
			visited3[r - c + (n - 1)] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		visited1.assign(n, false);
		visited2.assign(n, false);
		visited3.assign(n, false);

		ans = 0;
		DFS(0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}