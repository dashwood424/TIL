/*
2: 바이러스를 놓을 수 있는 칸 m: 바이러스를 놓을 수 있는 칸 중 m개를 고름
모든 빈 칸에 바이러스를 퍼뜨리는 최소시간 구하기
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int a[50][50];
int d[50][50]; //바이러스가 퍼지는 최소 시간
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int ans = -1;

void bfs() {
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 3) { //바이러스가 놓인 위치라면
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] != 1 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	int cur = 0;
	bool ok = true; //벽이 아닌데 방문할 수 없는 경우 false

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) { //빈칸일 때만 조사
				if (d[i][j] == -1) {
					ok = false;
				}
				if (cur < d[i][j]) {
					cur = d[i][j];
				}
			}
		}
	}

	if (ok) { //참일때만 최소 시간 구함
		if (ans == -1 || cur < ans) {
			ans = cur;
		}
	}
}

void go(vector<pair<int, int>> &v, int index, int cnt) {
	//index번째 바이러스를 선택할지 말지
	if (index == v.size()) {
		if (cnt == m) {
			bfs();
		}
	}
	else {
		int x = v[index].first;
		int y = v[index].second;
		a[x][y] = 3; //활성 바이러스로 만듦
		go(v, index + 1, cnt + 1);
		a[x][y] = 2; //비활성 바이러스
		go(v, index + 1, cnt);
	}
}

int main() {
	cin >> n >> m;
	vector<pair<int, int>> v; //바이러스를 놓을 수 있는 칸의 위치

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	go(v, 0, 0);

	cout << ans << '\n';

	return 0;
}