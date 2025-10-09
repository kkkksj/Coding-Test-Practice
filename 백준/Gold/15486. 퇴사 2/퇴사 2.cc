#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;

	vector<int> dp (n+1, 0);
	int max_cost = 0;
	int ans = 0;
	for(int i=0; i<n; i++){
		int time, cost;
		cin >> time >> cost;
		max_cost = max(max_cost, dp[i]);
		if(i+time <= n){
			dp[i+time] = max(dp[i+time], max_cost+cost);
			ans = max(dp[i+time], ans);
		}
	}

	cout << ans << '\n';
}