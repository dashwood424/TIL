#include <iostream>
#include <algorithm>
using namespace std;

int a[504][504];
int d[504][504];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[n][i]) {
			ans = d[n][i];
		}
	}

	cout << ans << '\n';

	return 0;
}
