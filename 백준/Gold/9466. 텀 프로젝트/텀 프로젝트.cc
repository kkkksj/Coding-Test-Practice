#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> arr;
vector<int> visited;
vector<bool> finished;
int cnt;

void DFS(int i, int start) {
	visited[i] = start;
	int next = arr[i];

	if (visited[next] == 0)
		DFS(next, start);
	else if (visited[next] == start && !finished[next]) {
		int cur = next;
		do {
			cnt++;
			cur = arr[cur];
		} while (cur != next);
	}

	finished[i] = true;
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		cin >> n;
		arr.assign(n + 1, 0);
		visited.assign(n + 1, 0);
		finished.assign(n + 1, false);
		
		for (int i = 1; i < n + 1; i++)
			cin >> arr[i];

		cnt = 0;
		for (int i = 1; i < n + 1; i++) 
			if(visited[i] == 0)
				DFS(i, i);
		
		cout << n - cnt << '\n';
	}
}