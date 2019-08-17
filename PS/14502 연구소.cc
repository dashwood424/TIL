#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[10][10];
int b[10][10];
int n, m;

int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
			if (a[i][j] == 2) { //모든 바이러스의 위치에서부터 bfs
				q.push(make_pair(i, j));
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

			if (0 <= nx && nx < n && 0 <= ny && ny < m) { //범위 안에 있고
				if (b[nx][ny] == 0) { //다음칸이 빈칸인 경우에만
					b[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	int ans = 0; //안전 영역의 최대 크기

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (a[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (a[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < m; y3++) {
							if (a[x3][y3] != 0) continue;
							
							if (x1 == x2 && y1 == y2) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;

							a[x1][y1] = 1;
							a[x2][y2] = 1;
							a[x3][y3] = 1; //세 곳에 일단 벽을 놓음

							int cur = bfs(); //현재 안전 영역의 개수
							if (ans < cur) {
								ans = cur;
							}

							a[x1][y1] = 0;
							a[x2][y2] = 0;
							a[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}