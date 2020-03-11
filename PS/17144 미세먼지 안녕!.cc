#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n, m, t;
	cin >> n >> m >> t;

	vector<vector<int>> a(n, vector<int>(m));
	int mx1, my1, mx2, my2;
	mx1 = my1 = mx2 = my2 = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				if (mx1 == -1) {
					mx1 = i;
					my1 = j;
				}
				else {
					mx2 = i;
					my2 = j;
				}
			}
		}
	}

	while (t--) {
		//1. 미세먼지 확산

		vector<vector<int>> b(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] > 0) { //미세먼지가 있는 칸인 경우
					int cnt = 0; //확산이 일어날 수 있는 칸의 개수

					for (int k = 0; k < 4; k++) {
						int x = i + dx[k];
						int y = j + dy[k];

						if (0 <= x && x < n && 0 <= y && y < m) { //범위 안에 있는 칸이고
							if (a[x][y] != -1) { //공기청정기가 있는 칸이 아닌 경우
								cnt += 1;
							}
						}
					}

					int dust = a[i][j] / 5; //확산이 일어나는 먼지의 양


					for (int k = 0; k < 4; k++) { //현재 칸(i, j)에서 확산이 일어날 수 있는 칸으로 확산
						int x = i + dx[k];
						int y = j + dy[k];

						if (0 <= x && x < n && 0 <= y && y < m) {
							if (a[x][y] != -1) {
								b[x][y] += dust;
							}
						}
					}
					b[i][j] += a[i][j] - dust*cnt;
				}
			}
		}
		a = b;

		//2. 공기청정기 작동
		//공기 청정기는 항상 1번열에 위치함

		vector<int> upper;
		for (int j = my1; j < m; j++) {
			upper.push_back(a[mx1][j]);
		}
		for (int i = mx1 - 1; i >= 0; i--) {
			upper.push_back(a[i][m - 1]);
		}
		for (int j = m - 2; j >= 0; j--) {
			upper.push_back(a[0][j]);
		}
		for (int i = 1; i < mx1; i++) {
			upper.push_back(a[i][0]);
		}
		for (int i = upper.size() - 1; i > 0; i--) {
			upper[i] = upper[i - 1];
		}
		upper[0] = 0; //바람이 나오는 위치 -> 미세먼지가 없는 바람

		int index = 0;
		for (int j = my1; j < m; j++) {
			a[mx1][j] = upper[index++];
		}
		for (int i = mx1 - 1; i >= 0; i--) {
			a[i][m - 1] = upper[index++];
		}
		for (int j = m - 2; j >= 0; j--) {
			a[0][j] = upper[index++];
		}
		for (int i = 1; i < mx1; i++) {
			a[i][0] = upper[index++];
		}
		a[mx1][my1] = -1;

		vector<int> lower;
		for (int j = my2 + 1; j < m; j++) {
			lower.push_back(a[mx2][j]);
		}
		for (int i = mx2 + 1; i < n; i++) {
			lower.push_back(a[i][m - 1]);
		}
		for (int j = m - 2; j >= 0; j--) {
			lower.push_back(a[n - 1][j]);
		}
		for (int i = n - 2; i >= mx2; i--) {
			lower.push_back(a[i][0]);
		}
		for (int i = lower.size() - 1; i > 0; i--) {
			lower[i] = lower[i - 1];
		}
		lower[0] = 0;
		index = 0;
		for (int j = my2 + 1; j < m; j++) {
			a[mx2][j] = lower[index++];
		}
		for (int i = mx2 + 1; i < n; i++) {
			a[i][m - 1] = lower[index++];
		}
		for (int j = m - 2; j >= 0; j--) {
			a[n - 1][j] = lower[index++];
		}
		for (int i = n - 2; i >= mx2; i--) {
			a[i][0] = lower[index++];
		}
		a[mx2][my2] = -1;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0) {
				ans += a[i][j];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}