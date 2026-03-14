#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int n, k;
string str;
int ans = -1;
bool visited[11][1000000];

void Back(int cnt) {
    if (cnt == k) {
        if (ans < stoi(str)) {
            ans = stoi(str);
        }
        return;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            if (str[j] == '0' && i == 0)
                continue;
            swap(str[i], str[j]);
            if (visited[cnt][stoi(str)] == false) {
                visited[cnt][stoi(str)] = true;
                Back(cnt + 1);
            }
            swap(str[i], str[j]);
        }

    return;
}

int main(int argc, char** argv)
{   
    for (int i = 0; i <= k; i++)
        for (int j = 0; j < 1000000; j++)
            visited[i][j] = false;

    cin >> str >> k;
    n = (int)str.size();

    Back(0);

    cout << ans << '\n';
    
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}