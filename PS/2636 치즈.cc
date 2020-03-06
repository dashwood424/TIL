#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool e[101][101];
int a[101][101];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> res; //시간, 치즈 면적
	int t = 0; //시간

	queue<pair<int, int>> q;
	queue<pair<int, int>> nq; //다음 턴에 녹는 치즈 -> 다음 칸에 빈 칸인 곳
	e[0][0] = true;
	q.push(make_pair(0, 0));

	while (true) {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			a[x][y] = 0;

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					if (a[nx][ny] == 0 && e[nx][ny] == false) {
						e[nx][ny] = true;
						q.push(make_pair(nx, ny));
					}
					else if (a[nx][ny] == 1) {
						nq.push(make_pair(nx, ny));
					}
				}
			}
		}
		q = nq;
		nq = queue<pair<int, int>>();

		int cnt = 0;
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					cnt += 1;
				}
			}
		}

		res.push_back(cnt);


		if (cnt == 0) {
			break;
		}
		t += 1;
	}

	cout << t << '\n';
	cout << res[t - 1] << '\n';

	return 0;
}