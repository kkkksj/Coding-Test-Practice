#include <iostream>
#include <algorithm>

using namespace std;

int n;
int parr[50];
int narr[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int pcnt = 0;
	int ncnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num <= 0) 
			narr[ncnt++] = num;
		else
			parr[pcnt++] = num;
	}

	sort(parr, parr + pcnt);
	sort(narr, narr + ncnt);
	int idx = pcnt - 1;
	int ans = 0;
	while (idx >= 0) {
		if (idx>0 && (parr[idx] * parr[idx - 1] > parr[idx] + parr[idx - 1])) {
			ans += (parr[idx] * parr[idx - 1]);
			idx -= 2;
		}
		else {
			ans += parr[idx];
			idx--;
		}
	}
	idx = 0;
	while (idx < ncnt) {
		if (idx<ncnt-1 && (narr[idx] * narr[idx + 1] > narr[idx] + narr[idx + 1])) {
			ans += (narr[idx] * narr[idx + 1]);
			idx += 2;
		}
		else {
			ans += narr[idx];
			idx++;
		}
	}
	cout << ans << '\n';
}