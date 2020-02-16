#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;

	long long ans = 0;
	
	int start = 1, end = 9;
	int len = 1;
	bool ok = true;
	while (true) {
		if (n < end) {
			end = n;
			ok = false;
		}
		ans += (end - start + 1)*len;

		if (!ok) {
			break;
		}

		len++;
		start *= 10;
		end = end * 10 + 9;
	}

	cout << ans << '\n';

	return 0;
}