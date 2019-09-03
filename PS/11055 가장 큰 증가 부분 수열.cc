#include <iostream>
#include <vector>
using namespace std;

int d[1001];
int a[1001];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// D[i]=i번째 인덱스의 수열이 증가하는 부분수열일때 최대합
	//모든 D[i]는 a[i]. 자기자신을 최대합으로 가짐

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i]) { //증가수열이고 가장 큰 합이면
				d[i] = d[j] + a[i];
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