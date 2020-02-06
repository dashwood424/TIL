/*
설치해야 할 거울의 최소 개수

***#*
*.!.*
*!.!*
*.!.*
*#***

! : 거울을 놓을 수 있는 위치
# : 문
* : 벽

00010
00200
03040
00500
06000 -> 이런 형태로 만들어 주기 

 123456
1FFFTFF
2FFFFTF
3FFFTFT
4TFTTFF
5FTFFFF
6FFTFFF -> d[i][j] : i번 정점에서 j번 정점을 볼 수 있으면 i번 정점에서 직교하는(?) 방향으로 있으면 true

시작과 끝이 몇 번 정점인지 알아야 함
-> 항상 시작 정점에서 시작해서 끝 정점에서 끝나야 하기 때문에

mirror[i] : i번 정점까지 거쳐온 정점의 개수
-> mirror[end]-1 가 정답이 됨
mirror배열을 갱신해주면서 정답 찾기

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	int n;
	cin >> n;

	vector<string> a(n); 
	vector<pair<int, int>> v; //정점의 위치
	int start, end; //시작 정점 번호
	start = end = -1; //끝 정점 번호
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '#') {
				if (start == -1) {
					start = v.size();
					v.push_back(make_pair(i, j));
				}
				else {
					v.push_back(make_pair(i, j));
					end = v.size() - 1;
				}
			}
			else if (a[i][j] == '!') {
				v.push_back(make_pair(i, j));
			}
		}
	}

	int l = v.size();
	vector<vector<int>> b(n, vector<int>(n)); //정점 번호로 표시 
	for (int i = 0; i < l; i++) {
		int x, y;
		x = v[i].first;
		y = v[i].second;

		b[x][y] = i;
	}

	vector<vector<bool>> d(l, vector<bool>(l, false)); //d[i][j] : i번 정점에서 j를 볼 수 있으면 true

	for (int i = 0; i < l; i++) {
		for (int k = 0; k < 4; k++) {
			int x = v[i].first + dx[k];
			int y = v[i].second + dy[k];
			
			while (0 <= x && x < n && 0 <= y && y < n) {
				if (a[x][y] == '*') break;
				if (a[x][y] == '!' || a[x][y] == '#') {
					d[i][b[x][y]] = true;
				}
				x += dx[k];
				y += dy[k];
			}
		}
	}

	//거울을 놓는 최소 개수 -> start에서 end까지 정점을 방문하는 최소횟수 -> bfs
	queue<int> q;
	vector<int> mirror(l, -1);
	mirror[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		for (int i = 0; i < l; i++) {
			if (d[x][i]==true && mirror[i] == -1) {
				mirror[i] = mirror[x] + 1;
				q.push(i);
			}
		}
	}

	cout << mirror[end] - 1 << '\n';

	return 0;
}