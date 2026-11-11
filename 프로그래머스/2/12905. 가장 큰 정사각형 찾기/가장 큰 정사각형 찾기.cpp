#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int n = board.size();
    int m = board[0].size();

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (board[i][j] == 0)
                continue;

            if (i == 0 || j == 0) {
                max_len = max(max_len, board[i][j]);
                continue;
            }

            board[i][j] = min({board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]}) + 1;

            max_len = max(max_len, board[i][j]);
        }
    }

    return max_len * max_len;
}