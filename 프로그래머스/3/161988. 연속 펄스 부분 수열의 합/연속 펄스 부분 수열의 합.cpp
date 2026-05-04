#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long kadane(vector<long long>& arr) {
    long long maxSum = arr[0];
    long long curSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (curSum + arr[i] > arr[i])
            curSum = curSum + arr[i];
        else
            curSum = arr[i];
        
        if (curSum > maxSum)
            maxSum = curSum;
    }
    return maxSum;
}

long long solution(vector<int> sequence) {
    int n = sequence.size();
    
    vector<long long> pulse1(n);
    vector<long long> pulse2(n);
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            pulse1[i] = sequence[i] * 1;
            pulse2[i] = sequence[i] * -1;
        } else {
            pulse1[i] = sequence[i] * -1;
            pulse2[i] = sequence[i] * 1;
        }
    }
    
    long long result1 = kadane(pulse1);
    long long result2 = kadane(pulse2);
    
    if (result1 > result2)
        return result1;
    else
        return result2;
}