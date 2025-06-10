#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;

    int arr[21] = {0,};
    string cmd;
    int input;

    for(int i=0; i<m; i++){
        cin >> cmd;
        if(cmd == "all"){
            for(int j=1; j<21; j++)
                arr[j] = 1;
        }
        else if(cmd == "empty"){
            for(int j=1; j<21; j++)
                arr[j] = 0;
        }
        else{
            cin >> input;
            if(cmd == "add")
                arr[input] = 1;
            else if(cmd == "remove")
                arr[input] = 0;
            else if(cmd == "check")
                if(arr[input])
                    cout << 1 << '\n';
                else    
                    cout << 0 << '\n';
            else if(cmd == "toggle")
                arr[input] = 1-arr[input];   
        }
    }
}