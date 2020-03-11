#include <iostream>
using namespace std;

int a[10][10];
int n = 10;
int available[] = { 0,5,5,5,5,5 }; //색종이의 크기별 개수

int go(int z) {
	if (z == 100) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1) return -1; //덮지 않은 칸이 하나라도 있는 경우 -1 리턴
			}
		}
		return 0;
	}

	int ans = -1;
	int x = z / n;
	int y = z%n;

	if (a[x][y] == 0) {
		return go(z + 1);
	}

	for (int k = 5; k >= 1; k--) { //색종이의 크기가 큰 것부터 붙여보기
		if (available[k] > 0) { //색종이가 남아있고
			if (x + k - 1 < n && y + k - 1 < n) { //범위를 벗어나지 않는 경우
				bool ok = true;
				for (int i = x; i < x + k; i++) {
					for (int j = y; j < y + k; j++) {
						if (a[i][j] == 0) { //크기가 k인 색종이로 덮을 수 없는 칸이 있는 경우
							ok = false;
						}
					}
					if (!ok) break;
				}

				if (ok) { 
					for (int i = x; i < x + k; i++) {
						for (int j = y; j < y + k; j++) {
							a[i][j] = 0;
						}
					}
					available[k] -= 1;

					int temp = go(z + 1);
					if (temp != -1) {
						if (ans == -1 || ans > temp + 1) {
							ans = temp + 1;
						}
					}

					available[k] += 1;
					for (int i = x; i < x + k; i++) {
						for (int j = y; j < y + k; j++) {
							a[i][j] = 1;
						}
					}
				}
			}
		}
	}

	return ans;
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << go(0) << '\n';

	return 0;
}