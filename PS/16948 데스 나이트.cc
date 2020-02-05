#include <iostream>
#include <queue>
using namespace std;

int d[201][201];
int dx[] = { -2,-2,0,0,2,2 };
int dy[] = { -1,1,-2,2,-1,1 };

int main() {
	int n; //체스판의 크기
	cin >> n;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = -1;
		}
	}

	queue<pair<int, int>> q;
	d[x1][y1] = 0;
	q.push(make_pair(x1, y1));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 6; k++) {
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

	cout << d[x2][y2] << '\n';

	return 0;
}