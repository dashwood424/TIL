#include <iostream>
#include <stdio.h>
using namespace std;

bool check_row[10][10]; //i행에 숫자 j가 있으면 true
bool check_col[10][10]; //i열에 숫자 j가 있으면 true
bool check_square[10][10]; //사각형 i에 숫자 j가 있으면 true
int a[10][10];

int square(int x, int y) { 
	return (x / 3) * 3 + (y / 3);
}

bool go(int z) {
	if (z == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j];
			}
			cout << '\n';
		}
		return true;
	}
	
	int x = z / 9;
	int y = z % 9;
	
	if (a[x][y] != 0) { //현재 칸이 이미 채워진 경우
		return go(z + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) { //a[x][y]칸에 1~9까지 가능한 숫자 채워봄
			if (check_row[x][i] == false && check_col[y][i] == false && check_square[square(x, y)][i] == false) {
				check_row[x][i] = true;
				check_col[y][i] = true;
				check_square[square(x, y)][i] = true;
				a[x][y] = i;

				if (go(z + 1)) {
					return true;
				}

				a[x][y] = 0;
				check_row[x][i] = false;
				check_col[y][i] = false;
				check_square[square(x, y)][i] = false;
				
			}
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] != 0) {
				check_row[i][a[i][j]] = true;
				check_col[j][a[i][j]] = true;
				check_square[square(i, j)][a[i][j]] = true;
			}
		}
	}

	go(0); //첫 번째 칸부터 탐색

	return 0;
}