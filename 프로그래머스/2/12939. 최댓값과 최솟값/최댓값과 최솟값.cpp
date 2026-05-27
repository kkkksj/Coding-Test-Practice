#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string tmp = "";
    int maxnum = -21e8;
    int minum = 21e8;
    for(char c : s){
        if(c == ' '){
            int num = stoi(tmp);
            maxnum = max(num, maxnum);
            minum = min(num, minum);
            tmp = "";
        }
        else
            tmp += c;
    }
    int num = stoi(tmp);
    maxnum = max(num, maxnum);
    minum = min(num, minum);
    
    answer += to_string(minum);
    answer += ' ';
    answer += to_string(maxnum);
    return answer;
}