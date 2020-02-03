#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 0; //두 십자가 넓이의 곱의 최댓값

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) { //십자가 1을 만들어 봄
			for (int s1 = 0; ; s1++) { //십자가 크기가 0인 것 부터
				if (x1 - s1 < 0 || x1 + s1 >= n) break;
				if (y1 - s1 < 0 || y1 + s1 >= m) break;
				if (a[x1 - s1][y1] != '#' || a[x1 + s1][y1] != '#') break;
				if (a[x1][y1 - s1] != '#' || a[x1][y1 + s1] != '#') break; //십자가를 놓을 수 없는 경우
				
				a[x1 - s1][y1] = '*';
				a[x1 + s1][y1] = '*';
				a[x1][y1 - s1] = '*';
				a[x1][y1 + s1] = '*'; //십자가 1을 놓을 수 있는 위치 표시

				for (int x2 = 0; x2 < n; x2++) {
					for (int y2 = 0; y2 < m; y2++) {
						for (int s2 = 0; ; s2++) {
							if (x2 - s2 < 0 || x2 + s2 >= n) break;
							if (y2 - s2 < 0 || y2 + s2 >= m) break;
							if (a[x2 - s2][y2] != '#' || a[x2 + s2][y2] != '#') break;
							if (a[x2][y2 - s2] != '#' || a[x2][y2 + s2] != '#') break;

							int cur = (4 * s1 + 1)*(4 * s2 + 1); //현재 십자가 넓이의 곱
							if (ans < cur) {
								ans = cur;
							}
						}
					}
				}
			}

			for (int s1 = 0; ; s1++) { //첫 번째 십자가를 놓은 위치 초기화하기
				if (x1 - s1 < 0 || x1 + s1 >= n) break;
				if (y1 - s1 < 0 || y1 + s1 >= m) break;
				if (a[x1 - s1][y1] != '*' || a[x1 + s1][y1] != '*') break;
				if (a[x1][y1 - s1] != '*' || a[x1][y1 + s1] != '*') break;

				a[x1 - s1][y1] = '#';
				a[x1 + s1][y1] = '#';
				a[x1][y1 - s1] = '#';
				a[x1][y1 + s1] = '#'; //십자가 1을 놓을 수 있는 위치 표시
			}
		}
	}

	cout << ans << '\n';
	
	return 0;
}