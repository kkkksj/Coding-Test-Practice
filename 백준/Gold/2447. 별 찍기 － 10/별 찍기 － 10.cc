#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 비어있는 칸을 점화식으로 표현
// n == 9일 때 빈 칸은 (3,3) (3,4) (3,5) (4,3) (4,4) (4,5) (5,3) (5,4) (5,5)
// (i / 3) % 3 == 1 && (j / 3 ) % 3 == 1 이면 빈 칸

void Print(int i, int j, int n){
    if((i/n)%3 == 1 && (j/n)%3 == 1)
        cout << ' ';
    else{
        if(n/3 == 0)
            cout << '*';
        else
            Print(i, j, n/3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            Print(i, j, n);
        cout << '\n';
    }
}