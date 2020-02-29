/*

만들수 있는 도미노타일 36가지 -> 도미노타일로 72개 칸 채움
1 2, 2 1 -> 같은 도미노

int n, m;
int a[10];
bool c[10];
int cnt = 0;
void go(int start, int index) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cnt += 1;
		cout << '\n';
	}
	for (int i = start; i <= 9; i++) {
		if (c[index]) continue;
		c[index] = true;
		a[index] = i;
		go(i + 1, index + 1);
		c[index] = false;
	}
}

도미노 타일의 개수, 종류, 위치 
1~9 타일 위치
도미노 타일로 채우기

*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int a[10][10];
bool domino[10][10]; //도미노로 사용되었으면 true
bool check_row[10][10]; //i행에 숫자 j가 있으면 true
bool check_col[10][10]; //i열에 숫자 j가 있으면 true
bool check_square[10][10]; //i사각형에 숫자 j가 있으면 true
int dx[] = { 0, 1 };
int dy[] = { 1, 0 }; //도미노를 가로방향으로 배치할지 세로방향으로 배치할지

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
	
	if(a[x][y] != 0) {
		return go(z + 1);
	}
	else {
		for (int k = 0; k < 2; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9) continue; //범위를 벗어나는 경우
			if (a[nx][ny] != 0) continue; //연속한 칸이 빈칸이 아닌 경우
			
			for (int i = 1; i <= 9; i++) {
				for (int j = 1; j <= 9; j++) { //도미노 놓아 봄
					if (i == j) continue;
					if (domino[i][j]) continue;
			
					if (check_row[x][i] == false && check_col[y][i] == false && check_square[square(x, y)][i] == false
						&& check_row[nx][j] == false && check_col[ny][j] == false && check_square[square(nx, ny)][j] == false) {
						domino[i][j] = true;
						domino[j][i] = true;
						check_row[x][i] = true;
						check_col[y][i] = true;
						check_square[square(x, y)][i] = true;
						a[x][y] = i;
						
						check_row[nx][j] = true;
						check_col[ny][j] = true;
						check_square[square(nx, ny)][j] = true;
						a[nx][ny] = j;

						if (go(z + 1)) { //도미노를 놓고 다음 경우 탐색
							return true;
						}

						domino[i][j] = false;
						domino[j][i] = false;
						check_row[x][i] = false;
						check_col[y][i] = false;
						check_square[square(x, y)][i] = false;
						a[x][y] = 0;

						check_row[nx][j] = false;
						check_col[ny][j] = false;
						check_square[square(nx, ny)][j] = false;
						a[nx][ny] = 0;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int n;
	int tc = 1;

	while (true) {
		memset(check_row, false, sizeof(check_row));
		memset(check_col, false, sizeof(check_col));
		memset(check_square, false, sizeof(check_square));
		memset(domino, false, sizeof(domino));
		memset(a, 0, sizeof(a));

		cin >> n; //도미노 타일의 개수
		if (n == 0) break;
		
		for (int i = 0; i < n; i++) {
			string s1, s2;
			int n1, n2;
			cin >> n1 >> s1 >> n2 >> s2;
			int x1 = s1[0] - 'A';
			int y1 = s1[1] - '1';
			int x2 = s2[0] - 'A';
			int y2 = s2[1] - '1';

			domino[n1][n2] = true;
			domino[n2][n1] = true;
			a[x1][y1] = n1;
			a[x2][y2] = n2;

			check_row[x1][n1] = true;
			check_col[y1][n1] = true;
			check_square[square(x1, y1)][n1] = true;

			check_row[x2][n2] = true;
			check_col[y2][n2] = true;
			check_square[square(x2, y2)][n2] = true;
		}

		for (int i = 1; i <= 9; i++) {
			string s;
			cin >> s;
			int x = s[0] - 'A';
			int y = s[1] - '1';
			
			a[x][y] = i;
			check_row[x][i] = true;
			check_col[y][i] = true;
			check_square[square(x, y)][i] = true;
		}

		cout << "Puzzle " << tc << '\n';
		go(0);
		tc += 1;
	}
	return 0;
}