#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n, 0));
		arr[0][0] = 1;
		
		cout << '#' << test_case << '\n';
		cout << arr[0][0] << '\n';
		for(int i=1; i<n; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (j == 0 || j == i)
					arr[i][j] = 1;
				else
					arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}