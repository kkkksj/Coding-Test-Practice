#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)	{
        vector<int> cost(4);
        for(int i=0; i<4; i++)
            cin >> cost[i];
        vector<int> using_day(12);
        for(int i=0; i<12; i++)
            cin >> using_day[i];

        vector<int> base(12);
        for(int i=0; i<12; i++)
            base[i] = min(using_day[i]*cost[0], cost[1]);

        vector<int> dp(13, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<13; i++){
            dp[i] = min(dp[i], dp[i-1]+base[i-1]);
            int j=min(12, i+2);
            dp[j] = min(dp[j], dp[i-1] + cost[2]);
        }
            
        int ans = min(dp[12], cost[3]);
        cout << '#' << test_case << ' ' << ans << '\n';    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}