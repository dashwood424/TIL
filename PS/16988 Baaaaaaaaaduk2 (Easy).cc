#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[20][20];
bool check[20][20];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs() {
	memset(check, false, sizeof(check));

	int ans = 0; //죽일 수 있는 상대 돌의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2 && check[i][j] == false) { //상대방 돌이고 방문한 적이 없으면
				queue<pair<int, int>> q;
				check[i][j] = true;
				q.push(make_pair(i, j));

				int cnt = 0; //인접한 칸이 빈칸이 아닌 상대방 돌의 개수 -> 죽는 상대방 돌의 개수
				bool ok = true; //인접한 칸에 빈칸이 없으면 true
				
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					cnt += 1;

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						
						if (0 <= nx && nx < n && 0 <= ny && ny < m) {
							if (a[nx][ny] == 2 && check[nx][ny] == false) { //인접한 칸이 상대방 돌
								check[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
							else if (a[nx][ny]==0) { //인접한 칸이 빈칸인 경우
								ok = false;
							}
						}
					}
				}

				if (ok) { //현재 상대 돌에서 인접한 칸이 빈칸이 아닌 경우
					ans += cnt;
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0; //죽일 수 있는 상대 돌의 최대 개수

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) { //내 돌1
			if (a[x1][y1] != 0) continue; //빈칸이 아닌 경우
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) { //내 돌2
					if (a[x2][y2] != 0) continue; //빈칸이 아닌 경우
					if (x1 == x2 && y1 == y2) continue; //내 돌1이랑 같은 위치에 놓은 경우
					a[x1][y1] = 1;
					a[x2][y2] = 1;

					int cur = bfs(); //현재 죽일 수 있는 상대돌의 개수

					if (ans < cur) {
						ans = cur;
					}

					a[x1][y1] = 0;
					a[x2][y2] = 0;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}