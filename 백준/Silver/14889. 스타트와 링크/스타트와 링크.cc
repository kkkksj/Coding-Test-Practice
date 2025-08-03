#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int gap = 2000;
void Back(vector<vector<int>> &cap_vec, int cnt, vector<bool> &used, int start){    
    if(cnt == n/2){
        int Aidx = 0;
        int Bidx = 0;
        vector<int> teamA_list (n/2);
        vector<int> teamB_list (n/2);
        for(int i=1; i<n+1; i++){
            if(used[i]){
                teamA_list[Aidx] = i;
                Aidx++;
            }
            else{
                teamB_list[Bidx] = i;
                Bidx++;
            }
        }
        int teamA = 0;
        int teamB = 0;
        for(int i=0; i<n/2-1; i++)
            for(int j=i+1; j<n/2; j++){
                teamA += cap_vec[teamA_list[i]][teamA_list[j]] + cap_vec[teamA_list[j]][teamA_list[i]];
                teamB += cap_vec[teamB_list[i]][teamB_list[j]] + cap_vec[teamB_list[j]][teamB_list[i]]; 
            }
        
        gap = min(gap, abs(teamA-teamB));
    }
    else{
        for(int i=start; i<n+1; i++)
            if(used[i] == false){
                used[i] = true;
                Back(cap_vec, cnt+1, used, i+1);
                used[i] = false;
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    vector<vector<int>> cap_vec(n+1, vector<int> (n+1));
    int all = 0;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++){
            cin >> cap_vec[i][j];
            all += cap_vec[i][j];
        }
    
    vector<bool> used (n+1, false);
    Back(cap_vec, 0, used, 1);

    cout << gap << '\n';
}