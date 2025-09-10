#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<long long>> dist(n+1, vector<long long> (n+1, INT_MAX));
    for(int i=1; i<n+1; i++)  
        for(int j=1; j<n+1; j++)
            if(i==j)
                dist[i][j] = 0;

    int m;
    cin >> m;

    for(int i=0; i<m; i++){
        int a, b;
        long long w;
        cin >> a >> b >> w;

        dist[a][b] = min(w, dist[a][b]);
    }

    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            for(int k=1; k<n+1; k++){
                if(dist[j][i] + dist[i][k] < dist[j][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(dist[i][j] == INT_MAX)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';    
    }
}