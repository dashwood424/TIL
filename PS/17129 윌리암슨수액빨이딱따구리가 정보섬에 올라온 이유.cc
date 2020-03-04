#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int main() {
	cin >> n >> m;

	vector<string> a(n);
	queue<pair<int, int>> q;
	vector<vector<int>> d(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '2') {
				q.push(make_pair(i, j));
				d[i][j] = 0;
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
				if (a[nx][ny] == '1') continue;
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = -1;
	bool ok = false; //아무 음식도 먹을 수 없는 경우 false

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '3' || a[i][j] == '4' || a[i][j] == '5') {
				if (d[i][j] != -1) {
					ok = true;
					if (ans == -1 || ans > d[i][j]) {
						ans = d[i][j];
					}
				}
			}
		}
	}

	if (ok) {
		cout << "TAK" << '\n';
		cout << ans << '\n';
	}
	else {
		cout << "NIE" << '\n';
	}

	return 0;
}
