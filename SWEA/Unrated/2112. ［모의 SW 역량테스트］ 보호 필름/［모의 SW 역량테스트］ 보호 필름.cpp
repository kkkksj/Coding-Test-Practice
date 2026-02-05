#include<iostream>
#include<vector>

using namespace std;

int d, w, k;
int film[13][20];	// 세로, 가로 최대로 할당
int aorb[13] = { -1, };

bool IsPass() {
	// 모든 열의 행들을 검사하며 조건을 충족 여부 반환
	int pre, now, cnt;
	for (int j = 0; j < w; j++) {
		cnt = 1;
		bool flag = false;
		for (int i = 0; i < d; i++) {
			if (aorb[i] != -1)
				now = aorb[i];
			else
				now = film[i][j];
			if (i == 0) {
				pre = now;
				continue;
			}
			if (pre == now)
				cnt++;
			else {
				cnt = 1;
				pre = now;
			}
			if (cnt >= k) {
				flag = true;
				break;
			}
		}
		if (!flag)
			return false;
	}
	return true;
}

bool AorB(int cnt, vector<int> &picked) {
	// 뽑은 조합 각 행에 A(0)를 줄지 B(1)를 줄지
	// 뽑은 조합을 어떻게 알게하지.......
	if (cnt == picked.size())
		return IsPass();
	
	aorb[picked[cnt]] = 0;
	if (AorB(cnt + 1, picked))
		return true;
	aorb[picked[cnt]] = 1;
	if (AorB(cnt + 1, picked))
		return true;

	aorb[picked[cnt]] = -1;

	return false;
}

bool Back(int start, int cnt, int len, vector<int> &picked) {
	// d C cnt 조합 뽑기
	if (cnt == len) 
		return AorB(0, picked);
	
	for (int i = start; i < d; i++) {
		picked.push_back(i);
		if (Back(i + 1, cnt + 1, len, picked))
			return true;
		picked.pop_back();
	}
	return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			aorb[i] = -1;
			for (int j = 0; j < w; j++)
				cin >> film[i][j];
		}
		int ans = 0;
		if (k > 1) {
			for (int i = 0; i <= k; i++) {
				// 일단 경우의 수 다 뽑고 만족하는지 계산 
				vector<int> picked;
				if (Back(0, 0, i, picked)) {
					ans = i;
					break;
				}
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}