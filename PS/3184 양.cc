#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[250 * 250][2]; //각각의 영역에 0: 양, 1: 늑대 의 수
bool c[250][250]; //방문한 칸 체크
string a[250];
int n, m;

void bfs(int sx, int sy, int cnt) {
	queue<pair<int, int> > q;
	c[sx][sy] = true;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		if (a[x][y] == 'o') {
			d[cnt][0] += 1; //양이면 양의 수 증가
		}
		else if (a[x][y] == 'v') {
			d[cnt][1] += 1; //늑대이면 늑대의 수 증가
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) { //범위 안에 있음
				if (c[nx][ny] == false && a[nx][ny] != '#') { //방문하지 않은 칸이고 벽이 아니면
					q.push(make_pair(nx, ny));
					c[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int cnt = 0; //영역의 개수
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cnt += 1;
			if (c[i][j] == false && a[i][j] != '#') {
				bfs(i, j, cnt);
			}
		}
	}

	int o = 0;
	int v = 0;
	
	for (int i = 0; i <= cnt; i++) {
		if (d[i][1] >= d[i][0]) { //늑대의 수가 양과 같거나 크면
			v += d[i][1]; //i번째 영역에서는 늑대의 수만
		}
		else {
			o += d[i][0]; //양의 수
		}
	}
	cout << o << ' ' << v << '\n';
	return 0;
}