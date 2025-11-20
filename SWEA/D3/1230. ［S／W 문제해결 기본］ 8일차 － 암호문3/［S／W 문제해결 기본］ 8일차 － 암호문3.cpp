#include<iostream>
#include<vector>
#include<deque>

using namespace std;

deque<int> dq1, dq2;

void Insert() {
	int idx, n, num;
	cin >> idx >> n;

	while (dq1.size() != idx) {
		if(idx < 10) {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		}
		else {
			if (dq2.empty())
				break;
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		dq1.push_back(num);
	}

	while (dq1.size() != 10) {
		if(dq1.size() < 10) {
			if (dq2.empty())
				return;
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
		else {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		}
	}
}
	
void Delete() {
	int idx, n;
	cin >> idx >> n;

	while (dq1.size() != idx) {
		if (idx < 10) {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		}
		else {
			if (dq2.empty())
				break;
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
	}

	for (int i = 0; i < n; i++) 
		dq2.pop_front();

	while (dq1.size() != 10) {
		if (dq1.size() < 10) {
			if (dq2.empty())
				return;
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
		else {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		}
	}
}

void Add() {
	int n, num;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		dq2.push_back(num);
	}

	while (dq1.size() != 10) {
		if (dq1.size() < 10) {
			if (dq2.empty())
				return;
			dq1.push_back(dq2.front());
			dq2.pop_front();
		}
		else {
			dq2.push_front(dq1.back());
			dq1.pop_back();
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	//cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		cin >> n;

		dq2.clear();
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i < 10)
				dq1.push_back(num);
			else
				dq2.push_back(num);
		}

		cin >> n;
		for (int i = 0; i < n; i++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'I')
				Insert();
			else if (cmd == 'D')
				Delete();
			else
				Add();
		}

		cout << '#' << test_case << ' ';
		while (!dq1.empty()) {
			cout << dq1.front() << ' ';
			dq1.pop_front();
		}
		cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}