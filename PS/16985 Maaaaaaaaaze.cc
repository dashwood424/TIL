#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;

int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };
int d[5][5][5];

int bfs(vector<vector<vector<int>>> &a) {
	if (a[0][0][0] != 1) return -1; //시작 칸을 방문할 수 없는 경우

	memset(d, -1, sizeof(d));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	d[0][0][0] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nz = z + dz[k];

			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5) {
				if (a[nx][ny][nz] == 1 && d[nx][ny][nz] == -1) {
					d[nx][ny][nz] = d[x][y][z] + 1;
					q.push(make_tuple(nx, ny, nz));
				}
			}
		}
	}

	return d[4][4][4];
}

vector<vector<int>> clockwise(vector<vector<int>> &a) { //시계방향으로 회전시키기
	vector<vector<int>> b(5, vector<int>(5));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			b[i][j] = a[5 - j - 1][i];
		}
	}

	return b;
}

int main() {
	vector<vector<vector<int>>> a(5);
	for (int k = 0; k < 5; k++) {
		a[k].resize(5, vector<int>(5));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> a[k][i][j];
			}
		}
	}

	vector<int> order; //판을 쌓는 순서
	for (int i = 0; i < 5; i++) {
		order.push_back(i);
	}

	int ans = -1; //최소 이동 횟수

	do {
		vector<vector<vector<int>>> b(5);
		for (int i = 0; i < 5; i++) { //미로판을 섞어가면서
			b[i] = a[order[i]];
		}

		for (int rot1 = 0; rot1 < 4; rot1++) { //첫 번째 미로 네 방향으로 회전시키기
			for (int rot2 = 0; rot2 < 4; rot2++) {
				for (int rot3 = 0; rot3 < 4; rot3++) {
					for (int rot4 = 0; rot4 < 4; rot4++) {
						for (int rot5 = 0; rot5 < 4; rot5++) {
							int cur = bfs(b);

							if (cur != -1) {
								if (ans == -1 || cur < ans) {
									ans = cur;
								}
							}
							b[4] = clockwise(b[4]);
						}
						b[3] = clockwise(b[3]);
					}
					b[2] = clockwise(b[2]);
				}
				b[1] = clockwise(b[1]);
			}
			b[0] = clockwise(b[0]);
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << ans << '\n';

	return 0;
}