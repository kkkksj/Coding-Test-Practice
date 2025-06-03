#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int c;

int main(void)
{
    cin >> c;

    for(int i=0; i<c; i++){
        int n;
        cin >> n;

        vector<int> scores(n);
        int sum = 0;
        for(int j=0; j<n; j++){
            cin >> scores[j];
            sum += scores[j];
        }
        double avg = sum / n;

        double cnt = 0;
        for(int score : scores){
            if(score > avg)
                cnt += 1;
        }

        cout << fixed;
        cout.precision(3);
        cout << (cnt/n)*100 << '%' << endl;
    }
}