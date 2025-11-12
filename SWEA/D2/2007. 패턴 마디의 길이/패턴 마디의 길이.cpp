#include<iostream>
#include<vector>

using namespace std;

int Find(string &word) {
	int i = 0, j = 1;
	while (j<30) {
		if (word[i] == word[j]) {
			int ti = i, tj = j;
			while (ti < j) {
				if (word[ti] != word[tj])
					break;
				ti++;	tj++;
			}
			if (ti == j)
				return j;
		}
		j++;
	}
	return j;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		string input;
		cin >> input;

		char first_c = input[0];
		int ans = Find(input);
		
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}