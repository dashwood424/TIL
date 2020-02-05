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

	int right = 0;
	int left = 0;
	int sum = a[0];
	int ans = 0; //합이 m이 되는 경우의 수

	while (left <= right && right < n) {
		if (sum < m) {
			right += 1;
			sum += a[right];
		}
		else if (sum == m) {
			ans += 1;
			right += 1;
			sum += a[right];
		}
		else if (sum > m) {
			sum -= a[left];
			left += 1;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}

	cout << ans << '\n';

	return 0;
}