/*
n*n 크기인 체스판 위에 퀸 n개를 놓는 문제
최대 2^(15*15) 복잡도를 가지는 문제 백트래킹으로 단순화 시키기 
*/

#include <iostream>
using namespace std;

bool check_col[16]; //i번째 열에 퀸이 있으면 true
bool check_diag1[32]; //i번째 오른쪽 위로 향하는 대각선
bool check_diag2[32]; //i번째 오른쪽 아래로 향하는 대각선
int n;
bool a[16][16];

bool check(int i, int j) { //i번째 행에 퀸을 놓을 수 있는지-> 백트래킹 조건
	if (check_col[j]) {
		return false;
	}

	if (check_diag1[i + j]) {
		return false;
	}

	if (check_diag2[i - j + n]) {
		return false;
	}

	return true;
}

int go(int row) { //행마다 퀸을 1개씩 놓아보기
	if (row == n) {
		return 1;
	}

	int cnt = 0;

	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			check_col[col] = true;
			check_diag1[row + col] = true;
			check_diag2[row - col + n] = true;
			a[row][col] = true; //퀸을 놓아봄

			cnt += go(row + 1);

			check_col[col] = false;
			check_diag1[row + col] = false;
			check_diag2[row - col + n] = false;
			a[row][col] = false;
		}
	}

	return cnt;
}

int main() {
	cin >> n;
	cout << go(0) << '\n';
	return 0;
}