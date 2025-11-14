#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>

using namespace std;

int n;
vector<int> x_list;
vector<int> y_list;
double e;
vector<bool> visited;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		x_list.assign(n, 0);
		y_list.assign(n, 0);
		visited.assign(n, false);

		for (int i = 0; i < n; i++)
			cin >> x_list[i];
		for (int i = 0; i < n; i++)
			cin >> y_list[i];

		cin >> e;

		vector<long long> mindist(n, LLONG_MAX);

		mindist[0] = 0;
		long double ttl = 0;
		for (int i = 0; i < n; i++) {
			int node = -1;
			long long best = LLONG_MAX;
			for(int j = 0; j < n; j++)
				if (visited[j] == false && mindist[j] < best) {
					best = mindist[j];
					node = j;
				}
			visited[node] = true;
			ttl += best;

			for (int j = 0; j < n; j++) {
				if (visited[j])
					continue;
				long long dx = x_list[node] - x_list[j];
				long long dy = y_list[node] - y_list[j];
				long long d = dx*dx + dy*dy;

				if (d < mindist[j])
					mindist[j] = d;
			}
		}

		long long ans = round(ttl * e);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}