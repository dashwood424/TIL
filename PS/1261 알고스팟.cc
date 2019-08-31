#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[100][100];
int d[100][100]; //벽을 부순 횟수

int main() {
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	memset(d, -1, sizeof(d));
	deque<pair<int, int>> q;
	d[0][0] = 0;
	q.push_back(make_pair(0, 0));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) { //다음 칸이 빈칸이고 방문하지 않은 경우
					d[nx][ny] = d[x][y];
					q.push_front(make_pair(nx, ny)); 
				}
				else if (a[nx][ny] == 1 && d[nx][ny] == -1) { //다음 칸이 벽인경우
					d[nx][ny] = d[x][y] + 1; //벽을 부순 횟수 증가
					q.push_back(make_pair(nx, ny));
				}
			}
		}
	}
	cout << d[n - 1][m - 1] << '\n';
	return 0;
}