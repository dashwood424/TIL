#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = -1; //등차 수여롤 변화시키기 위한 연산 횟수의 최솟값

	for (int d1 = -1; d1 <= 1; d1++) { //a0항에 적용할 연산
		for (int d2 = -1; d2 <= 1; d2++) { //a1항에 적용할 연산
			int cnt = 0; //연산을 적용한 횟수
			if (d1 != 0) cnt += 1;
			if (d2 != 0) cnt += 1;
			int a0 = a[0] + d1; //a0
			int diff = (a[1] + d2) - a0; //공차
			int an = a0 + diff; //a1
			bool ok = true; //등차수열 만들 수 없으면 false

			for (int i = 2; i < n; i++) {
				an += diff;
				if (an == a[i]) continue; //i번째 항에 연산을 적용하지 않아도 됨
				if (a[i] - 1 == an) cnt += 1; //i번째 항에 -1한 경우 an과 같다면
				else if (a[i] + 1 == an) cnt += 1;
				else {
					ok = false;
					break;
				}
			}

			if (ok) {
				if (ans == -1 || cnt < ans) {
					ans = cnt;
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}