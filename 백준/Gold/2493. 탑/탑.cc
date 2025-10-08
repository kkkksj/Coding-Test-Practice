#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n;
	cin >> n;

	stack <pair<int, int>> st;
	for(int i=1; i<n+1; i++){
		int num;
		cin >> num;

		while(!st.empty()){
			if(st.top().first <= num)	
				st.pop();
			else
				break;
		}
		if(st.empty())
			cout << 0 << ' ';
		else
			cout << st.top().second << ' ';
		
		st.push({num, i});
	}
}