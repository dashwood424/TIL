#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int a[25][25];
int d_size[25 * 25]; //단지 크기
int d[25][25]; //단지 번호 표시
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

void bfs(int sx, int sy, int num) {
	int cnt = 0; //단지 크기
	
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	d[sx][sy] = num;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					d[nx][ny] = num;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	d_size[num] = cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int num = 0; //단지 번호

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j, ++num);
			}
		}
	}

	cout << num << '\n';
	sort(d_size + 1, d_size + num + 1);
	for (int i = 1; i <= num; i++) {
		cout << d_size[i] << '\n';
	}

	return 0;
}