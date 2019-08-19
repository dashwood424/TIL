#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int a[50][50];
bool c[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	c[i][j] = true;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && c[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					c[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(c, false, sizeof(c));

		int k;
		cin >> m >> n >> k;
		
		while (k--) {
			int x, y;
			cin >> y >> x;
			a[x][y] = 1;
		}

		int cnt = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && c[i][j] == false) {
					bfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
	return 0;
}