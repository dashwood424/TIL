/*
인구이동이 없을 때까지 연합을 이루고 국경선을 열기

인구이동
-> 국경선을 공유하는 두 나라의 인구 차이가 l명 이상 r명 이하라면 두 나라가 공유하는 국경선을 연다
-> 국경선이 모두 열렸다면 인구 이동 시작
-> 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 연합이라 함
-> 연합을 이루는 각 칸의 인구수=(연합의 인구수)/(연합을 이루는 나라의 수)
-> 연합을 해체하고 국경선 닫음

인구 이동이 몇번 발생하는지
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[51][51];

bool bfs() {
	vector<vector<bool>> check(n, vector<bool>(n));
	bool ok = false; //인구이동이 발생하면 true

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { //(i, j)칸에서부터 연합을 이룰수 있는 나라를 찾아감
			if (check[i][j] == false) {
				queue<pair<int, int>> q;
				vector<pair<int, int>> u; //연합을 이루는 나라의 위치
				
				check[i][j] = true;
				q.push(make_pair(i, j));
				u.push_back(make_pair(i, j));
				int sum = a[i][j];
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; //범위를 벗어나는 경우
						if (check[nx][ny]) continue; //이미 연합을 이루는 경우
						int diff = a[x][y] - a[nx][ny];
						if (diff < 0) diff = -diff;
						if (diff >= l && diff <= r) { //인구 차이가 l이상 r이하
							ok = true; //인구이동이 가능
							q.push(make_pair(nx, ny));
							check[nx][ny] = true;
							u.push_back(make_pair(nx, ny)); //연합을 이루는 나라의 좌표
							sum += a[nx][ny];
						}
					}
				}

				if (ok) { //인구이동이 가능하면
					int u_sum = sum / u.size();

					for (int t = 0; t < u.size(); t++) {
						int x = u[t].first;
						int y = u[t].second;
						a[x][y] = u_sum;
					}
				}
			}
		}
	}
	return ok;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0; //인구이동이 발생한 횟수

	while (true) {
		if (bfs()) { //인구이동이 발생하면
			ans += 1;
		}
		else {
			break;
		}
	}

	cout << ans << '\n';
	
	return 0;
}