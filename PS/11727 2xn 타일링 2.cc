#include <iostream>
using namespace std;

int d[1001]; //2*n 직사각형을 채우는 경우의 수

int main() {
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++) {
		d[i] = (2 * d[i - 2] + d[i - 1]) % 10007;
	}
	cout << d[n] << '\n';
	return 0;
}