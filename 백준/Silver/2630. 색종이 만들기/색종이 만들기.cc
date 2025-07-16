#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

void PaperCut(int x, int y, int n, int &white, int &blue, vector<vector<int>> &paper){
    int first_c = paper[x][y];
    bool square = true;
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++)
            if(paper[i][j] != first_c){
                square = false;
                break;
            }
        if(square == false)
            break;
    }

    if(square == false){
        PaperCut(x, y, n/2, white, blue, paper);
        PaperCut(x, y+n/2, n/2, white, blue, paper);
        PaperCut(x+n/2, y, n/2, white, blue, paper);
        PaperCut(x+n/2, y+n/2, n/2, white, blue, paper);
    }
    else{
        if(first_c == 1)
            blue++;
        else
            white++;
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

    int blue = 0;
    int white = 0;
    PaperCut(0, 0, n, white, blue, paper);

    cout << white << '\n' << blue;
}