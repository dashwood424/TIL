#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };
int a[50][50];
bool c[50][50];
int n, m;

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	c[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && !c[nx][ny]) {
					c[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0) break;

		memset(a, 0, sizeof(a));
		memset(c, false, sizeof(c));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && !c[i][j]) {
					bfs(i, j);
					ans += 1;
				}
			}
		}

		cout << ans << '\n';
	}
}