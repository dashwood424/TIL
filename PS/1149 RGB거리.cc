#include <iostream>
#include <algorithm>
using namespace std;

int p[1001][3]; //i번 집을 칠하는 비용 0:R, 1:G, 2:B
int d[1001][3]; //i번 집을 칠하는 비용의 최소값

//d[i][0]=min(d[i-1][1], d[i-1][2])+p[i][0] i번째 집을 R로 칠했을때 i-1번째는 G or B

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + p[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + p[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + p[i][2];
	}

	int ans = min(min(d[n][0], d[n][1]), d[n][2]);

	cout << ans << '\n';

	return 0;
}