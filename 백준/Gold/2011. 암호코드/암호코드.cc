#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string str;
	cin >> str;

	vector<int> dp((int)str.size()+1, 0);
	if(str[0] == '0'){
		cout << 0 << '\n';
		return 0;
	}

	dp[0] = dp[1] = 1;
	for(int i=2; i<(int)str.size()+1; i++){
		if(str[i-1] != '0')
			dp[i] = dp[i-1] % 1000000;
		int tmp = (str[i-2]-'0')*10 + (str[i-1]-'0');
		if(tmp >=10 && tmp<=26)
			dp[i] = (dp[i] + dp[i-2]) % 1000000;
	}

	cout << dp[(int)str.size()];
}