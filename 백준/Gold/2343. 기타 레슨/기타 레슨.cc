#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    int l, r = 0;
	cin >> n >> m;
    vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r += arr[i];	
	}
	l = *max_element(arr.begin(), arr.end());	

	while (l <= r) {	
		int mid = (l + r) / 2;	

		int sum = 0;
        int cnt = 0;	
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if (sum != 0)
            cnt++;	
        	
		if (cnt > m) 
			l = mid + 1;
		else 
			r = mid - 1;
	}
    
	cout << l;
}   