#include <iostream>
using namespace std;

bool t[500001];
int num[1001];
int main() {
	for (int i = 1; i <= 1000; i++) {
		t[(i*(i + 1)) / 2] = true;
		num[i] = (i*(i + 1)) / 2;
	}

	int k;
	cin >> k;

	while (k--) {
		int x;
		cin >> x;
		
		bool ok = false;

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= x; j++) {
				if (x-num[i] - num[j] >= 0 && t[x - num[i] - num[j]]) {
					ok = true;
					break;
				} 
			}
		}
		if (ok) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}