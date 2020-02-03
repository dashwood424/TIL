#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[500][500];

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool ok = true; //인접한 칸에 늑대가 있으면 false
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			queue<pair<int, int>> q;
			if (a[i][j] == 'S' && check[i][j] == false) {
				check[i][j] = true;
				q.push(make_pair(i, j));
				
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (0 <= nx && nx < n && 0 <= ny && ny < m) {
							if (a[nx][ny] == 'S' && check[nx][ny] == false) {
								check[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
							else if (a[nx][ny] == 'W') { //인접한 칸이 늑대인 경우
								ok = false;
							}
						}
					}
				}
			}
		}
	}

	if (!ok) { //인접한 칸에 늑대가 있는 경우
		cout << 0 << '\n';
		return 0;
	}
	else {
		cout << 1 << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '.') {
					a[i][j] = 'D';
				}
				cout << a[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}