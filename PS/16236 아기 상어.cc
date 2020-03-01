/*
아기 상어가 몇 초 동안 엄마상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지

자신의 크기보다 큰 물고기가 있는 칸 -> 지나갈수 없음
자신의 크기보다 작은 물고기 -> 먹을 수 있음

먹을 수 있는 물고기가 1마리보다 많다면 거리가 가장 가까운 물고기를 먹으러 감
-> 현재 상태(크기)에서 먹을 수 있는 물고기 벡터 만들기(물고기까지 거리(시간), 위치)
-> 정렬

물고기를 먹으면 그 칸은 빈 칸이 됨

자신의 크기와 같은 수의 물고기를 먹을 때마다 크기가 1증가
-> 크기가 2인 아기 상어는 물고리를 2마리 먹으면 크기가 3이됨
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[21][21]; //공간의 상태
int n;

tuple<int, int, int> bfs(int size, int sx, int sy) {
	vector<vector<int>> d(n, vector<int>(n, -1)); //물고기까지 거리
	vector<tuple<int, int, int>> ans; //물고기까지 거리, 위치
	queue<pair<int, int>> q;
	d[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	bool pass = false; //지나갈 수 있는지
	bool eat = false; //먹을 수 있는지

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] <= size && d[nx][ny] == -1) { //작거나 같으면 지나갈 수 있음
					pass = true; //지나갈 수 있음
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;

					if (pass) {
						if (a[nx][ny] < size && a[nx][ny] != 0) {
							eat = true; //먹을 수 있음
							ans.push_back(make_tuple(d[nx][ny], nx, ny));
						}	
					}
				}
			}
		}
	}

	if (eat) {
		sort(ans.begin(), ans.end());
	}
	else {
		return make_tuple(-1, -1, -1);
	}

	return ans[0];
}

int main() {
	cin >> n;
	int sx, sy; //아기상어의 시작 위치
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				sx = i;
				sy = j;
				a[i][j] = 0;
			}
		}
	}

	int ans = 0; //먹을 수 있는 물고기를 다 먹었을 때 시간
	int size = 2; //아기상어의 크기
	int cnt = 0; //아기상어가 먹은 물고기의 수

	while (true) {
		int dist, x, y; //잡아먹는 물고기 까지 거리
		tie(dist, x, y) = bfs(size, sx, sy);
		if (dist == -1) break; //먹을 수 있는 물고기가 없으면 종료
		sx = x;
		sy = y; //잡아먹은 물고기의 위치부터 다시 시작
		a[x][y] = 0; //물고기를 먹은 칸은 빈 칸
		ans += dist;
		cnt += 1;
		if (cnt == size) { //자신의 크기와 같은 수의 물고기를 먹으면 크기가 1 증가
			size += 1;
			cnt = 0;
		}
	}

	cout << ans << '\n';

	return 0;
}