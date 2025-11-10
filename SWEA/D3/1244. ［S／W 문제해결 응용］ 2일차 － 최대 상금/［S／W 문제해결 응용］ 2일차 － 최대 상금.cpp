#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

int n;            
int ans;         
vector<unordered_set<string>> seen;

void DFS(string num, int cnt) {
    if (cnt == n) {
        ans = max(ans, stoi(num));
        return;
    }

    if (seen[cnt].count(num)) return;  
    seen[cnt].insert(num);

    int sz = (int)num.size();
    for (int i = 0; i < sz - 1; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            swap(num[i], num[j]);
            DFS(num, cnt + 1);
            swap(num[i], num[j]);      
        }
    }
    return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<int> d_list = { -2, -1, 1, 2 };
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string num;

		cin >> num >> n;

        ans = 0;                               
        seen.assign(n+1, unordered_set<string>{}); 

		DFS(num, 0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}