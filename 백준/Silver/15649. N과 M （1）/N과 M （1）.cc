#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void Combi(int n, int m, vector<int> &arr){
    if((int)arr.size() == m){
        for(int tmp : arr)
            cout << tmp << ' ';
        cout << '\n';
    }
    else{
        for(int i=1; i<n+1; i++){
            if(find(arr.begin(), arr.end(), i) == arr.end()){
                arr.push_back(i);
                Combi(n, m, arr);
                arr.pop_back();
            } 
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> arr; 
    Combi(n, m, arr);
}