#include <iostream>
#include <cmath>
#define SIZE 100000000

using namespace std;
#define SIZE 100000000

bool isPrime(int x){
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int d = 3; 1LL*d*d <= x; d += 2)
        if (x % d == 0) return false;
    return true;
}

void dfs(int cur, int len, int N){
    if (!isPrime(cur)) return;           
    if (len == N) {                    
        cout << cur << '\n';
        return;
    }
    for (int d = 1; d <= 9; d += 2)      
        dfs(cur*10 + d, len+1, N);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    int starters[4] = {2,3,5,7};        
    for (int s : starters) dfs(s, 1, N);
}