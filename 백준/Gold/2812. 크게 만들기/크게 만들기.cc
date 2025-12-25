#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {
	int n, k, sz;
	cin >> n >> k;
	sz = n - k;

	string num;
	cin >> num;

	deque<char> dq;
	for(char c : num) {
		if (dq.empty() || dq.back() >= c)
			dq.push_back(c);
		else {
			while (k > 0 && !dq.empty()) {
				if (dq.back() < c) {
					dq.pop_back();
					k--;
				}
				else
					break;
			}
			dq.push_back(c);
		}
	}
	
	for (int i = 0; i < sz; i++) {
		cout << dq.front();
		dq.pop_front();
	}
	cout << '\n';
}