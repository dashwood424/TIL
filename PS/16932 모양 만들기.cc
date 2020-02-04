/*
0인 칸을 1로 바꿔서 인접한 칸에 1로 이루어진 그룹이 있는지
0과 인접한 그룹의 크기+1 가 최대인지
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001][1001]; 
int group[1001][1001]; //모양 표시
int group_size[1000 * 1000]; //n번째 그룹의 크기
int groupn = 0; //그룹의 개수
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void bfs(int sx, int sy) {
	groupn += 1;
	int cnt = 0;
	queue<pair<int, int>> q;
	group[sx][sy] = groupn; //그룹 번호로 표시
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt += 1;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 1 && group[nx][ny] == 0) {
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
			cin >> a[i][j];
		}
	}

	int ans = -1; //수 하나를 변경해서 만들 수 있는 모양의 최대 크기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && group[i][j] == 0) { //모양을 만들 수 있는데 아직 그룹지어지지 않은 경우
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vector<int> temp; //인접한 칸 임시로 저장
			if (a[i][j] == 0) { //0인 칸과
				for (int k = 0; k < 4; k++) { //인접한 칸이  
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (a[nx][ny] != 0) { //0이 아니면
						temp.push_back(group[nx][ny]); //1이 속한 그룹번호 벡터에 넣어두기
					}
				}
				sort(temp.begin(), temp.end());
				temp.erase(unique(temp.begin(), temp.end()), temp.end()); //중복 제거
				
				int cur = 1; //현재 0인 칸의 넓이
				for (int near : temp) {
					cur += group_size[near];
				}

				if (ans < cur) {
					ans = cur;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}