#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (auto result : results) {
        int winner = result[0];
        int loser = result[1];

        graph[winner][loser] = 1;
    }

    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                if (graph[i][k] && graph[k][j]) 
                    graph[i][j] = 1;
               
    for (int i = 1; i <= n; i++) {
        int count = 0;

        for (int j = 1; j <= n; j++) 
            if (graph[i][j] || graph[j][i]) 
                count++;

        if (count == n - 1) 
            answer++;
    }

    return answer;
}