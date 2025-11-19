#include<iostream>
#include<vector>

using namespace std;

int h, w, n;
vector<string> gamemap;
int train_i, train_j;
vector<int> i_list = { -1, 1, 0, 0 };
vector<int> j_list = { 0, 0, -1, 1 };
vector<char> d_list = { '^', 'v', '<', '>' };
int d;

void Shoot() {
	int now_i = train_i, now_j = train_j;
	while (true) {
		now_i += i_list[d];
		now_j += j_list[d];
		if (now_i < 0 || now_i >= h || now_j < 0 || now_j >= w)
			return;
		char c = gamemap[now_i][now_j];
		if (c == '*') {
			gamemap[now_i][now_j] = '.';
			return;
		}
		if (c == '#')
			return;
	}
}

void Move(char cmd) {
	if (cmd == 'U')
		d = 0;
	else if (cmd == 'D')
		d = 1;
	else if (cmd == 'L')
		d = 2;
	else
		d = 3;

	gamemap[train_i][train_j] = d_list[d];

	int next_i = train_i + i_list[d];
	int next_j = train_j + j_list[d];
	if (next_i < 0 || next_i >= h || next_j < 0 || next_j >= w)
		return;
	if (gamemap[next_i][next_j] == '.') {
		gamemap[train_i][train_j] = '.';
		gamemap[next_i][next_j] = d_list[d];
		train_i = next_i;	 train_j = next_j;
		return;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> h >> w;

		gamemap.assign(h, "");
		for (int i = 0; i < h; i++) {
			cin >> gamemap[i];
			for (int j = 0; j < w; j++) {
				char c = gamemap[i][j];
				if (c == '<' || c == '>' || c == '^' || c == 'v') {
					train_i = i;	train_j = j;
					if (c == '<')
						d = 2;
					else if (c == '>')
						d = 3;
					else if (c == '^')
						d = 0;
					else
						d = 1;
				}
			}
		}

		cin >> n;
		
		string cmds;
		cin >> cmds;

		for (char cmd : cmds) {
			if (cmd == 'S')
				Shoot();
			else
				Move(cmd);
		}

		cout << '#' << test_case << ' ';
		for (string g : gamemap)
			cout << g << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}