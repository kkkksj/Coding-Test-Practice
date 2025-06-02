#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std; 

string word;
int cnt[26] = {0, };

int main(void)
{
    cin >> word;
    
    for (char ch : word){
        cnt[toupper(ch) - 'A'] += 1;
    }

    int max_num = *max_element(cnt, cnt+26);
    int max_cnt = count(cnt, cnt+26, max_num);

    if (max_cnt > 1)
        cout << '?' << endl;
    else{
        auto it = find(cnt, cnt+26, max_num);
        int idx = distance(cnt, it);
        cout << char(idx + 'A') << endl;
    }
}