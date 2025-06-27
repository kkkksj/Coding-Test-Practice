#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int FindRound(int n, int kim, int lim){
    queue<int> q1;
    queue<int> q2;
    for(int i=1; i<n+1; i++)
        q1.push(i);
    
    int ans = 0;
    for(int i=0; i<floor(n/2. + 0.5); i++){
        ans++;
        if(i%2==0){
            while(q1.size() > 0){
                int tmp = q1.front();
                q1.pop();
                if(q1.empty())
                    q2.push(tmp);
                else {
                    if((q1.front() == kim && tmp == lim) || (q1.front() == lim && tmp == kim))
                        return ans;
                    else if(tmp == kim || tmp == lim)
                        q2.push(tmp);
                    else if(q1.front() == kim || q1.front() == lim)
                        q2.push(q1.front());
                    else
                        q2.push(tmp);
                    q1.pop();
                }
            }
        }
        else{
            while(q2.size() > 0){
                int tmp = q2.front();
                q2.pop();
                if(q2.empty())
                    q1.push(tmp);
                else {
                    if((q2.front() == kim && tmp == lim) || (q2.front() == lim && tmp == kim))
                        return ans;
                    else if(tmp == kim || tmp == lim)
                        q1.push(tmp);
                    else if(q2.front() == kim || q2.front() == lim)
                        q1.push(q2.front());
                    else
                        q1.push(tmp);
                    q2.pop();
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, kim, lim;
    cin >> n >> kim >> lim;

    cout << FindRound(n, kim, lim);
}