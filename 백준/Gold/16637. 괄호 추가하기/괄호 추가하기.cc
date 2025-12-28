#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n;
string formula;
vector<bool> check;
int ans = -pow(2, 31);

int form(int a, int b, char op) {
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '*')
		return a * b;
}

int Cal() {
	int left = formula[0] - '0';
	for (int i = 1; i < n; i += 2) {
		int right = formula[i + 1] - '0';
		if (check[i])
			left = form(formula[i - 1] - '0', right, formula[i]);
		else if (check[i + 2]) {
			left = form(left, form(right, formula[i + 3] - '0', formula[i + 2]), formula[i]);
			i += 2;
		}
		else
			left = form(left, right, formula[i]);
	}
	return left;
}

void Search(int cnt) {
	if(cnt >= n){
		ans = max(ans, Cal());
		return;
	}

	Search(cnt + 2);

	if (cnt % 2 == 1) {
		check[cnt] = 1;
		Search(cnt + 4);
		check[cnt] = 0;
	}
}

int main() {
	cin >> n;
	cin >> formula;
	check.assign(n+3, false);

	Search(1);
	
	cout << ans << '\n';
}