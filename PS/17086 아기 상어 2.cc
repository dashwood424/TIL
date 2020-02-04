/*
안전거리 -> 현재 상어가 있는 칸에서 가장 거리가 가까운 아기 상어 까지의 거리
안전 거리의 최대값
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[50][50];
int dist[50][50];
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };
int n, m;

int bfs(int sx, int sy) {
	memset(dist, -1, sizeof(dist));

	queue<pair<int, int>> q;
	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny] == -1 && a[nx][ny] == 1) {
					return dist[x][y] + 1;
				}
				else if (dist[nx][ny] == -1 && a[nx][ny] == 0) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0; //안전 거리의 최댓값

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) { //빈칸에서 안전거리 구함
				int cur = bfs(i, j);
				if (ans < cur) {
					ans = cur;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
