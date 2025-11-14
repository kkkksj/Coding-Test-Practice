#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int Simulation(long long n) {
	unordered_set<char> check;
	long long number = n;
	int ret = 1;
	while (check.size() < 10) {
		string num = to_string(number);
		for (char c : num)
			check.insert(c);
		if (check.size() == 10)
			return ret*n;
		ret++;
		number = n * ret;
	}
	return ret*n;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		long long n;
		cin >> n; 

		int ans;
		ans = Simulation(n);

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}