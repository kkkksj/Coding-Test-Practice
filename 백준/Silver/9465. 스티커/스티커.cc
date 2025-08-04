#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        vector<vector<int>> sticker (2, vector<int> (n+2));
        for(int j=0; j<2; j++) 
            for(int k=2; k<n+2; k++)
                cin >> sticker[j][k];
        
        for(int j=2; j<=n+1; j++){
			sticker[0][j] += max(sticker[1][j-1],sticker[1][j-2]);
			sticker[1][j] += max(sticker[0][j-1],sticker[0][j-2]);
		}
		
		cout << max(sticker[0][n+1],sticker[1][n+1]) << '\n';
    }
}