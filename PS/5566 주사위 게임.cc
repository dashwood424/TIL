#include <iostream>
#include <vector>
using namespace std;

int a[1001];

int main() {
	int n, m;
	cin >> n >> m; //n: 칸의 개수, n칸에 도착해야함. m: 주사위를 던진 횟수

	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
	}

	int ans = 0; //주사위를 던지는 횟수
	int cur = 1; //현재 위치
	while (m--) {
		int i;
		cin >> i; //주사위로 나온 눈
		
		cur += i; //현재 칸의 위치를 주사위로 나온 눈만큼 옮기고
		ans += 1; //주사위 던지는 횟수 증가

		if (a[cur] < 0) {
			cur -= -a[cur];
		}
		else if(a[cur] > 0) {
			cur += a[cur];
		}

		if (cur >= n) { //n칸에 도착했을 때와 그 칸을 넘는 경우도 도착한 것
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}