#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 200000

int n;
vector<int> arr[MAX + 1];

int Search() {
	int ret = 0;
	priority_queue<int> pq;

	for (int i = n; i > 0; i--) {
		for (int a : arr[i])
			pq.push(a);
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int deadline, cup;
		cin >> deadline >> cup;

		arr[deadline].push_back(cup);
	}

	cout << Search() << '\n';

}