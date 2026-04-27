#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int position = 1;
    int coverage = 2 * w + 1;  
    
    for (int station : stations) {
        int left = station - w; 
        
        if (position < left) {
            int gap = left - position;  
            answer += (gap + coverage - 1) / coverage;
        }
        
        position = station + w + 1;
    }
    
    if (position <= n) {
        int gap = n - position + 1;
        answer += (gap + coverage - 1) / coverage;
    }
    
    return answer;
}