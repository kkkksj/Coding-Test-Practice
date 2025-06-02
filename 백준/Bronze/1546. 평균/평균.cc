#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int n;
double max_score;
double sum = 0;

int main(void)
{
    cin >> n;
    
    int *score = new int [n];
    for(int i=0; i<n; i++){
        cin >> score[i];
    }

    max_score = *max_element(score, score+n);

    for(int i=0; i<n; i++){
        sum += (score[i]/max_score*100);
    }

    cout << sum/n << endl;
}