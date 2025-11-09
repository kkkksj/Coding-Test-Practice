#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isPal(const string word, int s, int e){
    while(s < e){
        if(word[s++] != word[e--]) return false;
    }
    return true;
}

int IsPalindrome(string word){
    int len = (int)word.size();
    int s = 0, e = len-1;

    bool flag = false;
    while(s<e){
        if(word[s] == word[e]){
            s++;
            e--;
        }
        else{
            bool a = isPal(word, s+1, e);
            bool b = isPal(word, s, e-1);
            return (a || b) ? 1 : 2;
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
   
    int n;
    cin >> n;

    string word;
    while(n--){
        cin >> word;
        cout << IsPalindrome(word) << '\n';
    }
}