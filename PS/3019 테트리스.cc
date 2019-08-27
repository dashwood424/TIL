#include <iostream>
#include <string>
using namespace std;

int a[101];
int n;

int calc(int i, string s) { //i번째 위치에서부터 블록의 바닥과의 높이 비교
	int len = s.length();
	if (i + len > n) return 0; //범위를 벗어나는 경우
	int base = a[i] - (s[0] - '0');
	for (int j = 0; j < len; j++) {
		if (a[i + j] - (s[j] - '0') != base) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0; //블록을 떨어뜨리는 방법의 수

	for (int i = 0; i < n; i++) { //i번째 열에서부터 블록을 놓음
		if (m == 1) {
			ans += calc(i, "0") + calc(i, "0000"); //각 칸의 바닥으로부터 높이
		}
		else if (m == 2) {
			ans += calc(i, "00");
		}
		else if (m == 3) {
			ans += calc(i, "001") + calc(i, "10");
		}
		else if (m == 4) {
			ans += calc(i, "100") + calc(i, "01");
		}
		else if (m == 5) {
			ans += calc(i, "000") + calc(i, "10") + calc(i, "101") + calc(i, "01");
		}
		else if (m == 6) {
			ans += calc(i, "000") + calc(i, "20") + calc(i, "011") + calc(i, "00");
		}
		else if (m == 7) {
			ans += calc(i, "000") + calc(i, "02") + calc(i, "110") + calc(i, "00");
		}
	}
	cout << ans << '\n';
	return 0;
}