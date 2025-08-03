#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr (n, vector<int> (n, 0));
    vector<vector<int>> arr_sum (n+1, vector<int> (n+1, 0));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            arr_sum[i][j] = arr[i-1][j-1] + arr_sum[i-1][j] + arr_sum[i][j-1] - arr_sum[i-1][j-1];

    int x1, y1, x2, y2;
    for(int i=0; i<m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = arr_sum[x2][y2] - arr_sum[x1-1][y2] - arr_sum[x2][y1-1] + arr_sum[x1-1][y1-1];
        cout << ans << '\n';
    }
}