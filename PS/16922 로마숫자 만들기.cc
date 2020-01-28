#include <iostream>
using namespace std;

bool check[20001]; //숫자 i를 만들 수 있으면 true

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			for (int k = 0; k <= n - i - j; k++) {
				int l = n - i - j - k;
				int res = i * 1 + j * 5 + k * 10 + l * 50;
				check[res] = true;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= 20001; i++) {
		if (check[i]) {
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}