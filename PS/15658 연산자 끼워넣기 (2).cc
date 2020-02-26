#include <iostream>
using namespace std;

int a[20]; //수 입력
int op[4]; //각 연산자의 개수
int max_num = -1000000001;
int min_num = 1000000001;
int n;

void go(int index, int res) {
	if (index == n) {
		if (max_num < res) {
			max_num = res;
		}
		if (min_num > res) {
			min_num = res;
		}
		return;
	}
	else {
		if (op[0] > 0) {
			op[0]--;
			go(index + 1, res + a[index]);
			op[0]++;
		}
		if (op[1] > 0) {
			op[1]--;
			go(index + 1, res - a[index]);
			op[1]++;
		}
		if (op[2] > 0) {
			op[2]--;
			go(index + 1, res*a[index]);
			op[2]++;
		}
		if (op[3] > 0) {
			op[3]--;
			go(index + 1, res / a[index]);
			op[3]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	go(1, a[0]);

	cout << max_num << '\n';
	cout << min_num << '\n';

	return 0;
}