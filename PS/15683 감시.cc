/*
cctv는 벽을 통과할 수 x
회전은 항상 90도 회전
cctv는 cctv를 통과할 수 있음
사무실의 크기, 상태, cctv의 정보가 주어졌을 때 cctv의 방향을 적절히 정해서
사각지대의 최소 크기 구하기
-> : 0 부터 반시계방향으로 90도 회전
(k번째 방향+1)%4 -> 방향 k에서 반시계 방향으로 90도 회전
*/

#include <iostream>
#include <vector>
using namespace std;

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 }; //반시계 방향으로 90도 회전하는 순서대로
int n, m;

void check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y, int dir) {
	//x, y에 위치한 cctv의 방향이 dir일때 감시하는 영역 표시하기
	int i = x;
	int j = y;

	while (0 <= i && i < n && 0 <= j && j < m) { //사무실 영역을 벗어나지 않는지
		if (a[i][j] == 6) break; //벽을 만나면 종료
		b[i][j] = a[x][y]; //cctv의 번호로 표시
		
		i += dx[dir];
		j += dy[dir];
	}
}

int go(vector<vector<int>> &a, vector<pair<int, int>> &cctv, vector<int> dirs, int index) {
	if (index == cctv.size()) { //모든 cctv의 방향을 다 정해 줌
		vector<vector<int>> b(a); //벡터 b에 cctv가 감시하는 영역 표시하기
		for (int i = 0; i < cctv.size(); i++) {
			int x, y;
			x = cctv[i].first;
			y = cctv[i].second; //i번째 cctv의 위치

			if (a[x][y] == 1) { //i번째 cctv의 종류가 1
				check(a, b, x, y, dirs[i]);
			}
			else if (a[x][y] == 2) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (a[x][y] == 3) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
			}
			else if (a[x][y] == 4) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);

			}
			else if (a[x][y] == 5) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
				check(a, b, x, y, (dirs[i] + 3) % 4);
			}
		} //cctv가 감시하는 영역 모두 표시하기

		int cnt = 0; //사각 지대의 개수

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i][j] == 0) {
					cnt += 1;
				}
			}
		}

		return cnt;
 	}

	int ans = 10000;

	for (int i = 0; i < 4; i++) {
		dirs[index] = i; //index번째 cctv의 방향을 i로 정해줌
		int temp = go(a, cctv, dirs, index + 1);
		if (ans > temp) {
			ans = temp;
		}
	}

	return ans;
}

int main() {
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m)); //사무실의 상태
	vector<pair<int, int>> cctv; //cctv의 위치
	vector<int> dirs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 5) { //cctv이면
				cctv.push_back(make_pair(i, j));
				dirs.push_back(0);  //모든 cctv의 방향을 0으로 정해놓음 -> index번째 cctv의 방향을 정할 것임
			}
		}
	}

	
	cout << go(a, cctv, dirs, 0) << '\n';

	return 0;
}