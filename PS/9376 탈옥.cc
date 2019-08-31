#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<vector<int>> bfs(vector<string> &a, int sx, int sy) {
	int n = a.size();
	int m = a[0].size();

	vector<vector<int>> d(n, vector<int>(m, -1)); //시작점에서 (i, j)까지 문을 연 횟수
	deque<pair<int, int>> q;
	q.push_back(make_pair(sx, sy));
	d[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == '*') continue; //벽인 경우
				if (d[nx][ny] != -1) continue; //이미 방문한 경우
				
				if (a[nx][ny] == '#') { //문인 경우
					d[nx][ny] = d[x][y] + 1;
					q.push_back(make_pair(nx, ny));
				}
				else {
					d[nx][ny] = d[x][y];
					q.push_front(make_pair(nx, ny));
				}
			}
		}
	}
	return d;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n + 2);
		int x1, y1, x2, y2;
		x1 = y1 = x2 = y2 = -1;
		for (int i = 1; i < n + 1; i++) {
			cin >> a[i];
			a[i] = "." + a[i] + ".";
		}
		n += 2;
		m += 2;
		for (int j = 0; j < m; j++) {
			a[0] += ".";
			a[n - 1] += ".";
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '$') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}

		auto d = bfs(a, 0, 0); //밖에서부터 bfs -> 0,0에서 문을 여는 최소값
		auto d1 = bfs(a, x1, y1);
		auto d2 = bfs(a, x2, y2);

		int ans = 10000000;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '*') continue;
				int temp = d[i][j] + d1[i][j] + d2[i][j];
				if (a[i][j] == '#') {
					temp -= 2;
				}
				if (ans > temp) {
					ans = temp;
				}
			} 
		}
		cout << ans << '\n';
	}
	return 0;
}