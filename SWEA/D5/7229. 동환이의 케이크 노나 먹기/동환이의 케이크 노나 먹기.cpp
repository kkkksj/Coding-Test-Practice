#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <algorithm>

#define MAXN 50
#define MAXM 100000

using namespace std;

int n, m;
long long cake[MAXN];
int cnt[MAXN];

long double GetSize(int idx) {
	return (long double)cake[idx] / cnt[idx];
}

int GetMaxIdx() {
	int idx = 0;

	for(int i=1; i<n; i++) {
		// 실수 비교 대신 교차곱으로 비교
		if (cake[i] * (long long)cnt[idx] > cake[idx] * (long long)cnt[i])
			idx = i;
	}

	return idx;
}

long double GetDiff() {
	long double minsize = GetSize(0);
	long double maxsize = GetSize(0);

	for(int i=1; i<n; i++) {
		long double size = GetSize(i);
		minsize = min(minsize, size);
		maxsize = max(maxsize, size);
	}

	return maxsize - minsize;
}

int main(int argc, char** argv)
{
    int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		cin >> n;

		for(int i=0; i<n; i++) {
			cin >> cake[i];
			cnt[i] = 1;	// 처음에는 각 케이크가 한 조각
		}

		cin >> m;

		long double answer = GetDiff();

		for(int cut=0; cut<m; cut++) {
			// 지금 가장 큰 조각을 가진 케이크를 한 번 더 나눔
			int idx = GetMaxIdx();
			cnt[idx]++;

			// 칼을 꼭 M번 다 쓸 필요는 없으므로 매번 확인
			answer = min(answer, GetDiff());
		}

		cout << "#" << test_case << " ";
		cout << fixed << setprecision(10) << answer << '\n';
	}

	return 0;
}