#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string, string> parents;
unordered_map<string, int> cnts;

string GetParent(string a) {
	if (parents[a] == a)
		return a;
	else
		return parents[a] = GetParent(parents[a]);
}

void Unify(string a, string b) {
	string a_ = GetParent(a);
	string b_ = GetParent(b);

	if (a_ == b_)
		return;

	parents[b_] = a_;
	cnts[a_] += cnts[b_];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		parents.clear();
		cnts.clear();

		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;

			if (parents.count(a) == 0) {
				parents.insert({ a, a });
				cnts.insert({ a, 1 });
			}
			if (parents.count(b) == 0) {
				parents.insert({ b, b });
				cnts.insert({ b, 1 });
			}

			Unify(a, b);
			cout << cnts[GetParent(a)] << '\n';
		}
	}
}