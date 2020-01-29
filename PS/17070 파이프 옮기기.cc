#include <iostream>
using namespace std;

int a[20][20]; //집의 크기
int n;

int go(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) { //파이프의 끝이 (n-1, n-1) 에 도착하는 경우 
		return 1; //도착하는 방법을 하나 찾음
	}

	int ans = 0;
	
	if (dir == 0) { //가로
		if (y + 1 < n && a[x][y + 1] == 0) { //가로->가로
			//범위 안에 있고 이동하는 칸이 벽이 아닌 경우
			ans += go(x, y + 1, 0);
		}

		if (x + 1 < n && y + 1 < n && a[x + 1][y] == 0 && a[x][y + 1] == 0 && a[x + 1][y + 1] == 0) { //가로->대각선
			ans += go(x + 1, y + 1, 2);
		}
	}
	else if (dir == 1) { //세로
		if (x + 1 < n && a[x + 1][y] == 0) { //세로->세로
			ans += go(x + 1, y, 1);
		}

		if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) { //세로->대각선
			ans += go(x + 1, y + 1, 2);
		}
	}
	else if (dir == 2) { //대각선
		if (y + 1 < n && a[x][y + 1] == 0) { //대각선->가로
			ans += go(x, y + 1, 0);
		}
		
		if (x + 1 < n && a[x + 1][y] == 0) { //대각선->세로
			ans += go(x + 1, y, 1);
		}

		if (x + 1 < n && y + 1 < n && a[x][y + 1] == 0 && a[x + 1][y] == 0 && a[x + 1][y + 1] == 0) { //대각선->대각선
			ans += go(x + 1, y + 1, 2);
		}
	}

	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	cout << go(0, 1, 0) << '\n'; //파이프의 끝은 항상 (0,1) 에 위치, 0(가로) 방향부터 시작
	
	return 0;
}