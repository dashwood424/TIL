/*

  0 1 2 3 4 5 6 7 8 9 -> 끝나는 수
1 0 1 1 1 1 1 1 1 1 1 -> 길이
2 1 1 2 2 2 2 2 2 2 1
3 1 3 3 4 4 4 4 4 3 2 

1로 끝나는 길이가 2인 계단 수
21

3으로 끝나는 길이가 2인 계단 수
23
43

-> 2로 끝나는 길이가 3인 계단 수
212
232
432

d[n][k] = 길이가 n인 k로 끝나는 계단수의 개수
d[n][k] = d[n-1][k-1]+d[n-1][k+1]

*/

#include <iostream>
using namespace std;

long long d[101][10];
long long mod = 1000000000;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1; //길이가 1인 i로 끝나는 계단수의 개수
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= mod;
		}
	}

	long long ans = 0;

	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	ans %= mod;

	cout << ans << '\n';

	return 0;
}