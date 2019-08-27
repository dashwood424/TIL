#include <iostream>
using namespace std;

bool check[20 * 100000 + 1]; //부분수열의 합으로 나올 수 있으면 true
int s[20];
int n;
void go(int index, int sum) {
	if (index == n) { //n번째 까지 부분수열을 만들었으면
		check[sum] = true;
		return;
	}

	go(index + 1, sum + s[index]); //index번째 원소를 더하는 경우
	go(index + 1, sum); //더하지 않는 경우
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	go(0, 0);

	for (int i = 0; ; i++) {
		if (check[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}