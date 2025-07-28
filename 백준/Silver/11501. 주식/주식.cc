#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        vector<int> cost(n);
        for(int j=0; j<n; j++)
            cin >> cost[j];
        long long pro = 0;
        long long buy = 0;
        long long num = 0;
        int max_num = cost[n-1];
        for(int j=n-2; j>=0; j--){
            if(cost[j] < max_num){
                buy += cost[j];
                num++;
            }
            else if(cost[j] > max_num){
                pro += (max_num*num - buy);
                max_num = cost[j];
                buy = 0;
                num = 0;
            }
        }

        pro += (max_num*num - buy);

        cout << pro << '\n';
        cost.clear();
    }
}