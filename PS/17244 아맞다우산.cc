#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int n, m;

vector<vector<int>> bfs(vector<string> &a, int sx, int sy) {
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	dist[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == '#') continue;
				if (dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return dist;
}

int main() {
	cin >> m >> n;
	vector<string> a(n);
	vector<pair<int, int>> v(1); //방문할 물건들의 위치와 시작, 끝 정점
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') { //시작점은 항상 첫 번째 정점
				v[0] = make_pair(i, j);
			}
			else if (a[i][j] == 'X') {
				v.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'E') { //항상 마지막에 넣기
				v.push_back(make_pair(i, j));
			}
		}
	}

	int l = v.size(); //정점의 개수

	vector<vector<int>> d(l, vector<int>(l)); //정점 i에서 j로 가는 거리

	for (int i = 0; i < l; i++) {
		int sx = v[i].first;
		int sy = v[i].second;

		vector<vector<int>> dist = bfs(a, sx, sy);

		for (int j = 0; j < l; j++) {
			if (i == j) continue;
			d[i][j] = dist[v[j].first][v[j].second];
		}
	}

	if (v.size() == 2) { //챙길 물건이 없는 경우
		cout << d[0][1] << '\n';

		return 0;
	}

	vector<int> p;
	for (int i = 1; i <= l - 2; i++) {
		p.push_back(i);
	}

	int ans = -1; //S에서 출발하여 모든 물건을 챙겨서 E까지 도착할 수 있는 최소 시간
	
	do {
		int temp = d[0][p[0]];
		for (int i = 0; i < p.size() - 1; i++) {
			temp += d[p[i]][p[i + 1]];
		}
		temp += d[p[p.size() - 1]][l - 1]; //도착점 위치까지 거리

		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << ans << '\n';

	return 0;
}