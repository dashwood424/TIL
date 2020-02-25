#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int b1[8][8];
int b2[8][8];
int a[50][50];

int go(int sx, int sy) {
	int temp1 = 0, temp2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (a[sx + i][sy + j] != b1[i][j]) {
				temp1 += 1;
			}
			if (a[sx + i][sy + j] != b2[i][j]) {
				temp2 += 1;
			}
		}
	}
	if (temp1 < temp2) {
		return temp1;
	}
	else {
		return temp2;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'W') {
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j += 2) {
				b1[i][j] = 1;
			}
		}
		else {
			for (int j = 1; j < 8; j += 2) {
				b1[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 1; j < 8; j += 2) {
				b2[i][j] = 1;
			}
		}
		else {
			for (int j = 0; j < 8; j += 2) {
				b2[i][j] = 1;
			}
		}
	}

	int ans = -1;

	//8*8크기로 잘라내기
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cur = go(i, j);
			if (ans == -1 || ans > cur) {
				ans = cur;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}