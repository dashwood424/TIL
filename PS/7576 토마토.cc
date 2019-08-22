#include <iostream>
#include <queue>
using namespace std;

int a[1001][1001]; //토마토
int d[1001][1001]; //토마토가 익는 최소 일 수
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m;
	cin >> m >> n;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1) { //익은 토마토가 있으면
				d[i][j] = 0;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < d[i][j]) {
				ans = d[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1 && d[i][j] == -1) {
				ans = -1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
