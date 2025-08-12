#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX 1000001

void Find(int num, vector<bool> &prime){
    for(int n=num; n>sqrt(num)-1; n--)
        if(prime[n])
            if(prime[num-n]){
                cout << num << " = " << num-n << " + " << n << '\n';
                return;
            }

    cout << "Goldbach's conjecture is wrong." << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<bool> prime (MAX, true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<sqrt(MAX)+1; i++)
        if(prime[i] == true)
            for(int j=i*i; j<MAX+1; j+=i)
                prime[j] = false;

    while(true){
        int num; 
        cin >> num;
        if(num == 0)
            break;
        Find(num, prime);        
    }
}