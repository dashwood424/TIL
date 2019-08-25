#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[10000]; //i번째 영역의 넓이
int n, m;
bool check[101][101];

int bfs(vector<vector<int>> &a, int sx, int sy) {
	queue<pair<int, int>> q;
	check[sx][sy] = true;
	q.push(make_pair(sx, sy));
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
				if (a[nx][ny] != -1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}

int main() {
	int l;
	cin >> m >> n >> l;
	vector<vector<int>> a(n, vector<int>(m, 0));
	while (l--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				a[i][j] = -1; //사각형인 부분이면 -1
			}
		}
	}

	int area = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1 && check[i][j] == false) {
				area += 1;
				d[area] = bfs(a, i, j);
			}
		}
	}

	cout << area << '\n';
	sort(d, d + area + 1);
	for (int i = 1; i <= area; i++) {
		cout << d[i] << ' ';
	}
	cout << '\n';
	return 0;
}