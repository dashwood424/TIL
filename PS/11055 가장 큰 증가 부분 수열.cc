#include <iostream>
using namespace std;

int d[1001]; //합이 가장 큰 증가 부분 수열의 합
int a[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] < a[i] && d[j] + a[i] > d[i]) {
				d[i] = d[j] + a[i];
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}

	cout << ans << '\n';

	return 0;
}