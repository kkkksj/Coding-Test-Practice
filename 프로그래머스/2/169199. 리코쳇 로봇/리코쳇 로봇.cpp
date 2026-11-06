#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int i;
    int j;
    int cnt;
};

int i_list[4] = {-1, 1, 0, 0};
int j_list[4] = {0, 0, -1, 1};

int solution(vector<string> board) {
    int n = board.size();
    int m = board[0].size();

    int si, sj;
    int gi, gj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                si = i;
                sj = j;
            }

            if (board[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    bool visited[100][100] = {false};

    queue<Node> q;
    q.push({si, sj, 0});
    visited[si][sj] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.i == gi && now.j == gj)
            return now.cnt;

        for (int d = 0; d < 4; d++) {
            int ni = now.i;
            int nj = now.j;

            while (1) {
                int next_i = ni + i_list[d];
                int next_j = nj + j_list[d];

                if (next_i < 0 || next_i >= n ||
                    next_j < 0 || next_j >= m)
                    break;

                if (board[next_i][next_j] == 'D')
                    break;

                ni = next_i;
                nj = next_j;
            }

            if (visited[ni][nj])
                continue;

            visited[ni][nj] = true;
            q.push({ni, nj, now.cnt + 1});
        }
    }

    return -1;
}