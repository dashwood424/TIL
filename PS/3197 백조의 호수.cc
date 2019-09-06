#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string a[1500];
bool scheck[1500][1500]; //백조가 방문한 칸
bool wcheck[1500][1500]; //물 이동
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey; //백조의 위치
	sx = sy = ex = ey = -1;
	queue<pair<int, int>> swan, water, nswan, nwater;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
				a[i][j] = '.';
			}
			else if (a[i][j] == '.') {
				water.push(make_pair(i, j));
				wcheck[i][j] = true;
			}
		}
	}

	scheck[sx][sy] = true;
	swan.push(make_pair(sx, sy));

	for (int i = 0; ; i++) {
		while (!water.empty()) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			a[x][y] = '.';

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nx][ny] == '.' && wcheck[nx][ny] == false) {
						wcheck[nx][ny] = true;
						water.push(make_pair(nx, ny));
					}
					else {
						wcheck[nx][ny] = true;
						nwater.push(make_pair(nx, ny));
					}
				}
			}
		}

		while (!swan.empty()) {
			int x = swan.front().first;
			int y = swan.front().second;
			swan.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nx][ny] == '.' && scheck[nx][ny] == false) {
						scheck[nx][ny] = true;
						swan.push(make_pair(nx, ny));
					}
					else {
						scheck[nx][ny] = true;
						nswan.push(make_pair(nx, ny));
					}
				}
			}
 		}

		if (scheck[ex][ey]) {
			cout << i << '\n';
			break;
		}

		swan = nswan;
		water = nwater;
		nswan = queue<pair<int, int>>();
		nwater = queue<pair<int, int>>();
	}

	return 0;
}