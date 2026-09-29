#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> answers;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            int next = elements[(i+j)%n];
            sum += next;
            answers.insert(sum);
        }
    }
        
    int answer = answers.size();
    return answer;
}