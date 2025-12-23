#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int n, m, d;
vector<vector<int>> origin_grid;
vector<vector<int>> grid;
vector<int> pick;
int ans = 0;

struct Info {
	int dist;
	int i, j;
};

bool cmp(Info a, Info b) {
	if (a.dist == b.dist) return a.j < b.j;
	else return a.dist < b.dist;
}

int Dist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

int Attack() {
	int row = n;
	int ret = 0;
	while (row>=1) {
		vector<pair<int, int>> attacked;
		for (int col : pick) {
			vector<Info> arr;
			for(int i=0; i<row; i++)
				for (int j = 0; j < m; j++) {
					int dist = Dist(row, col, i, j);
					if (grid[i][j] == 0 || dist > d)
						continue;
					arr.push_back({ dist, i, j});	// j, i순으로 되어있다.
				}
			if (arr.empty())
				continue;
			sort(arr.begin(), arr.end(), cmp);
			attacked.push_back({ arr[0].i, arr[0].j });
		}
		for (int i = 0; i < attacked.size(); i++) 
			if (grid[attacked[i].first][attacked[i].second] == 1) {
				grid[attacked[i].first][attacked[i].second] = 0;
				ret++;
		}
		row--;
	}
	return ret;
}

void Copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			grid[i][j] = origin_grid[i][j];
}

void Combi(int s) {
	if (pick.size() == 3) {
		Copy();
		ans = max(ans, Attack());
	}
	for (int i = s; i < m; i++) {
		pick.push_back(i);
		Combi(i+1);
		pick.pop_back();
	}
}

int main() {
	cin >> n >> m >> d;
	origin_grid.assign(n, vector<int>(m, 0));
	grid.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> origin_grid[i][j];

	Combi(0);

	cout << ans << '\n';
}