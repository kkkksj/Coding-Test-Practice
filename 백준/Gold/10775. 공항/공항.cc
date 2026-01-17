#include<iostream>
#include<vector>

using namespace std;

int g, p;
vector<int> arr;

int find(int num) {
	if (num == arr[num])
		return num;
	return arr[num] = find(arr[num]);
}

void unify(int a, int b) {
	a = find(a);
	b = find(b);

	if (a < b)
		arr[b] = a;
	else
		arr[a] = b;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> g >> p;
	arr.assign(g + 1, 0);

	for (int i = 0; i < g + 1; i++)
		arr[i] = i;

	int num;
	int ans = 0;
	while (p--) {
		cin >> num;

		num = find(num);

		if (num == 0)
			break;

		unify(num, num - 1);

		ans++;
	}

	cout << ans << '\n';
}