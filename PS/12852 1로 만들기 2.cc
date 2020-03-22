#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001]; //n을 1로 만드는 연산의 최소값
int from[1000001]; //from[i]=j -> j는 i에서 옴

void go(int n) {
	if (n == 0) return;
	cout << n << ' ';
	go(from[n]);
}

int main() {
	int n;
	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	from[3] = 1;
	from[2] = 1;
	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1; //1을 빼는 연산
		from[i] = i - 1;
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1) {
				d[i] = d[i / 3] + 1;
				from[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1) {
				d[i] = d[i / 2] + 1;
				from[i] = i / 2;
			}
		}
	}

	cout << d[n] << '\n';
	go(n);

	return 0;
}