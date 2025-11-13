#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int n, m;
vector<string> arr;

int Find(int si, int sj) {
	string code = "";
	int odd_sum = 0;
	int even_sum = 0;
	int cnt = 8;
	int num;
	for (int i = 0; i < 56; i++) {
		code = (arr[si][sj - i] + code);
		if(code.size()==7) {
			if (code == "0001101")
				num = 0;
			else if (code == "0011001")
				num = 1;
			else if (code == "0010011")
				num = 2;
			else if (code == "0111101")
				num = 3;
			else if (code == "0100011")
				num = 4;
			else if (code == "0110001")
				num = 5;
			else if (code == "0101111")
				num = 6;
			else if (code == "0111011")
				num = 7;
			else if (code == "0110111")
				num = 8;
			else if (code == "0001011")
				num = 9;
			else
				return 0;

			code = "";

			if (cnt % 2 == 0)
				even_sum += num;
			else
				odd_sum += num;
			cnt--;
		}
	}

	if ((odd_sum * 3 + even_sum) % 10 == 0)
		return odd_sum + even_sum;
	return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m;

		arr.assign(n, "");

		for(int i=0; i<n; i++)
			cin >> arr[i];
			
		int ans;
		bool flag = false;
		for(int i=0; i<n; i++) {
			for (int j = m - 1; j >= 0; j--)
				if (arr[i][j] == '1') {
					ans = Find(i, j);
					flag = true;
					break;
				}
			if (flag)
				break;
		}

		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}