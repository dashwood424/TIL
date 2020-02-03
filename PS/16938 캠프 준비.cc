#include <iostream>
using namespace std;

int n, l, r, x;
int a[15];
bool c[15]; //고르는 문제면 true

int go(int index) { //index번째 문제를 고를지 말지
	if (index == n) { //n번 문제까지 고를지 말지 정했다면
		int cnt = 0;
		int sum = 0; //문제 난이도의 합
		int easy = -1; //가장 쉬운 문제
		int hard = -1; //가장 어려운 문제
		
		for (int i = 0; i < n; i++) {
			if (c[i]) {
				cnt += 1;
				sum += a[i];
				if (easy == -1 || easy > a[i]) {
					easy = a[i];
				}
				if (hard == -1 || hard < a[i]) {
					hard = a[i];
				}
			}
		}
		if (cnt >= 2 && l <= sum && sum <= r && hard - easy >= x) {
			return 1; //조건을 만족하는 경우의 수 하나 추가
		}
		else {
			return 0;
		}
	}
	
	c[index] = true;
	int temp1 = go(index + 1); //index번째를 포함하는 경우
	c[index] = false;
	int temp2 = go(index + 1); //index번째를 포함하지 않는 경우
	
	return temp1 + temp2;
}

int main() {
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << go(0) << '\n'; //캠프에 사용할 문제를 고르는 방법의 수

	return 0;
}