#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ice[301][301];
int check[301][301];

void bfs(int sx, int sy) {
	check[sx][sy] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (ice[nx][ny] != 0 && check[nx][ny] == 0) {
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}

	int year = 0; //년 도
	
	while (true) {
		memset(check, 0, sizeof(check));
		int cnt = 0; //빙산의 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] != 0 && check[i][j] == 0) {
					bfs(i, j);
					cnt += 1;
				}
			}
		}

		if (cnt == 0) { //빙산이 없으면
			cout << 0 << '\n';
			break;
		}
		else if (cnt >= 2) {
			cout << year << '\n';
			break;
		}

		vector<vector<int>> near(n, vector<int>(m)); //각 칸에서 인접한 바다의 개수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] == 0) continue;
				int sea = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if (0 <= nx && nx < n && 0 <= ny && ny < m) {
						if (ice[nx][ny] == 0) {
							sea += 1;
						}
					}
					near[i][j] = sea;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ice[i][j] -= near[i][j];
				if (ice[i][j] < 0) {
					ice[i][j] = 0;
				}
			}
		}
		year += 1;
	}
	return 0;
}