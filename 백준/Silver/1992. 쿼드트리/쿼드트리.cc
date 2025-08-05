#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void Recursive(vector<string> &pixels, int si, int sj, int l){
    char zeroone = pixels[si][sj];
    bool flag = true;
    for(int i=si; i<si+l; i++){
        for(int j=sj; j<sj+l; j++){
            if(pixels[i][j] != zeroone){
                flag = false;
                break;
            }
        }
        if(flag == false)
            break;
    }
    if(flag)
        cout << zeroone;
    else{
        cout << '(';
        Recursive(pixels, si, sj, l/2);
        Recursive(pixels, si, sj+l/2, l/2);
        Recursive(pixels, si+l/2, sj, l/2);
        Recursive(pixels, si+l/2, sj+l/2, l/2);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> pixels (n);
    for(int i=0; i<n; i++)
        cin >> pixels[i];

    Recursive(pixels, 0, 0, n);
}