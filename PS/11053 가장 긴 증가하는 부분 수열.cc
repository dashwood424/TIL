#include <iostream>
using namespace std;

int d[1001]; //d[i] = i번째 수가 증가하는 부분수열의 마지막 수 일 때 길이
int a[1001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1; //자기 자신은 항상 길이가 1인 수열
		
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}

	cout << ans << '\n';

	return 0;
}