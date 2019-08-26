#include <iostream>
using namespace std;

bool check[201][201]; //섞어먹으면 안되는 조합인 경우 true

int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		check[x][y] = true;
		check[y][x] = true;
	}

	int ans = 0; //가능한 방법의 수
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (check[i][j] || check[j][k] || check[i][k]) continue; 
				//먹을 수 없는 조합이라면 건너뜀
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}