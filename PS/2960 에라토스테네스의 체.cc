#include <iostream>
using namespace std;

bool c[1001];

int main() {
	int n, k;
	cin >> n >> k;

	int cnt = 0;
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (c[i]) continue;
		cnt += 1;
		if (cnt == k) {
			ans = i;
		}
		
		
		if (c[i] == false) {
			for (int j = i + i; j <= n; j += i) {
				if (c[j]) continue;
				c[j] = true;
				cnt += 1;
				if (cnt == k) {
					ans = j;
				}
				
			}
		}
	}

	cout << ans << '\n';

	return 0;
}