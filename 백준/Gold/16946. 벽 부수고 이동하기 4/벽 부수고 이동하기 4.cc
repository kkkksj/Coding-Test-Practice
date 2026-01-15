#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct Pos {
	int x, y;
};

int N, M;
int Map[1001][1001];
bool visited[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int startx, int starty) {
	queue<Pos>q;
	vector<Pos>wall;
	q.push({ startx,starty });
	visited[startx][starty] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (Map[nx][ny] == 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
			else if (Map[nx][ny] != 0 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				wall.push_back({ nx,ny });
			}
		}
	}
	for (int i = 0; i < wall.size(); i++) {
		Map[wall[i].x][wall[i].y] += cnt;
		visited[wall[i].x][wall[i].y] = false;
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			Map[i][j] = c - '0';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0 && visited[i][j] == false)
				bfs(i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << Map[i][j] % 10;
		}
		cout << '\n';
	}
}