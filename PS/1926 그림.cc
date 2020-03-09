#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[501][501];
int d[501][501];
vector<int> p_size;
int n, m;

void bfs(int sx, int sy, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	d[sx][sy] = num;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && d[nx][ny] == -1) {
					d[nx][ny] = num;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	p_size.push_back(cnt);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int num = 0;
	memset(d, -1, sizeof(d));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && d[i][j] == -1) {
				bfs(i, j, ++num);
			}
		}
	}

	int max_size = 0;
	for (int i = 0; i < num; i++) {
		if (max_size < p_size[i]) {
			max_size = p_size[i];
		}
	}
	cout << num << '\n';
	cout << max_size << '\n';

	return 0;
}