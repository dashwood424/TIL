#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, k; //치즈 공장의 개수

tuple<int, int, int> bfs(vector<vector<int>> &b, int sx, int sy, int hp) {
	vector<vector<int>> d(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	d[sx][sy] = 0;

	vector<tuple<int, int, int>> ret;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (d[nx][ny] != -1) continue; //이미 방문한 칸인 경우
				if (b[nx][ny] == -1) continue; //장애물

				if (d[nx][ny] == -1) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;

					if (b[nx][ny] > 0 && b[nx][ny] <= hp) {
						ret.push_back(make_tuple(d[nx][ny], nx, ny));
					}
				}
			}
		}
	}
	if (!ret.empty()) {
		//sort(ret.begin(), ret.end());
		return ret[0];
	}
	else {
		return make_tuple(-1, 1, -1);
	}
}

int main() {
	cin >> n >> m >> k;
	int sx, sy;
	vector<string> a(n);
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') { //쥐 시작 위치
				sx = i;
				sy = j;
				b[i][j] = 0;
			}
			else if (a[i][j] == 'X') {
				b[i][j] = -1;
			}
			else if (a[i][j] >= '1' && a[i][j] <= '9') {
				b[i][j] = a[i][j] - '0';
			}
			else {
				b[i][j] = 0;
			}
		}
	}


	int hp = 1; //쥐의 시작 체력
	int ans = 0; //

	while (true) {
		int dist, x, y; //먹은 치즈 까지 거리(시간), 먹은 치즈의 위치
		tie(dist, x, y) = bfs(b, sx, sy, hp);
		if (dist == -1) break; //치즈를 다 먹으면 break
		hp += 1; //쥐 체력 증가
		ans += dist; 
		b[x][y] = 0;
		sx = x;
		sy = y;
	}

	cout << ans << '\n';
	return 0;
}