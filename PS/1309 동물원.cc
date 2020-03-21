#include <iostream>
using namespace std;

long long d[100001][3];
long long mod = 9901;

int main() {
	int n;
	cin >> n;

	d[0][0] = 1;
	d[0][1] = 1;
	d[0][2] = 1;

	for (int i = 1; i < n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
		d[i][1] = d[i - 1][0] + d[i - 1][2];
		d[i][2] = d[i - 1][0] + d[i - 1][1];

		d[i][0] %= mod;
		d[i][1] %= mod;
		d[i][2] %= mod;
	}

	long long ans = d[n - 1][0] + d[n - 1][1] + d[n - 1][2];
	ans %= mod;
	cout << ans << '\n';

	return 0;
}