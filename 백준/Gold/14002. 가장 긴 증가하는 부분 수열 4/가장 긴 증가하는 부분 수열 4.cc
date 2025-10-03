#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n+1);
	for (int i=1; i <n+1; i++)
		cin >> arr[i];
	
    vector<int> tmp, ans;
    vector<int> dp(n+1, 0);
	tmp.push_back(arr[1]);
    int cnt = 0;
	for (int i=2; i <n+1; i++){
		if (tmp[cnt] < arr[i]){
			tmp.push_back(arr[i]);
			cnt++;
			dp[i] = cnt;
		}
		else{
			int pos = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
			tmp[pos] = arr[i];
			dp[i] = pos;
		}
	}

	int tmp_size = cnt;

	for (int i=n; i>-1; i--)
		if (dp[i] == tmp_size){
			ans.push_back(arr[i]);
			tmp_size--;
		}

	int size = ans.size();
	cout << size << '\n';
	for (int i=0; i<size; i++){
		cout << ans.back() << " ";
		ans.pop_back();
	}
}