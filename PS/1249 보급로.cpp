#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[101][101]; //지도
int d[101][101];  //출발지에서 도착지까지 가는 복구시간이 최소로 걸리는 경로의 복구시간

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%1d", &a[i][j]);
			}
		}

		memset(d, -1, sizeof(d));
		queue<pair<int, int> > q;
		d[0][0] = 0;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (d[nx][ny] == -1 || d[nx][ny] > d[x][y] + a[nx][ny]) {
						d[nx][ny] = d[x][y] + a[nx][ny];
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << '#' << test_case << ' ' << d[n - 1][n - 1] << '\n';
	}
	return 0;
}