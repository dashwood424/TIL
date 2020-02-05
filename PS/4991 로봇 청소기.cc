/*
더러운 칸의 개수는 10개를 넘지 않으며, 로봇 청소기의 개수는 항상 하나
10!가지 경우의 수
더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동횟수의 최솟값
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<vector<int>> bfs(vector<string> &a, int sx, int sy) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> dist(n, vector<int>(m, -1)); //(sx, sy)에서 모든 칸 까지의 거리

	queue<pair<int, int>> q;
	dist[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] != 'x' && dist[nx][ny] == -1) {
					//다음 칸이 가구가 없는 칸이고 방문한 적 없는 칸인 경우
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return dist;
}

int main() {
	while (true) {
		int n, m;
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		vector<string> a(n);
		vector<pair<int, int>> b(1); //더러운 칸의 위치 저장 -> 0번째에는 항상 청소기의 위치 -> 청소기 위치부터 시작

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'o') { //청소기인 경우
					b[0] = make_pair(i, j); 
				}
				else if (a[i][j] == '*') { //더러운 칸
					b.push_back(make_pair(i, j));
				}
			}
		}

		int ans = -1; //더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동횟수의 최솟값

		//더러운 칸 -> 더러운 칸 거리 구하기
		//d[i][j] = 더러운 칸 i에서 더러운 칸 j 까지 거리
		
		int l = b.size(); //청소기를 포함한 더러운 칸의 개수(서로 간의 거리를 구해야 하는 위치)
		vector<vector<int>> d(l, vector<int>(l));
		
		bool ok = true; //방문할 수 없는 칸이 존재하는 지
		//i번째 더러운 칸에서 j번째 더러운 칸의 거리가 -1인 경우 -> false

		for (int i = 0; i < l; i++) {
			vector<vector<int>> dist = bfs(a, b[i].first, b[i].second); //i번째 더러운 칸에서 모든 칸 까지의 거리

			for (int j = 0; j < l; j++) {
				d[i][j] = dist[b[j].first][b[j].second]; //j번 째 더러운 칸이 위치칸 곳 까지 거리
				if (d[i][j] == -1) {
					ok = false;
				}
			}
		}

		vector<int> p(l - 1); //청소기의 위치를 제외한 더러운 칸의 개수

		for (int i = 0; i < l - 1; i++) {
			p[i] = i + 1;
		}

		do {
			int temp = d[0][p[0]]; //청소기부터 첫 번째 방문하는 칸 까지의 거리
			
			for (int i = 0; i < l - 2; i++) {
				temp += d[p[i]][p[i + 1]];
			}
			if (ans == -1 || ans > temp) {
				ans = temp;
			}
		} while (next_permutation(p.begin(), p.end()));

		if (!ok) { //갈 수 없는 칸이 존재하는 경우
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}
	return 0;
}