#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> list (n);
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        list[i] = {a, b};
    }

    sort(list.begin(), list.end());

    int answer = 0;
    int s = list[0].first;
    int e = list[0].second;
    for(int i=1; i<n; i++){
        if(list[i].first <= e)
            e = max(e, list[i].second);
        else{
            answer += (e-s);
            s = list[i].first;
            e = list[i].second;
        }
    }
    answer += (e-s);

    cout << answer << '\n';
}