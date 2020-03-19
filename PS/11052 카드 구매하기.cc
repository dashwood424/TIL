#include <iostream>
#include <algorithm>
using namespace std;

int d[1001]; //카드 i개를 구매하는 금액의 최댓값
int p[1001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	d[1] = p[1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i - j] + p[j], d[i]);
		}
	}

	cout << d[n] << '\n';

	return 0;
}