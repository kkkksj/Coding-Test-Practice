#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

#define MAXN 100000
#define MAXINT 1e9

using namespace std;

int n;
int arr[MAXN];
int lis[MAXN];

int GetLisLength() {
	int len = 0;

	for(int i=0; i<n; i++) {
		int idx = lower_bound(lis, lis + len, arr[i]) - lis;

		lis[idx] = arr[i];

		if (idx == len)
			len++;
	}

	return len;
}

int main(int argc, char** argv)
{
	int test_case;
	int t;

	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		cin >> n;

		for(int i=0; i<n; i++)
			cin >> arr[i];

		int answer = GetLisLength();

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}