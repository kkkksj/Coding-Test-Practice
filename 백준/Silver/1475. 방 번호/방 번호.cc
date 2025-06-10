#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int room_number;
    cin >> room_number;

    int arr[10] = {0,};
    int ans=0;
    int tmp;

    while(room_number > 0){
        tmp = room_number%10;
        room_number /= 10;

        if(tmp == 6 || tmp == 9){
            if(arr[6] >= ans and arr[9] >= ans){
                arr[tmp]++;
                ans++;
            }
            else if(arr[6] < ans)
                arr[6]++;
            else if(arr[9] < ans)
                arr[9]++;
        }
        else{
            if(arr[tmp] >= ans)
                ans++;
            arr[tmp]++;
        }
    }
    cout << ans << '\n';
}