#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

string a[1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m;
	cin >> n >> m;

	int ex, ey; //원준이 위치

	vector<vector<int>> d(n, vector<int>(m, -1)); //불이 번지는 시간, -1로 초기화
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '@') {
				q.push(make_pair(i, j)); //불이면 큐에 넣음
				d[i][j] = 0;
			}
			else if (a[i][j] == '&') {
				ex = i;
				ey = j;
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

			if (0 <= nx && nx < n && 0 <= ny && ny < m) { //범위 안에서만 움직임
				if (d[nx][ny] == -1 && a[nx][ny] != '#') { //한번도 방문하지 않았고 벽이 아니라면 불이 번지는 시간 계산
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if (d[ex][ey] == -1) {
		cout << -1 << '\n';
	}
	else {
		cout << d[ex][ey] - 1 << '\n';
	}
	return 0;
}