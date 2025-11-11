#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n;

struct Info {
	int num, idx;
};

struct CMP1 {
	bool operator()(Info a, Info b) {
		if (a.num != b.num)
			return a.num < b.num;
		return a.idx < b.idx;
	}
};
struct CMP2 {
	bool operator()(Info a, Info b) {
		if (a.num != b.num)
			return a.num> b.num;
		return a.idx > b.idx;
	}
};

priority_queue<Info, vector<Info>, CMP1> bpq;
priority_queue<Info, vector<Info>, CMP2> spq;
vector<int> num_list;

int Find() {
	int big, small;
	int big_idx, small_idx;
	for (int i = 0; i < n; i++) {
		big = bpq.top().num;
		big_idx = bpq.top().idx;
		bpq.pop();
		if (num_list[big_idx] != big) {
			bpq.push({ num_list[big_idx], big_idx });
			big = bpq.top().num;
			big_idx = bpq.top().idx;
			bpq.pop();
		}
		small = spq.top().num;
		small_idx = spq.top().idx;
		spq.pop();
		if (num_list[small_idx] != small) {
			spq.push({ num_list[small_idx], small_idx });
			small = spq.top().num;
			small_idx = spq.top().idx;
			spq.pop();
		}

		if (big - small <= 1)
			return big - small;
		bpq.push({ big - 1, big_idx });
		spq.push({ small + 1, small_idx });
		
		num_list[big_idx] = big - 1;
		num_list[small_idx] = small + 1;
	}
	return bpq.top().num - spq.top().num;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		
		bpq = priority_queue<Info, vector<Info>, CMP1>();
		spq = priority_queue<Info, vector<Info>, CMP2>();

		int num;
		num_list.assign(100, 0);
		for (int i = 0; i < 100; i++) {
			cin >> num;
			bpq.push({num, i});
			spq.push({num, i});
			num_list[i] = num;
		}

		cout << '#' << test_case << ' ' << Find() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}