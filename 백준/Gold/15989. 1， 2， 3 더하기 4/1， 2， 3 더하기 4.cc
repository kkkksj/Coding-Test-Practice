#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
   
    int n;
    cin >> n;

    vector<int> dp(10001, 1);
    
    for(int i=2; i<10001; i++)
        dp[i] += dp[i-2];

    for(int i=3; i<10001; i++)
        dp[i] += dp[i-3];

    int num;
    while(n--){
        cin >> num;
        cout << dp[num] << '\n';
    }
}