#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int minusone = 0;
int zero = 0;
int one = 0;

void Recursive(vector<vector<int>> &paper, int r, int c, int n){
    int firstnum = paper[r][c];
    bool find = true;
    for(int i=r; i<r+n; i++){
        for(int j=c; j<c+n; j++)
            if(paper[i][j] != firstnum){
                find = false;
                Recursive(paper, r, c, n/3);
                Recursive(paper, r, c+n/3, n/3);
                Recursive(paper, r, c+(n*2)/3, n/3);
                
                Recursive(paper, r+n/3, c, n/3);
                Recursive(paper, r+n/3, c+n/3, n/3);
                Recursive(paper, r+n/3, c+(n*2)/3, n/3);
                
                Recursive(paper, r+(n*2)/3, c, n/3);
                Recursive(paper, r+(n*2)/3, c+n/3, n/3);
                Recursive(paper, r+(n*2)/3, c+(n*2)/3, n/3);
                break;
            }
        if(find == false)
            break;
    }
    
    if(find){
        if(firstnum == -1)
            minusone++;
        else if(firstnum == 0)
            zero++;
        else
            one++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int>> paper(n, vector<int> (n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> paper[i][j];
    
    Recursive(paper, 0, 0, n);
    cout << minusone << '\n' << zero << '\n' << one << '\n';
}