#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 1000000

int Search(vector<int> &p, int n){
    int ret = 0;
    int left = 0;
    int right = (int)p.size()-1;

    while(left <= right){
        if(p[left] + p[right] == n){
            ret++;
            left++;
            right--;
        }
        else if(p[left] + p[right] < n)
            left++;
        else
            right--;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    vector<bool> isprime(MAX, true);
    isprime[0] = false;
    isprime[1] = false;
    // 에라토스테네스의 체
    for(int i=2;i<=sqrt(MAX);i++)
        if(isprime[i]==true)
            for(int j=i*i;j<=MAX;j+=i)
                isprime[j]=false;
    
    vector<int> p;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        p.clear();
        for(int j=2; j<n+1; j++)
            if(isprime[j])
                p.push_back(j);
        
        cout << Search(p, n) << '\n';
    }
}