#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int grid[10][10];
int ones = 0;
int ans = 10000;
int paper[6] = { 0, 5, 5, 5, 5, 5 };

bool IsPossible(int i, int j, int l) {
	for (int r = i; r < i + l; r++)
		for (int c = j; c < j + l; c++) {
			if (r >= 10 || c >= 10)
				return false;
			if (grid[r][c] == 0)
				return false;
		}
	return true;
}

void Fill(int i, int j, int l, int num) {
	for (int r = i; r < i + l; r++)
		for (int c = j; c < j + l; c++) {
			grid[r][c] = num;
		}
}
void Back(int r, int c, int cntone, int cntsquare) {
	if (cntsquare >= ans)
		return;

	if (c >= 10) {
		Back(r + 1, 0, cntone, cntsquare);
		return;
	}

	if (r >= 10) {
		if (cntone == ones) ans = min(ans, cntsquare);
		return;
	}

	if (grid[r][c] == 1) {
		for (int k = 5; k >= 1; k--) {
			if (paper[k] > 0 && IsPossible(r, c, k)) {
				paper[k]--;
				Fill(r, c, k, 0);

				Back(r, c + 1, cntone + k * k, cntsquare + 1);

				Fill(r, c, k, 1);
				paper[k]++;
			}
		}
	}
	else
		Back(r, c + 1, cntone, cntsquare);
}

int main() {
	ones = 0;
	ans = 10000;
	for (int i = 1; i < 6; i++)
		paper[i] = 5;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1)
				ones++;
		}

	Back(0, 0, 0, 0);

	if (ans == 10000)
		ans = -1;

	cout << ans << '\n';
	
}