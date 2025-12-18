#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


int n, m, k;
map<pair<int, int>, vector<int>> info;	// 나무 정보
vector<vector<int>> nour;
vector<vector<int>> add_nour;
vector<int> i_list = { -1, -1, -1, 0, 0, 1, 1, 1 };
vector<int> j_list = { -1, 0, 1, -1, 1, -1, 0, 1 };

void SpringSummer() {
	for (auto& [pos, age] : info) {
		vector<int> tmp;
		sort(age.begin(), age.end());
		int i = pos.first, j = pos.second;
		int dead = 0;
		for (int t = 0; t<age.size(); t++) {
			int tree = age[t];
			if (nour[i][j] < tree) 
				dead += tree / 2;
			else {
				tmp.push_back(tree+1);
				nour[i][j] -= tree;
			}
		}
		info[{i, j}] = tmp;
		nour[i][j] += dead;	// summer
	}
}

void Fall() {
	for (auto& [pos, age] : info) {
		int i = pos.first, j = pos.second;
		for (int tree : age) {
			if (tree % 5 == 0) 
				for (int d = 0; d < 8; d++) {
					int next_i = i + i_list[d];
					int next_j = j + j_list[d];
					if (next_i < 1 || next_i >= n+1 || next_j < 1 || next_j >= n+1)
						continue;
					info[{next_i, next_j}].push_back(1);
				}
		}
	}
}

void Winter() {
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			nour[i][j] += add_nour[i][j];
}

int main() {
	cin >> n >> m >> k;
	nour.assign(n + 1, vector<int>(n + 1, 5));
	add_nour.assign(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> add_nour[i][j];

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		info[{x, y}].push_back(z);
	}

	while (k--) {
		SpringSummer();
		Fall();
		Winter();
	}

	int ans = 0;
	for (auto& [pos, age] : info)
		ans += age.size();

	cout << ans << '\n';
}