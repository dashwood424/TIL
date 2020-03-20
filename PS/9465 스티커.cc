#include <iostream>
#include <algorithm>
using namespace std;

int d[100001][3]; 
//0: i번째 열의 스티커를 둘다 뜯지 않음
//1: i번째 열의 스티커를 윗칸만 뜯음
//2: i번째 열의 스티커를 아랫칸만 뜯음
int p[100001][2];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> p[i][0];
		}

		for (int i = 1; i <= n; i++) {
			cin >> p[i][1];
		}
		
		d[1][0] = 0;
		d[1][1] = p[1][0];
		d[1][2] = p[1][1];

		for (int i = 2; i <= n; i++) {
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + p[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + p[i][1];
		}
		
		int ans = max(max(d[n][0], d[n][1]), d[n][2]);

		cout << ans << '\n';
	}

	return 0;
}