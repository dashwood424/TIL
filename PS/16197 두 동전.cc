#include <iostream>
#include <string>
using namespace std;

string a[20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

int go(int step, int x1, int y1, int x2, int y2) {
	//1. 불가능한 경우
	if (step == 11) return -1; //버튼을 10번이상 누르는 경우 -1리턴

	//2. 가능한 경우
	bool fall1 = false, fall2 = false; //동전이 밖으로 떨어지면 true
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true; //동전1이 밖으로 떨어짐
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true; //동전2가 밖으로 떨어짐

	if (fall1 && fall2) return -1; //동전이 둘다 떨어지면 -1리턴
	if (fall1 || fall2) return step; //동전이 하나만 떨어지면 버튼을 누른 횟수 리턴

	//3. 다음 가능한 경우
	int ans = -1; //동전 한개가 밖으로 떨어질때 버튼을 누르는 최소 횟수
	
	for (int k = 0; k < 4; k++) {
		int nx1 = x1 + dx[k];
		int ny1 = y1 + dy[k];
		int nx2 = x2 + dx[k];
		int ny2 = y2 + dy[k];

		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') {
			//보드안에서 벽을 만난 경우
			nx1 = x1;
			ny1 = y1; //이동하지 않음
		}

		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}

		int temp = go(step + 1, nx1, ny1, nx2, ny2);
		if (temp == -1) continue; //불가능한 이동 건너뜀
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	cout << go(0, x1, y1, x2, y2) << '\n';
	return 0;
}