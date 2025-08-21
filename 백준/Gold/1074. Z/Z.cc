#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, r, c;
int cnt = 0;

void Find(int i, int j, int sz){
    if(r==i && c==j){
        cout << cnt << '\n';
        return;
    }
    else if (r<i+sz && c<j+sz && r>=i && c>=j){
        Find(i, j, sz / 2);
        Find(i, j + sz / 2, sz / 2);
        Find(i + sz / 2, j, sz / 2);
        Find(i + sz / 2, j + sz / 2, sz / 2);
    }
    else{
        cnt += sz * sz;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> r >> c;

    Find(0, 0, pow(2,n));
}