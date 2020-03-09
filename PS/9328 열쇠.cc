#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool key[26]; //키가 있으면 true
bool check[104][104];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n + 2);
		for (int i = 1; i < n + 1; i++) { //상근이가 건물 밖으로 나갈 수 있기 때문에 건물을 이동할 수 있는 빈칸으로 둘러쌓아준다
			string str;
			cin >> str;
			a[i] = "." + str + ".";
		}

		n += 2;
		m += 2;
		for (int j = 0; j < m; j++) {
			a[0] += ".";
			a[n - 1] += ".";
		}

		memset(key, false, sizeof(key));
		string k;
		cin >> k;
		for (int i = 0; i < k.length(); i++) {
			if (k[0] == 0) {
				break;
			}
			key[k[i] - 'a'] = true;
		}

		int ans = 0; //훔칠 수 있는 문서의 최대 개수

		memset(check, false, sizeof(check));
		queue<pair<int, int>> q; //다음에 방문할 수 있는 칸
		queue<pair<int, int>> door[26]; //열쇠가 없어서 방문하지 못하는 문
		check[0][0] = true;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위를 벗어나는 경우
				if (a[nx][ny] == '*') continue; //벽인 경우
				if (check[nx][ny] == true) continue;
				
				check[nx][ny] = true;

				if (a[nx][ny] == '$') {
					ans += 1;
					q.push(make_pair(nx, ny));
				}
				else if (a[nx][ny] == '.') {
					q.push(make_pair(nx, ny));
				}
				else if (a[nx][ny] >= 'a' && a[nx][ny] <= 'z') { //열쇠인 경우
					if (key[a[nx][ny] - 'a'] == false) { //가지고 있지 않던 열쇠인 경우
						key[a[nx][ny] - 'a'] = true; //열쇠를 줍고
						
						//열쇠가 없어서 방문하지 못했던 문들을 방문할수 있는 칸(큐)에 넣기
						while (!door[a[nx][ny] - 'a'].empty()) {
							q.push(door[a[nx][ny] - 'a'].front());
							door[a[nx][ny] - 'a'].pop();
						}
					}
					q.push(make_pair(nx, ny));
				}
				else if (a[nx][ny] >= 'A' && a[nx][ny] <= 'Z') { //문인 경우
					if (key[a[nx][ny] - 'A'] == true) {
						q.push(make_pair(nx, ny));
					}
					else {
						door[a[nx][ny] - 'A'].push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}