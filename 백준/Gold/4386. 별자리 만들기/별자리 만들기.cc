#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<unordered_set>

using namespace std;

int n;
vector<pair<double, double>> arr;

double CalDist(double x1, double y1, double x2, double y2) {
	return round(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))*100) / 100;
}

double Prim() {
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	pq.push({ 0, 0 });
	unordered_set<int> visited;
	double ans = 0;

	while (!pq.empty() && visited.size() < n) {
		double dist = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (visited.find(node) != visited.end())
			continue;

		visited.insert(node);
		ans += dist;

		for (int next = 0; next < n; next++) {
			if (visited.find(next) != visited.end())
				continue;
			double d = CalDist(arr[node].first, arr[node].second, arr[next].first, arr[next].second);
			pq.push({ d, next });
		}
	}

	return ans;
}

int main() {
	cin >> n;
	arr.assign(n, {});

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	double ans = Prim();

	cout << ans << '\n';
}