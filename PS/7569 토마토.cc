#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int a[101][101][101];
int d[101][101][101]; //토마토가 익는 최소 일 수
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };

int main() {
	int n, m, h;
	cin >> m >> n >> h;
	
	queue<tuple<int, int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> a[i][j][k];
				d[i][j][k] = -1;
				if (a[i][j][k] == 1) { //익은 토마토가 있으면
					q.push(make_tuple(i, j, k));
					d[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + dz[k];

			if (0 <= nx && nx < h && 0 <= ny && ny < n && 0 <= nz && nz < m) {
				if (a[nx][ny][nz] == 0 && d[nx][ny][nz] == -1) {
					q.push(make_tuple(nx, ny, nz));
					d[nx][ny][nz] = d[x][y][z] + 1;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (ans < d[i][j][k]) {
					ans = d[i][j][k];
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (a[i][j][k] != -1 && d[i][j][k] == -1) {
					ans = -1;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}