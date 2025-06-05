#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std; 

bool Comp(string a, string b) {
    if (a.length() != b.length()) 
        return a.length() < b.length();
    else 
        return a < b;
}

int main() {
    int n;
    cin >> n;

    string word;
    vector<string> arr;
    for(int i=0; i<n; i++){
        cin >> word;
        arr.push_back(word);
    }
    sort(arr.begin(), arr.end(), Comp);

    for(int i=0; i<n; i++)
        if(i==0 || arr[i] != arr[i-1])
            cout << arr[i] << '\n';
}