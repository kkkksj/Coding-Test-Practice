#include<iostream>
#include<vector>

using namespace std;

int n;
vector<string> board;
vector<int> i_list = { 0, 1, 1, 1 };
vector<int> j_list = { 1, 0, 1, -1 };

bool Check(int i, int j) {
	for (int d = 0; d < 4; d++) {
		int cnt = 0;
		int now_i = i, now_j = j;
		for (int c = 0; c < n; c++) {
			if (now_i < 0 || now_i >= n || now_j < 0 || now_j >= n)
				break;

			if (board[now_i][now_j] == 'o')
				cnt++;
			else
				cnt = 0;
			if (cnt >= 5)
				return true;

			now_i += i_list[d];
			now_j += j_list[d];
		}
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<string> arr;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		board.assign(n, "");
		
		for (int i = 0; i < n; i++)
			cin >> board[i];

		bool flag = false;
		for(int i=0; i<n; i++) {
			for (int j = 0; j < n; j++) {
				flag = Check(i, j);
				if (flag)	break;
			}
			if (flag)	break;
		}

		if (flag)
			cout << '#' << test_case << ' ' << "YES" << '\n';
		else
			cout << '#' << test_case << ' ' << "NO" << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}