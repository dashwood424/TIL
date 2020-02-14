#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

bool check(bool rgb, char cur, char next) { //rgb=true 이면 적록색약
	if (rgb) {
		if (cur == 'R' && next == 'B') {
			return false;
		}
		else if (cur == 'G' && next == 'B') {
			return false;
		}
		else if (cur == 'B' && next == 'R') {
			return false;
		}
		else if (cur == 'B' && next == 'G') {
			return false;
		}
	}
	else {
		if (cur != next) {
			return false;
		}
	}
	return true;
}

int bfs(vector<string> &a, bool rgb) { //적록색약인지 아닌지
	int cnt = 0; //구역의 개수

	vector<vector<bool>> c(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == false) { //방문하지 않은 칸이라면
				cnt += 1; //bfs시작
				
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				c[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							if (c[nx][ny]) continue;
							if (check(rgb, a[x][y], a[nx][ny])) { //다음 칸을 방문할 수 있는지 없는지
								c[nx][ny] = true; //
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n;
	vector<string> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	cout << bfs(a, false) << ' ' << bfs(a, true) << '\n';

	return 0;
}