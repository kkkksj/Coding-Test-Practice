#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

void CountCase(int cnt, int result, int &ans, int n, int s, vector<int> &arr){
    if(cnt == n){
        if(result == s)
            ans++;
    }
    else{
        CountCase(cnt+1, result, ans, n, s, arr);   // 다음 수를 더하지 않고 넘어감
        CountCase(cnt+1, result+arr[cnt], ans, n, s, arr);  // 다음 수를 더함
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int ans = 0;
    CountCase(0, 0, ans, n, s, arr);

    if(s==0)
        ans--;  // 목표 값이 0일 경우 공집합이 체크된 것은 제외해야 함

    cout << ans << '\n';
}