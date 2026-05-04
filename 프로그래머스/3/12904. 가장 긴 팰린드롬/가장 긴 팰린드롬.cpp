#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int n = s.size();
    int maxLen = 1;
    
    for (int i = 0; i < n; i++) {
        
        int left = i;
        int right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen)
                maxLen = right - left + 1;
            left--;
            right++;
        }
     
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen)
                maxLen = right - left + 1;
            left--;
            right++;
        }
    }
    
    return maxLen;
}