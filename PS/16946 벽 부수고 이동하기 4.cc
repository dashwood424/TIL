#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int a[1001][1001];
int group[1001][1001]; //그룹 번호 표시
int group_size[1000 * 1000]; //그룹 i의 크기
int groupn = 0; //그룹 번호
void bfs(int sx, int sy) {
	groupn += 1;
	queue<pair<int, int>> q;
	group[sx][sy] = groupn;
	q.push(make_pair(sx, sy));

	int cnt = 0; //그룹의 크기

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && group[nx][ny] == 0) {
					group[nx][ny] = groupn;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	group_size[groupn] = cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	//빈 칸인 곳 탐색하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && group[i][j] == 0) { //빈 칸 인곳 그룹번호 표시하기
				bfs(i, j);
			}
		}
	}

	vector<vector<int>> ans(n, vector<int>(m)); //정답 출력할 벡터
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) { //벽이면
				vector<int> near; //벽과 인접한 칸의 그룹 번호
				for (int k = 0; k < 4; k++) { //벽과 인접한 칸
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위를 벗어나는 경우
					if (group[nx][ny] == 0) continue; //인접한 칸이 그룹지어진 칸이 아닌 경우 -> 빈칸이 아닌 경우
					near.push_back(group[nx][ny]);
				}
				sort(near.begin(), near.end());
				near.erase(unique(near.begin(), near.end()), near.end());

				int temp = 1; //벽인 칸을 빈칸으로 바꿨을 때 인접한 그룹의 넓이 -> 현재칸에서 갈수 있는 칸의 개수
				//현재 벽인 칸도 포함해야 함
				for (int n : near) {
					temp += group_size[n];
				}
				ans[i][j] = temp % 10; //갈 수 있는 칸을 10으로 나눈 나머지
			}
			else { //원래 빈 칸인 곳은 0
				ans[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}