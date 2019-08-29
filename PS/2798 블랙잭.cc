#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = 0;
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = a[i] + a[j] + a[k];
				if (sum <= m) {
					if (ans < sum) {
						ans = sum;
					}
				}
			}
		}
	}
	cout << ans << '\n';
}