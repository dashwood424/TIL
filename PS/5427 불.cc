#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		vector<string> a(n);

		queue<pair<int, int>> q; 
		vector<vector<int>> fire(n, vector<int>(m, -1)); //불이 번지는 시간
		int sx, sy; //상근이의 위치
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') {
					q.push(make_pair(i, j));
					fire[i][j] = 0;
				}
				else if (a[i][j] == '@') {
					sx = i;
					sy = j;
				}
			}
		}

		//불이 번지는 시간 먼저 구하기
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nx][ny] == '#') continue;
					if (fire[nx][ny] == -1) {
						fire[nx][ny] = fire[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}

		vector<vector<int>> d(n, vector<int>(m, -1)); //상근이의 이동 시간
		q.push(make_pair(sx, sy));
		d[sx][sy] = 0;

		int ans = -1;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
				if (ans == -1 || ans > d[x][y] + 1) {
					ans = d[x][y] + 1;
				}
			}

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (a[nx][ny] == '#') continue; //벽인 경우
				if (d[nx][ny] != -1) continue; //이미 지난 칸인 경우
				if (fire[nx][ny] != -1 && fire[nx][ny] <= d[x][y] + 1) continue; //불보다 늦게 도착하는 경우

				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			
		}

		if (ans != -1) {
			cout << ans << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
	}

	return 0;
}