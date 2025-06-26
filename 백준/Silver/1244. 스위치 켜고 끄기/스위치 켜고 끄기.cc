#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void BOY(vector<int> &lights, int num, int n){
    for(int i=num; i<n+1; i+=num)
        lights[i] = 1-lights[i];
}

void GIRL(vector<int> &lights, int num, int n){
    lights[num] = 1 - lights[num];
    for(int i=1; i<n+1; i++){
        if((num-i < 1) || (num+i > n))
            break;
        if(lights[num-i] == lights[num+i]){
            lights[num-i] = 1 -lights[num-i];
            lights[num+i] = 1 - lights[num+i];
        }
        else
            break;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> lights (n+1);
    for(int i=1; i<n+1; i++)
        cin >> lights[i];
    
    int m;
    cin >> m;

    int gorb, num;
    for(int i=0; i<m; i++){
        cin >> gorb >> num;
        if(gorb == 1)
            BOY(lights, num, n);
        else
            GIRL(lights, num, n);
    }

    for(int i=1; i<n+1; i++){
        cout << lights[i] << ' ';
        if(i%20 == 0)
            cout << '\n';
    }
}