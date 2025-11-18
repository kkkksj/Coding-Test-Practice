#include<iostream>
#include<vector>

using namespace std;

vector<string> arr;

bool IsPalRow(int len, int r, int idx) {
	int i = idx, j = idx + len - 1;
	while (i < j) {
		if (arr[r][i] != arr[r][j])
			return false;
		i++;	j--;
	}
	return true;
}

bool IsPalCol(int len, int c, int idx) {
	int i = idx, j = idx + len - 1;
	while (i < j) {
		if (arr[i][c] != arr[j][c])
			return false;
		i++;	j--;
	}
	return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tc;
		cin >> tc;

		arr.assign(100, "");
		string input;
		for (int i = 0; i < 100; i++)
			cin >> arr[i];

		int ans = 1;
		for (int len = 100; len > 0; len--) {
			bool flag = false;
			// 가로 검사
			for(int r=0; r<100 && !flag; r++)
				for (int s = 0; s <= 100 - len; s++) {
					if (IsPalRow(len, r, s)) {
						ans = len;
						flag = true;
						break;
					}
				}
			// 세로 검사
			for (int c = 0; c < 100 && !flag; c++)
				for (int s = 0; s <= 100 - len; s++) {
					if (IsPalCol(len, c, s)) {
						ans = len;
						flag = true;
						break;
					}
				}
			if (flag)
				break;
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}