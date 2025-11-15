#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n;
vector<vector<int>> board;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;

		board.assign(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		
		bool flag = false;
		int ans = 0;
		for (int c = 0; c < n; c++) {
			flag = false;
			for (int r = 0; r < n; r++) {
				if (board[r][c] == 1)
					flag = true;
				else if(board[r][c] == 2) {
					if (flag) 
						ans++;
						flag = false;
				}
			}
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}