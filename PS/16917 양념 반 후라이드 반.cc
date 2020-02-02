#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y; //양념 가격, 후라이드 가격, 반반 가격, 양념 최소 x마리, 후라이드 최소 y마리
	cin >> a >> b >> c >> x >> y;

	int ans = 2147483647;

	for (int i = 0; i <= 100000; i++) {
		int res = 2 * i*c + max(0, x - i)*a + max(0, y - i)*b;
		if (res < ans) {
			ans = res;
		}
	}

	cout << ans << '\n';
	return 0;
}