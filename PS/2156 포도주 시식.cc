#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];
int d[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1]; //i번째 포도주를 마시지 않음
		d[i] = max(d[i], d[i - 2] + a[i]); //i번째 포도주를 연속 1번 마심
		d[i] = max(d[i], d[i - 3] + a[i - 1] + a[i]); //i번째 포도주를 연속 2번 마심
	}

	cout << d[n] << '\n';

	return 0;
}