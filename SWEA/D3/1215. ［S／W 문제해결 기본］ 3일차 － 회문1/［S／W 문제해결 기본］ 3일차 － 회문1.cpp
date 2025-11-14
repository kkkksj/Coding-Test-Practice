#include<iostream>
#include<vector>

using namespace std;

int n;
vector<string> board;

int IsPal(int si, int sj) {
	int ret = 0;
	int start_j = sj, end_j = sj + n - 1;
	int start_i = si, end_i = si + n - 1;
	bool flag_j = true;
	bool flag_i = true;
	while (start_j <= end_j && start_i <= end_i) {
		if (end_j < 8) {
			if (board[si][start_j] != board[si][end_j])
				flag_j = false;
			else if (flag_j) {
				start_j++;
				end_j--;
			}
		}
		else
			flag_j = false;
		if (end_i < 8) {
			if (board[start_i][sj] != board[end_i][sj])
				flag_i = false;
			else if (flag_i) {
				start_i++;
				end_i--;
			}
		}
		else
			flag_i = false;
		if (flag_j == false && flag_i == false)
			break;
	}
	if (flag_j)
		ret++;
	if (flag_i)
		ret++;

	return ret;
}

int Simul() {
	int ret = 0;
	if (n == 1)
		return 64;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			ret += IsPal(i, j);

	return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;

		board.assign(8, "");
		for (int i = 0; i < 8; i++)
			cin >> board[i];

		int ans = Simul();

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}