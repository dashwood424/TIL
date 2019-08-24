#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
bool check[101][101];

void bfs(vector<vector<int>> &b, int sx, int sy) {
	queue<pair<int, int>> q;
	check[sx][sy] = true;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (b[nx][ny]!=-1 && check[nx][ny]==false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	
	int ans = 1;
	for (int i = 1; i <= 100; i++) { //강수량 1부터
		vector<vector<int>> b(a);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (b[j][k] <= i) {
					b[j][k] = -1; //물에 잠긴 지역이면 -1
				}
			}
		}
	
		int cnt = 0;
		memset(check, false, sizeof(check));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (b[j][k]!=-1 && check[j][k]==false) {
					//이미 방문한 지역이 아니고 물에 잠기지 않은 곳에서 부터 인접한 영역 탐색
					bfs(b, j, k);
					cnt++;
				}
			}
		}

		if (ans < cnt) {
			ans = cnt;
		}
	}
	cout << ans << '\n';
	return 0;
}