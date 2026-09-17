#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#define MAXALPHA 26

using namespace std;

int cnt[MAXALPHA];

int GetMaxCount(string word) {
	for(int i=0; i<MAXALPHA; i++)
		cnt[i] = 0;

	for(char ch : word)
		cnt[ch - 'a']++;

	int answer = 0;

	for(int i=0; i<MAXALPHA; i++)
		answer += cnt[i] * (cnt[i] + 1) / 2;

	return answer;
}

int main(int argc, char** argv)
{
    int t;
	cin >> t;

	for(int test_case=1; test_case<=t; test_case++) {
		string word;
		cin >> word;

		int answer = GetMaxCount(word);

		cout << "#" << test_case << " " << answer << '\n';
	}

	return 0;
}