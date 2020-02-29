#include <iostream>
using namespace std;

int a[10][10];
bool check_row[10][10]; //i행에 숫자 j가 있으면 true
bool check_col[10][10]; //i열에 숫자 j가 있으면 true
bool check_square[10][10]; //i번째 사각형에 숫자 j가 있으면 true

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

bool go(int z) {
	if (z == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}

	int x = z / 9;
	int y = z % 9;
	
	if (a[x][y] != 0) {
		return go(z + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check_row[x][i] == false && check_col[y][i] == false && check_square[square(x, y)][i] == false) { //조건을 만족할 때만 다음 경우 탐색
				check_row[x][i] = true;
				check_col[y][i] = true;
				check_square[square(x, y)][i] = true;
				a[x][y] = i;

				if (go(z + 1)) {
					return true;
				}

				check_row[x][i] = false;
				check_col[y][i] = false;
				check_square[square(x, y)][i] = false;
				a[x][y] = 0;
				
			}
		}
	}

	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				check_row[i][a[i][j]] = true;
				check_col[j][a[i][j]] = true;
				check_square[square(i, j)][a[i][j]] = true;
			}
		}
	}

	go(0);

	return 0;
}