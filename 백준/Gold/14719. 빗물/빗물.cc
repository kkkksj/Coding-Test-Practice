#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int FindLeftMax(int i){
	return *max_element(arr.begin(), arr.begin()+i);
}

int FindRightMax(int i){
	return *max_element(arr.begin()+i+1, arr.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int h, w;
	cin >> h >> w;
	
	arr.assign(w, 0);
	for(int i=0; i<w; i++)
		cin >> arr[i];

	int ans = 0;
	for(int i=1; i<w-1; i++){
		int left_max = FindLeftMax(i);
		int right_max = FindRightMax(i);

		int min_num = min(left_max, right_max);
		if(min_num-arr[i] > 0)
			ans += (min_num-arr[i]);
	}

	cout << ans << '\n';
}