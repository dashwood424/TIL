#include <iostream>
#include <set>
using namespace std;

int n = 5;
int a[5][5];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
set<int> ans;

void go(int x, int y, int num, int cnt) {
	if (cnt == 6) {
		ans.insert(num);
		return;
	}
	
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			go(nx, ny, num * 10 + a[nx][ny], cnt + 1);
		}
	}
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//모든 가능한 시작점을 고려하며 6자리수만들기
			go(i, j, a[i][j], 1);
		}
	}

	cout << ans.size() << '\n';
	return 0;
}