#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int a[103][103];
bool check[103][103];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs(int sx, int sy) {
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	check[sx][sy] = true;
	q.push(make_pair(sx, sy));

	int dist = 0;
	int num = a[sx][sy];

	while (int size = q.size()) {
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (a[nx][ny] != 0 && a[nx][ny] != num) return dist;
					if (a[nx][ny] == 0 && check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		dist += 1;
	}

	return dist;
}

bool possible(int x, int y) {
	bool ok = false;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (a[nx][ny] == 0) {
				ok = true;
			}
		}
	}

	return ok;
}

void dfs(int x, int y, int num) {
	check[x][y] = true;
	a[x][y] = num;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (a[nx][ny] == 1 && check[nx][ny] == false) {
				dfs(nx, ny, num);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && check[i][j] == false) {
				dfs(i, j, ++num);
			}
		}
	}


	int ans = -1; //가장 짧은 다리의 길이

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0 && possible(i, j)) { //인접한 칸이 바다인 곳에서부터 다른 섬 까지의 거리 구하기
				int cur = bfs(i, j);
				if (ans == -1 || ans > cur) {
					ans = cur;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}