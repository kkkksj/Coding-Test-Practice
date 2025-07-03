#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void FindMax(vector<vector<int>> arr, int day, int n, int &max_income, int income){
    if(day > n)
        max_income = max(max_income, income);
    else{
        FindMax(arr, day+1, n, max_income, income);
        if(day+arr[day][0] < n+2)
            FindMax(arr, day+arr[day][0], n, max_income, income+arr[day][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> arr (n+1, vector<int> (2));
    for(int i=1; i<n+1; i++)
        cin >> arr[i][0] >> arr[i][1];
    
    int max_income = 0;
    int income = 0;
    FindMax(arr, 1, n, max_income, income);
    cout << max_income << '\n';
}