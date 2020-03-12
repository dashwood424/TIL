#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[1001][1001][2]; //0: 벽을 부수지 않았을 때, 1: 벽을 부쉈을 때
int a[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;
	int hx, hy, ex, ey;
	cin >> hx >> hy >> ex >> ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	dist[hx][hy][0] = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(hx, hy, 0));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			
			if (1 <= nx && nx <=n && 1 <= ny && ny <= m) {
				if (a[nx][ny] == 0 && dist[nx][ny][z] == -1) {
					dist[nx][ny][z] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z));
				}
				if (a[nx][ny] == 1 && dist[nx][ny][z + 1] == -1 && z == 0) { //벽을 부수는 경우 -> 다음 칸이 벽이고 벽을 한번도 부수지 않은 경우
					dist[nx][ny][z + 1] = dist[x][y][z] + 1;
					q.push(make_tuple(nx, ny, z + 1));
				}
			}
		}
	}

	int ans = 0;

	if (dist[ex][ey][0] != -1 && dist[ex][ey][1] != -1) {
		if (dist[ex][ey][0] < dist[ex][ey][1]) {
			ans = dist[ex][ey][0];
		}
		else {
			ans = dist[ex][ey][1];
		}
	}
	else if (dist[ex][ey][0] != -1) {
		ans = dist[ex][ey][0];
	}
	else if (dist[ex][ey][1] != -1) {
		ans = dist[ex][ey][1];
	}
	else {
		ans = -1;
	}

	cout << ans << '\n';

	return 0;
}