#include <iostream>
#include <string>
#include <queue>
#include <cstdio>
#include <cstring>
#include <tuple>
using namespace std;

string a[31][31];
int d[31][31][31]; //각 위치에 도착하는 최단시간
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 0,0,0,0,1,-1 };
int dz[] = { 1,-1,0,0,0,0 };

int main() {
	while (true) {
		int l, n, m; //층수, 세로, 가로
		cin >> l >> n >> m;
		if (l == 0 && n == 0 && m == 0) break;
		int sz, sx, sy, ez, ex, ey; //시작위치와 도착위치
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				for (int k = 0; k < m; k++) {
					if (a[i][j][k] == 'S') {
						sz = i; //높이
						sx = j; //세로
						sy = k; //가로
					}
					else if (a[i][j][k] == 'E') {
						ez = i;
						ex = j;
						ey = k;
					}
				}
			}
		}
		memset(d, -1, sizeof(d));

		queue<tuple<int, int, int>> q;
		d[sz][sx][sy] = 0;
		q.push(make_tuple(sz, sx, sy));

		while (!q.empty()) {
			int z, x, y;
			tie(z, x, y) = q.front();
			q.pop();

			for (int k = 0; k < 6; k++) {
				int nz = z + dz[k];
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nz && nz < l && 0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nz][nx][ny] != '#' && d[nz][nx][ny] == -1) { //벽이 아니고 방문한 적이 없으면
						d[nz][nx][ny] = d[z][x][y] + 1;
						q.emplace(nz, nx, ny);
					}
				}
			}
		}
		if (d[ez][ex][ey] != -1) {
			printf("Escaped in %d minute(s).\n", d[ez][ex][ey]);
		}
		else {
			printf("Trapped!\n");
		}
	}
	return 0;
}