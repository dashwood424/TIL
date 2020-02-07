#include <iostream>
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int a[1001][1001];
int d[1001][1001][11]; //벽을 10개까지 부술 수 있음
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	
	queue<tuple<int, int, int>> q;
	d[0][0][0] = 1; //시작하는 칸도 포함
	q.push(make_tuple(0, 0, 0));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int t = 0; t < 4; t++) {
			int nx = x + dx[t];
			int ny = y + dy[t];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (a[nx][ny] == 0 && d[nx][ny][z] == 0) { //빈 칸인 경우
				d[nx][ny][z] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}

			if (a[nx][ny] == 1 && d[nx][ny][z + 1] == 0 && z + 1 <= k) { //벽은 k개 까ㅏ지 부술 수 있음
				d[nx][ny][z + 1] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}

	int ans = -1;
	bool ok = true;
	for (int i = 0; i <= k; i++) {
		if (d[n - 1][m - 1][i] != 0) { 
			if (ans == -1 || d[n - 1][m - 1][i] < ans) {
				ans = d[n - 1][m - 1][i];
			}
		}
	}

	if (ans == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}