#include <iostream>
using namespace std;

int t[16];
int p[16];
int n;
int ans = 0;

void go(int index, int sum) { //index번째 날에 상담을 할지 말지 정함
	if (index == n + 1) {
		if (ans < sum) { //최대 수익을 구함
			ans = sum;
		}
		return;
	}
	if (index > n + 1) return;

	go(index + t[index], sum + p[index]); //index번째 날에 상담을 하는 경우
	go(index + 1, sum); //index번째 날에 상담을 하지 않는 경우
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	go(1, 0);

	cout << ans << '\n';

	return 0;
}