#include <iostream>
#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;

int a[1001][1001];
int d[1001][1001][2]; //0: 벽을 하나도 안부수고 이동한 경우, 1: 벽을 한개 부수고 이동한 경우 이동거리
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	d[0][0][0] = 1; //시작하는 칸과 끝나는 칸도 포함해서 센다
	q.push(make_tuple(0, 0, 0));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위를 벗어나는 경우
			
			if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {
				d[nx][ny][z] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			} 
			if (a[nx][ny] == 1 && d[nx][ny][z + 1] == 0 && z == 0) { //벽을 부수는 경우 -> 다음 칸이 벽이고 벽을 한번도 부수지 않은 경우
				d[nx][ny][z + 1] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}
	
	int ans = -1;

	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0) { //둘 다 0이 아닌 경우
		if (d[n - 1][m - 1][0] < d[n - 1][m - 1][1]) {
			ans = d[n - 1][m - 1][0];
		}
		else {
			ans = d[n - 1][m - 1][1];
		}
	}
	else if (d[n - 1][m - 1][0] != 0) {
		ans = d[n - 1][m - 1][0];
	}
	else if (d[n - 1][m - 1][1] != 0) {
		ans = d[n - 1][m - 1][1];
	}
	else {
		ans = -1;
	}

	cout << ans << '\n';

	return 0;
}