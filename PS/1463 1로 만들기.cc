#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001]; //n을 1로 만드는 연산의 최소값

int main() {
	int n;
	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1; //1을 빼는 연산
		if (i % 3 == 0) {
			d[i] = min(d[i / 3] + 1, d[i]);
		}
		if (i % 2 == 0) {
			d[i] = min(d[i / 2] + 1, d[i]);
		}
	}

	cout << d[n] << '\n';

	return 0;
}