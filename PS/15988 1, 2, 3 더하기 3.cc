#include <iostream>
using namespace std;

long long d[1000001]; //d[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
long long mod = 1000000009L;

int main() {
	d[0] = 1; //1, 2, 3초기화하기 위해
	for (int i = 1; i <= 1000000; i++) {
		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
		d[i] %= mod;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}