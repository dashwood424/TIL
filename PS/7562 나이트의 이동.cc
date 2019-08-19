#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> d(n, vector<int>(n, -1)); //-1이면 아직 가지 않은 칸
		queue<pair<int, int>> q;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		
		d[sx][sy] = 0;
		q.push(make_pair(sx, sy));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (d[nx][ny] == -1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << d[ex][ey] << '\n';
	}
	return 0;
}