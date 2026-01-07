#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;

struct Info {
	int kg, price;
};

bool CMP(Info a, Info b) {
	if (a.kg != b.kg)
		return a.kg < b.kg;
	return a.price < b.price;
}

vector<Info> stone;
vector<int> bags;

int main(int argc, char** argv)
{
	cin >> n >> k;
	stone.assign(n, { 0, 0 });
	bags.assign(k, 0);

	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		stone[i] = { m, v };
	}
	for (int i = 0; i < k; i++)
		cin >> bags[i];

	sort(stone.begin(), stone.end(), CMP);
	sort(bags.begin(), bags.end());

	int idx = 0;
	long long ans = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; i++) {
		while (idx < n && stone[idx].kg <= bags[i]) {
			pq.push(stone[idx].price);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans << '\n';
}