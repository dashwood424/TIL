#include <iostream>
using namespace std;

bool check[20 * 100000 + 1]; //부분수열의 합으로 나올 수 있으면 true
int s[20];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) { //수열의 j번째 원소가 존재하면
				sum += s[j];
			}
		}
		check[sum] = true;
	}

	for (int i = 0; ; i++) {
		if (check[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}