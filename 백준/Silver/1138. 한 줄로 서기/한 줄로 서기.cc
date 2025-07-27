#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr (n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    vector<int> ans;
    for(int i=n-1; i>=0; i--)
        ans.insert(ans.begin()+arr[i], i+1);

    for(int tmp : ans)
        cout << tmp << ' ';
}