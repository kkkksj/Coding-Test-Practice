#include<iostream>
#include<vector>

using namespace std;

int n, m, h;
vector<vector<bool>> arr;
int ans = 0;
bool flag = false;

void DFS(int num, int cnt) {
	if (ans == cnt) {
		bool isright = true;
		for (int i = 1; i < n + 1; i++) {
			int dest = i;
			for (int j = 1; j < h + 1; j++) {
				if (arr[j][dest])
					dest++;
				else if (dest > 1 && arr[j][dest - 1])
					dest--;
			}
			if (dest != i) {
				isright = false;
				break;
			}
		}
		if (isright)
			flag = true;
		return;
	}

	for (int i = num; i < h + 1; i++) 
		for (int j = 1; j < n; j++) {
			if (!arr[i][j - 1] && !arr[i][j] && !arr[i][j + 1]) {
				arr[i][j] = true;
				DFS(i, cnt + 1);
				arr[i][j] = false;
			}
		}

	return;
}

int main()
{
	cin >> n >> m >> h;
	arr.assign(h + 1, vector<bool>(n + 1, false));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a][b] = true;
	}

	for (ans = 0; ans < 4; ans++) {
		DFS(1, 0);
		if (flag) {
			cout << ans << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
}