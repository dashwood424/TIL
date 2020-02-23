/*
각 칸이 세로 칸에 속하거나 가로 칸에 속함
0000000000000000 모두 가로 -> 가로로 네 자리수 4개 만든 경우
1111111111111111 모두 세로 -> 세로로 네 자리수 4개 만든 경우

2^16 가지 경우의 수
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int a[4][4];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	int ans = 0; //얻을 수 있는 점수의 최댓값

	for (int t = 0; t < (1 << (n*m)); t++) {
		int cur = 0; //현재 턴의 합
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				int k = i*m + j;

				if ((t&(1 << k)) == 0) { //k번째 칸이 가로 칸에 속하는 경우
					temp = temp * 10 + a[i][j];
				}
				else {
					cur += temp;
					temp = 0;
				}
			}
			cur += temp;
		}

		for (int j = 0; j < m; j++) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				int k = i*m + j;

				if ((t&(1 << k)) != 0) { //k번째 칸이 세로 칸에 속하는 경우
					temp = temp * 10 + a[i][j];
				}
				else {
					cur += temp;
					temp = 0;
				}
			}
			cur += temp;
		}

		if (ans < cur) {
			ans = cur;
		}
	}

	cout << ans << '\n';

	return 0;
}
