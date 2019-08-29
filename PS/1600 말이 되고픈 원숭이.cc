#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int d[200][200][31];
int a[200][200];
int dx[] = { 0,0,1,-1,-1,-2,-2,-1,1,2,2,1 };
int dy[] = { 1,-1,0,0,-2,-1,1,2,2,1,-1,-2 };
int dz[] = { 0,0,0,0,1,1,1,1,1,1,1,1 };

int main() {
	int l; 
	cin >> l; //말 처럼 갈 수 있는 횟수
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	queue<tuple<int, int, int>> q;
	d[0][0][0] = 0;
	q.push(make_tuple(0, 0, 0));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 12; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + dz[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m && nz <= l) {
				if (a[nx][ny] == 0 && d[nx][ny][nz] == -1) {
					d[nx][ny][nz] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, nz));
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= l; i++) {
        if(d[n - 1][m - 1][i]==-1) continue;
		if (ans == -1 || ans > d[n - 1][m - 1][i]) {
			ans = d[n - 1][m - 1][i];
		}
	}
	cout << ans << '\n';

	return 0;
}