#include <string>
#include <vector>

using namespace std;

string convertJC(string str){
    int n = str.size();
    
    if(str[0] >= 'a' && str[0] <= 'z')
        str[0] = (str[0]-'a' + 'A');
    for(int i=1; i<n; i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i]-'A' + 'a');
    
    return str;
}

string solution(string s) {
    string answer = "";
    
    int n=s.size();
    
    string str = "";
    for(int i=0; i<n; i++){
        if(s[i] == ' '){
            str = convertJC(str);
            answer += str;
            answer += ' ';
            str = "";
        }        
        else
            str += s[i];
    }
    
    str = convertJC(str);
    answer += str;
    // answer += ' ';
    // str = "";
    
    return answer;
}