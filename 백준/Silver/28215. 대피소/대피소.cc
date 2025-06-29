#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int distance(int x1, int y1, int x2, int y2){
    int ans = 0;
    ans += x1 > x2 ? x1-x2 : x2-x1;
    ans += y1 > y2 ? y1-y2 : y2-y1;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> home (n, vector<int> (2));
    for(int i=0; i<n; i++) 
        cin >> home[i][0] >> home[i][1];
    
    int min_ans = 2000001;
    if(k==1){
        for(int i=0; i<n; i++){
            int max_len = 0;
            for(int j=0; j<n; j++)
                if(i != j)
                    max_len = max(max_len, distance(home[i][0], home[i][1], home[j][0], home[j][1]));
            min_ans = min(min_ans, max_len);
        }
    }

    else if(k==2){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int max_len = 0;
                for(int k=0; k<n; k++)
                    if(i != k && j != k)
                        max_len = max(max_len, min(distance(home[i][0], home[i][1], home[k][0], home[k][1]), distance(home[j][0], home[j][1], home[k][0], home[k][1])));
                min_ans = min(min_ans, max_len);
            }
        }
    }

    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    int max_len = 0;
                    for(int l=0; l<n; l++)
                        if(i != l && j != l && k != l)
                            max_len = max(max_len, min(distance(home[i][0], home[i][1], home[l][0], home[l][1]), min(distance(home[j][0], home[j][1], home[l][0], home[l][1]), distance(home[k][0], home[k][1], home[l][0], home[l][1]))));
                    min_ans = min(min_ans, max_len);
                }
            }
        }
    }

    cout << min_ans << '\n';
}