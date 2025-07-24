#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int n;
int ans = INT_MAX;

void Back(vector<int> &combi, vector<vector<int>> &city){
    if((int)combi.size() == n){
        int sum = 0;
        for(int i=1; i<n; i++){
            if(city[combi[i-1]][combi[i]] == 0)
                return;
            sum += city[combi[i-1]][combi[i]];
        }
        if(city[combi[n-1]][combi[0]] == 0)
            return;
        sum += city[combi[n-1]][combi[0]];
        ans = min(sum , ans);
    }
    else
        for(int i=0; i<n; i++)
            if(find(combi.begin(), combi.end(), i) == combi.end()){
                combi.push_back(i);
                Back(combi, city);
                combi.pop_back();
            }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    vector<vector<int>> city(n, vector<int> (n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> city[i][j];
    
    vector<int> combi;
    Back(combi, city);

    cout << ans << '\n';
}