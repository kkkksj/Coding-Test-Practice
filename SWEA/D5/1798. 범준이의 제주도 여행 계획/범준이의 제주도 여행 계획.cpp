#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 35
#define MAXDAY 5
#define DAYTIME 540

using namespace std;

struct PLACE {
	char type;
	int time;
	int score;
};

int n, m;
int airport;
int movetime[MAXN][MAXN];

PLACE place[MAXN];

bool visited[MAXN];

vector<int> hotels;
vector<int> path;
vector<int> answerpath;

int bestscore;
int totalscore;

bool CanFinish(int day, int cur, int usedtime) {
	if (day == m)
		return usedtime + movetime[cur][airport] <= DAYTIME;

	for(int hotel : hotels) {
		if (usedtime + movetime[cur][hotel] <= DAYTIME)
			return true;
	}

	return false;
}

void UpdateAnswer(int score) {
	if (score <= bestscore)
		return;

	bestscore = score;
	answerpath = path;
}

void Dfs(int day, int cur, int usedtime, int score, int remainscore) {
	if (score + remainscore <= bestscore)
		return;

	for(int next=0; next<n; next++) {
		if (place[next].type != 'P')
			continue;

		if (visited[next])
			continue;

		int nexttime = usedtime + movetime[cur][next] + place[next].time;

		if (nexttime > DAYTIME)
			continue;

		if (!CanFinish(day, next, nexttime))
			continue;

		visited[next] = true;
		path.push_back(next);

		Dfs(day, next, nexttime, score + place[next].score, remainscore - place[next].score);

		path.pop_back();
		visited[next] = false;
	}

	if (day == m) {
		int nexttime = usedtime + movetime[cur][airport];

		if (nexttime > DAYTIME)
			return;

		path.push_back(airport);
		UpdateAnswer(score);
		path.pop_back();

		return;
	}

	for(int hotel : hotels) {
		int nexttime = usedtime + movetime[cur][hotel];

		if (nexttime > DAYTIME)
			continue;

		path.push_back(hotel);

		Dfs(day + 1, hotel, 0, score, remainscore);

		path.pop_back();
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		cin >> n >> m;

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++)
				movetime[i][j] = 0;
		}

		for(int i=0; i<n-1; i++) {
			for(int j=i+1; j<n; j++) {
				int time;
				cin >> time;

				movetime[i][j] = time;
				movetime[j][i] = time;
			}
		}

		hotels.clear();
		totalscore = 0;

		for(int i=0; i<n; i++) {
			char type;
			cin >> type;

			place[i] = { type, 0, 0 };

			if (type == 'A') {
				airport = i;
			}
			else if (type == 'H') {
				hotels.push_back(i);
			}
			else {
				cin >> place[i].time >> place[i].score;
				totalscore += place[i].score;
			}

			visited[i] = false;
		}

		bestscore = -1;

		path.clear();
		answerpath.clear();

		Dfs(1, airport, 0, 0, totalscore);

		cout << "#" << test_case << " ";

		if (bestscore <= 0) {
			cout << "0\n";
			continue;
		}

		cout << bestscore;

		for(int node : answerpath)
			cout << " " << node + 1;

		cout << '\n';
	}

	return 0;
}