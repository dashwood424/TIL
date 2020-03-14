#include <iostream>
using namespace std;

int a[10][10]; //꽃밭
bool check[10][10]; //꽃을 심은 위치

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = -1;

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			if (x1 - 1 < 0 || x1 + 1 >= n || y1 - 1 < 0 || y1 + 1 >= n || check[x1][y1] == true) continue;
			if (check[x1 - 1][y1] || check[x1 + 1][y1] || check[x1][y1 - 1] || check[x1][y1 + 1]) continue;
			check[x1 - 1][y1] = true;
			check[x1 + 1][y1] = true;
			check[x1][y1 - 1] = true;
			check[x1][y1 + 1] = true;
			check[x1][y1] = true;

			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < n; y2++) {
					if (x2 - 1 < 0 || x2 + 1 >= n || y2 - 1 < 0 || y2 + 1 >= n || check[x2][y2] == true) continue;
					if (check[x2 - 1][y2] || check[x2 + 1][y2] || check[x2][y2 - 1] || check[x2][y2 + 1]) continue;
					check[x2 - 1][y2] = true;
					check[x2 + 1][y2] = true;
					check[x2][y2 - 1] = true;
					check[x2][y2 + 1] = true;
					check[x2][y2] = true;
					
			
					for (int x3 = 0; x3 < n; x3++) {
						for (int y3 = 0; y3 < n; y3++) {
							if (x3 - 1 < 0 || x3 + 1 >= n || y3 - 1 < 0 || y3 + 1 >= n || check[x3][y3] == true) continue;
							if (check[x3 - 1][y3] || check[x3 + 1][y3] || check[x3][y3 - 1] || check[x3][y3 + 1]) continue;
							check[x3 - 1][y3] = true;
							check[x3 + 1][y3] = true;
							check[x3][y3 - 1] = true;
							check[x3][y3 + 1] = true;
							check[x3][y3] = true;
							

							int temp = 0;
							
							for (int i = 0; i < n; i++) {
								for (int j = 0; j < n; j++) {
									if (check[i][j]) {
										temp += a[i][j];
									}
								}
							}

							if (ans == -1 || ans > temp) {
								ans = temp;
							}

							check[x3 - 1][y3] = false;
							check[x3 + 1][y3] = false;
							check[x3][y3 - 1] = false;
							check[x3][y3 + 1] = false;
							check[x3][y3] = false;
						}
					}
					check[x2 - 1][y2] = false;
					check[x2 + 1][y2] = false;
					check[x2][y2 - 1] = false;
					check[x2][y2 + 1] = false;
					check[x2][y2] = false;
				}
			}
			check[x1 - 1][y1] = false;
			check[x1 + 1][y1] = false;
			check[x1][y1 - 1] = false;
			check[x1][y1 + 1] = false;
			check[x1][y1] = false;
		}
	}

	cout << ans << '\n';

	return 0;
}