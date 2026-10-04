#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i=1; i<sqrt(yellow)+1; i++){
        if(yellow % i ==0){
            int j = yellow / i;
            if((i+2) * 2 + j*2 == brown){
                answer.push_back(j+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    return answer;
}