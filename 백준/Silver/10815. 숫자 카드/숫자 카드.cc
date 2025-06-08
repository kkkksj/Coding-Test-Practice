#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> pos_num_card(10000001, 0);
    vector<long long> neg_num_card(10000001, 0);
    long long n, m;

    cin >> n;
    long long num;
    for(long long i=0; i<n; i++){
        cin >> num;
        if(num>=0)
            pos_num_card[num] = 1;
        else
            neg_num_card[-num] = 1;
    }

    cin >> m;
    for(long long i=0; i<m; i++){
        cin >> num;
        if(num>=0){ 
            if(pos_num_card[num])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        else{
            if(neg_num_card[-num])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
    }
}