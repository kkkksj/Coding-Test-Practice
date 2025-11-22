#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<string, int> dic = { {"ZRO",0}, {"ONE",1}, {"TWO",2}, {"THR",3}, {"FOR",4}, {"FIV",5}, {"SIX",6}, {"SVN",7}, {"EGT",8}, {"NIN",9} };

bool CMP(string a, string b) {
	return dic[a] < dic[b];
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	vector<string> arr;
	for (test_case = 1; test_case <= T; ++test_case) {
		string tc;
		cin >> tc;
		int n;
		cin >> n;

		arr.assign(n, "");
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end(), CMP);

		cout << tc << '\n';
		for (string a : arr) 
			cout << a << ' ';
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}