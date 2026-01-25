#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	if (k >= n)
		cout << 0 << '\n';
	else {
		int ans = 0;
		while (true) {
			int cnt = 0;
			int tmp = n;
			while (tmp > 0) {
				if (tmp % 2 != 0)
					cnt++;
				tmp /= 2;
			}

			if (k >= cnt)
				break;

			n++;
			ans++;
		}
		cout << ans << '\n';
	}

}