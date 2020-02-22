#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int qdx[] = { 0, 0, 1,-1, -1, 1, 1, -1 };
int qdy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int a[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> q; //퀸의 위치

	for (int i = 0; i < 3; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x, y;

			if (i == 0) { 
				cin >> x >> y;
				a[x][y] = 1; //말인 경우
				q.push_back(make_pair(x, y));
			}
			else if (i == 1) { //나이트인 경우 
				cin >> x >> y;
				a[x][y] = 1;
				for (int k = 0; k < 8; k++) { //나이트는 중간에 장애물이 있더라고 이동할 수 있음
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
						if (a[nx][ny] == 1) continue;
						a[nx][ny] = 2; //말의 영역인 경우
					}
				}
			}
			else if (i == 2) { //폰
				cin >> x >> y;
				a[x][y] = 1;
			}
		}
	}

	for (int i = 0; i < q.size(); i++) {
		int x, y;
		x = q[i].first;
		y = q[i].second;

		for (int k = 0; k < 8; k++) {
			int nx = x + qdx[k];
			int ny = y + qdy[k];

			while (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
				if (a[nx][ny] == 1) {
					break;
				}
				a[nx][ny] = 2;
				nx += qdx[k];
				ny += qdy[k];
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0) {
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}