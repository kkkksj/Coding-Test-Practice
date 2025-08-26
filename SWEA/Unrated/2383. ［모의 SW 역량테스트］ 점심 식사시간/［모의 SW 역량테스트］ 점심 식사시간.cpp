#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<limits.h>

using namespace std;

int stair_h1, stair_h2; 

int STAIR1(vector<int> &dist_list, int n){
    if(n==0)
        return 0;
    sort(dist_list.begin(), dist_list.end());

    vector<int> dp(n, 0);
    for(int i=0; i<n; i++){
        if(i < 3)
            dp[i] = dist_list[i] + stair_h1 + 1;
        else{
            if(dist_list[i] < dp[i-3])
                dp[i] = dp[i-3] + stair_h1;
            else
                dp[i] = dist_list[i] + stair_h1 + 1;
        }
    }

    return dp[n-1];
}

int STAIR2(vector<int> &dist_list, int n){
    if(n==0)
        return 0;
    sort(dist_list.begin(), dist_list.end());
    vector<int> dp(n, 0);
    for(int i=0; i<n; i++){
        if(i < 3)
            dp[i] = dist_list[i] + stair_h2 + 1;
        else{
            if(dist_list[i] < dp[i-3])
                dp[i] = dp[i-3] + stair_h2;
            else
                dp[i] = dist_list[i] + stair_h2 + 1;
        }
    }

    return dp[n-1];
}

bool CMP(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;

        vector<pair<int, int>> people;
        vector<pair<int, int>> stairs;
        stair_h1 = 0;   stair_h2 = 0;
        int people_num = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                int num;
                cin >> num;

                if(num == 0)
                    continue;
                if(num == 1){
                    people.push_back({i, j});
                    people_num++;                    
                }
                else{
                    stairs.push_back({i, j});
                    if(stair_h1 == 0)
                        stair_h1 = num;
                    else
                        stair_h2 = num;
                }
            }
        vector<pair<int, int>> dist1(people_num, pair<int, int> ());
        vector<int> dist2(people_num);
        for(int i=0; i<people_num; i++){
            dist1[i] = {i, (abs(people[i].first-stairs[0].first) + abs(people[i].second-stairs[0].second))};
            dist2[i] = (abs(people[i].first-stairs[1].first) + abs(people[i].second-stairs[1].second));
        }

        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << people_num); mask++) {
            vector<int> go_1_dist;
            vector<int> go_2_dist;
            for (int p = 0; p < people_num; ++p) {
                if (mask & (1 << p))
                    go_1_dist.push_back(dist1[p].second);
                else                
                    go_2_dist.push_back(dist2[p]);
            }

            int one = STAIR1(go_1_dist, (int)go_1_dist.size());
            int two = STAIR2(go_2_dist, (int)go_2_dist.size());
            ans = min(ans, max(one, two));
        }

        cout << '#' << test_case << ' ' << ans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}