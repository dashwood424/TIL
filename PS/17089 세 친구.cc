#include <iostream>
using namespace std;

int a[4001][4001]; //친구 관계 -> 친구이면 1
int d[4001]; //i번째 사람의 친구 수

int main() {
	int n, m;
	cin >> n >> m;
	
	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = 1;
		d[x] += 1;
		d[y] += 1;
	}

	int ans = -1; //세사람을 골랐을 때 a,b,c가 모두 친구 일때 a친구 수+b친구 수+c친구 수 의 최솟값

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (a[i][j] == 1) { //a, b가 친구일 때
				for (int k = 0; k <= n; k++) {
					if (a[i][k] == 1 && a[j][k] == 1) { //a, b와 모두 친구인지
						int temp = d[i] + d[j] + d[k] - 6; //a를 계산할 때 현재 선택한 b, c를 빼야하기 때문에
						if (ans == -1 || ans > temp) {
							ans = temp;
						}
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}