/*
1. 성에 있는 방의 개수 -> 같은 방임을 표시
2. 가장 넓은 방의 넓이 -> 방의 크기 -> 방문한 개수
3. 하나의 벽을 제거해서 얻을 수 있는 가장 넓은 방의 크기
-> 서로 다른 방이어야 함, 벽이 존재해야 함
*/

#include <iostream>
#include <queue>
using namespace std;

int a[50][50];
int room[50][50]; //방 번호 표시
int room_size[50 * 50]; //n번째 방의 넓이 
int roomn = 0; //방 번호 -> 성에 있는 방의 개수
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int n, m;

void bfs(int sx, int sy) {
	roomn += 1;
	queue<pair<int, int>> q;
	room[sx][sy] = roomn;
	q.push(make_pair(sx, sy));
	int cnt = 0; //방의 크기

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) { //범위 안에 있고
				if (room[nx][ny] != -1) continue; //방문한 적이 있는 경우
				if ((a[x][y] & (1 << k)) > 0) continue; //a[x][y]의 k번 방향에 벽이 있음
				room[nx][ny] = roomn; //k번 방향에 벽이 없는 경우 다음 칸 방문
				q.push(make_pair(nx, ny));
			}
		}
	}

	room_size[roomn] = cnt;
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			room[i][j] = -1; //방문하지 않은 칸
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (room[i][j] == -1) {
				bfs(i, j);
			}
		}
	}

	cout << roomn << '\n'; //1. 방의 개수

	int ans = 0;

	for (int i = 1; i <= roomn; i++) {
		if (ans < room_size[i]) {
			ans = room_size[i];
		}
	}

	cout << ans << '\n'; //2. 가장 넓은 방의 넓이

	ans = 0;

	//현재 칸과 인접한 칸이 다른 방이고 벽이 존재함
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (x < 0 || x >= n || y < 0 || y >= m) continue;
				if (room[i][j] != room[x][y] && (a[i][j] & (1 << k)) > 0) { //현재 방에서 k번 방향으로 벽이 존재하면
					if (ans < room_size[room[i][j]] + room_size[room[x][y]]) {
						ans = room_size[room[i][j]] + room_size[room[x][y]];
					}
				}
			}
		}
	}

	cout << ans << '\n';


	return 0;
}