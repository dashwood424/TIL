#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[51][51] = { -1, };
string a[51];
int bfs(int sx, int sy) {
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	int res = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		res = max(res, dist[x][y]);

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 'L' && dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return res;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}