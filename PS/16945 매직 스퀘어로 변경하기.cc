#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[9];

bool check(vector<int> &b) { //매직스퀘어이면 true
	int c[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c[i][j] = b[i * 3 + j];
		}
	}

	int temp = c[0][0] + c[0][1] + c[0][2]; //첫 번째 행의 합

	for (int i = 0; i < 3; i++) { //행방향 비교
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += c[i][j];
		}
		if (temp != sum) {
			return false;
		}
	}

	for (int j = 0; j < 3; j++) {
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += c[i][j];
		}
		if (temp != sum) {
			return false;
		}
	}

	if (c[0][0] + c[1][1] + c[2][2] != temp) return false; //대각선 방향 비교
	if (c[0][2] + c[1][1] + c[2][0] != temp) return false;

	return true;
}

int main() {
	vector<int> b(9);
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		b[i] = i + 1;
	}

	int ans = -1;

	do {
		if (check(b)) { //b가 매직스퀘어이면
			int cur = 0;
			for (int i = 0; i < 9; i++) {
				int temp = a[i] - b[i];
				if (temp < 0) temp = -temp;
				cur += temp;
			}
			if (ans == -1 || ans > cur) {
				ans = cur;
			}
		}
	} while (next_permutation(b.begin(), b.end()));

	cout << ans << '\n';
	
	return 0;
}