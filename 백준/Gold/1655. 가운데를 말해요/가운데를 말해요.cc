#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int num;
	while (n--) {
		cin >> num;
		if (pq1.empty() || pq1.top() > num) {
			if (pq1.size() > pq2.size()) {
				pq2.push(pq1.top());
				pq1.pop();
			}
			pq1.push(num);
		}
		else if (pq2.empty() || pq2.top() < num) {
			if (pq1.size() <= pq2.size()) {
				pq1.push(pq2.top());
				pq2.pop();
			}
			pq2.push(num);
		}
		else if (pq1.top() <= num && num <= pq2.top()) {
			if (pq1.size() <= pq2.size()) 
				pq1.push(num);
			else
				pq2.push(num);
		}
		
		cout << pq1.top() << '\n';
	}
}