#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

int FindNum(vector<int> &num_vec, int num, int n){
    int s=0;
    int e=n-1;
    int ans = 0;
    while(s<e){
        int sum = num_vec[s] + num_vec[e];
        if(sum == num){
            ans++;
            e -= 1;
            s += 1;
        }
        else if(sum > num)
            e -= 1;
        else
            s += 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> num_vec(n);
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        num_vec[i] = tmp;
    }
    sort(num_vec.begin(), num_vec.end());

    int num;
    cin >> num;
    
    cout << FindNum(num_vec, num, n) << '\n';
}