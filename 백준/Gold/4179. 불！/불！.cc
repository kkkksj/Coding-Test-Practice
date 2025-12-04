#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Info {
	int i, j;
	int time;
};

int r, c;
vector<string> maze;
queue<Info> fire_q;
queue<Info> pos_q;
vector<vector<bool>> visited;
vector<int> i_list = { 0, 0, -1, 1 };
vector<int> j_list = { -1, 1, 0, 0 };

void Fire(int time) {
	if (!pos_q.empty() && pos_q.front().time != time) {
		while (!fire_q.empty()) {	// 불 확산
			int fire_i = fire_q.front().i;
			int fire_j = fire_q.front().j;
			int t = fire_q.front().time;
			if (t != time)
				break;
			fire_q.pop();

			for (int d = 0; d < 4; d++) {
				int next_fire_i = fire_i + i_list[d];
				int next_fire_j = fire_j + j_list[d];

				if (next_fire_i < 0 || next_fire_i >= r || next_fire_j < 0 || next_fire_j >= c)
					continue;
				if (maze[next_fire_i][next_fire_j] != 'F' && maze[next_fire_i][next_fire_j] != '#') {
					maze[next_fire_i][next_fire_j] = 'F';
					fire_q.push({ next_fire_i, next_fire_j, t + 1 });
				}
			}
		}
	}
}

int BFS() {
	while (!pos_q.empty()) {
		int now_i = pos_q.front().i;
		int now_j = pos_q.front().j;
		int time = pos_q.front().time;
		pos_q.pop();

		if (maze[now_i][now_j] == 'F')
		{
			Fire(time);
			continue;
		}

		if (now_i == 0 || now_i == r-1 || now_j == 0 || now_j == c-1)
			return time;
		
		for (int d = 0; d < 4; d++) {	// 지훈 움직이기
			int next_i = now_i + i_list[d];
			int next_j = now_j + j_list[d];
			
			if (visited[next_i][next_j] || maze[next_i][next_j] == '#' || maze[next_i][next_j] == 'F')
				continue;

			visited[next_i][next_j] = true;
			pos_q.push({ next_i, next_j, time + 1 });
		}
		
		Fire(time);
	}
	return -1;
}

int main()
{
	cin >> r >> c;
	maze.assign(r, "");
	visited.assign(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++) {
		cin >> maze[i];
		for(int j = 0; j < c; j++){
			if (maze[i][j] == 'J') {
				pos_q.push({ i, j, 0 });
				visited[i][j] = true;
			}
			else if (maze[i][j] == 'F')
				fire_q.push({ i, j, 0 });
		}
	}

	int ans = BFS();
	if (ans == -1)
		cout << "IMPOSSIBLE" << '\n';
	else
		cout << ans + 1 << '\n';
}