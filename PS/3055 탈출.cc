#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int water[50][50]; //물이 차는 데 걸리는 시간
int d[50][50]; //고슴도치가 이동하는 시간

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	memset(water, -1, sizeof(water));
	memset(d, -1, sizeof(d));
	int sx, sy, ex, ey; //고슴도치 위치, 비버굴 위치
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (a[i][j] == 'D') {
				ex = i;
				ey = j;
			}
			else if (a[i][j] == '*') { //물이 찬곳
				q.push(make_pair(i, j));
				water[i][j] = 0;
			}
		}
	}

	while (!q.empty()) { //물부터 이동
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 'D') continue; //비버굴을 만난경우
				if (a[nx][ny] == 'X') continue; //돌을 만난 경우
				if (water[nx][ny] != -1) continue; //이미 방문했던 경우

				water[nx][ny] = water[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	d[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 'X') continue; //돌이면 
				if (a[nx][ny] == '*') continue; //물이 시작하는 곳이면 
				if (water[nx][ny] != -1 && water[nx][ny] <= d[x][y] + 1) continue; //물이 지난 자리이고 물보다 칸에 동시에 or 늦게 도착하는 경우 
				if (d[nx][ny] != -1) continue; //이미 방문했던 경우

				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (d[ex][ey] == -1) { //비버굴에 도착하지 못한 경우
		cout << "KAKTUS" << '\n';
	}
	else {
		cout << d[ex][ey] << '\n';
	}
	return 0;
}