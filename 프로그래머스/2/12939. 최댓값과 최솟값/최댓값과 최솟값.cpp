#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string tmp = "";
    int maxnum = -1e9;
    int minnum = 1e9;
    for(char c : s){
        if(c == ' '){
            int num = stoi(tmp);
            maxnum = max(num, maxnum);
            minnum = min(num, minnum);
            tmp = "";
        }
        else
            tmp += c;
    }
    // 마지막 한 번 더 
    int num = stoi(tmp);
    maxnum = max(num, maxnum);
    minnum = min(num, minnum);
    
    answer += to_string(minnum);
    answer += ' ';
    answer += to_string(maxnum);
    
    return answer;
}