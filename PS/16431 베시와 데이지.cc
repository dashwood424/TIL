#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int b[1001][1001]; //베시
int d[1001][1001]; //데이지
int dx1[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy1[] = { -1, 0, 1, 1, 1, 0, -1, -1 }; //베시 이동
int dx2[] = { 0,0,1,-1 };
int dy2[] = { 1,-1,0,0 };

int main() {
	int x1, y1, x2, y2, ex, ey;
	cin >> x1 >> y1 >> x2 >> y2 >> ex >> ey;

	memset(b, -1, sizeof(b));
	queue<pair<int, int>> q;
	q.push(make_pair(x1, y1));
	b[x1][y1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
	
		for (int k = 0; k < 8; k++) {
			int nx = x + dx1[k];
			int ny = y + dy1[k];

			if (1 <= nx && nx <= 1000 && 1 <= ny && ny <= 1000) {
				if (b[nx][ny] == -1) {
					b[nx][ny] = b[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	memset(d, -1, sizeof(d));
	q.push(make_pair(x2, y2));
	d[x2][y2] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx2[k];
			int ny = y + dy2[k];

			if (1 <= nx && nx <= 1000 && 1 <= ny && ny <= 1000) {
				if (d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}

	}

	if (b[ex][ey] < d[ex][ey]) {
		cout << "bessie" << '\n';
	}
	else if (d[ex][ey] < b[ex][ey]) {
		cout << "daisy" << '\n';
	}
	else if (b[ex][ey] == d[ex][ey]) {
		cout << "tie" << '\n';
	}

	return 0;
}