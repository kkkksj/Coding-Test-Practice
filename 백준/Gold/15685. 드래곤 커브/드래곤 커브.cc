#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

vector<vector<bool>> grid(101, vector<bool>(101, false));
vector<int> i_list = { 0, -1, 0, 1 };
vector<int> j_list = { 1, 0, -1, 0 };
vector<pair<int, int>> arr;

void Rot() {
	int n = arr.size();
	int a = arr[n - 1].first;
	int b = arr[n - 1].second;

	for (int i = n-2; i >= 0; i--) {
		int y = arr[i].first;
		int x = arr[i].second;

		int y_prime = a - b + x;
		int x_prime = b + a - y;
		if (y_prime < 0 || y_prime > 100 || x_prime < 0 || x_prime > 100)
			continue;
		arr.push_back({ y_prime, x_prime });
	}
}

int main()
{
	int n;
	cin >> n;

	int x, y, d, g;
	while (n--) {
		arr = vector<pair<int, int>>();
		cin >> x >> y >> d >> g;
		arr.push_back({ y, x });
		arr.push_back({ y + i_list[d], x + j_list[d] });
		for (int i = 0; i < g; i++)
			Rot();
		for (int i = 0; i < arr.size(); i++) {
			int y = arr[i].first;
			int x = arr[i].second;
			grid[y][x] = true;
		}
	}
	int ans = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (grid[y][x] &&
				grid[y + 1][x] &&
				grid[y][x + 1] &&
				grid[y + 1][x + 1])
				ans++;
		}
	}

	cout << ans << '\n';
}