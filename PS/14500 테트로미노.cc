#include <iostream>
using namespace std;

int a[500][500];
bool c[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int ans = 0;

//연속하는 네 칸으로 이루어진 블록 ㅗ, ㅜ, ㅏ, ㅓ 모양이 아닌 것
void go(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j]) {
					cout << a[i][j];
				}
				else {
					cout << ' ';
				}
			}
			cout << '\n';
		}
		cout << '\n';*/
		//cout << sum << '\n';
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	if (c[x][y]) return;
	if (x < 0 || x >= n || y < 0 || y >= m) return;

	for (int k = 0; k < 4; k++) {
		c[x][y] = true;
		go(x + dx[k], y + dy[k], cnt + 1, sum + a[x][y]);
		c[x][y] = false;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);

			if (i + 2 < n) { //ㅏ, ㅓ
				if (j + 1 < m) { 
					int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1];
					if (ans < temp) {
						ans = temp;
					}
				}
				if (j - 1 >= 0) {
					int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1];
					if (ans < temp) {
						ans = temp;
					}
				}
			}

			if (j + 2 < m) { //ㅗ, ㅜ
				if (i + 1 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1];
					if (ans < temp) {
						ans = temp;
					}
				}
				if (i - 1 >= 0) {
					int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1];
					if (ans < temp) {
						ans = temp;
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return  0;
}