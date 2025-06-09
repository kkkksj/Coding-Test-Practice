#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    double sum_class=0;
    double score=0;
    vector<vector<string>> info(20, vector<string> (3));

    for(int i=0; i<20; i++)
        cin >> info[i][0] >> info[i][1] >> info[i][2] ;
    
    for(int i=0; i<20; i++){
        double s = stof(info[i][1]);
        string rank = info[i][2];
        if(rank != "P")
            sum_class += s;
        if(rank == "A+")
            score += (s * 4.5);
        else if(rank == "A0")
            score += (s * 4);
        else if(rank == "A0")
            score += (s * 4);
        else if(rank == "B+")
            score += (s * 3.5);
        else if(rank == "B0")
            score += (s * 3);
        else if(rank == "C+")
            score += (s * 2.5);
        else if(rank == "C0")
            score += (s * 2);
        else if(rank == "D+")
            score += (s * 1.5);
        else if(rank == "D0")
            score += (s * 1);
    }
    cout << score / sum_class << '\n';
}