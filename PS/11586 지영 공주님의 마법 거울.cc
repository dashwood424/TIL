#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int state;
	cin >> state;

	if (state == 1) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << '\n';
		}
	}
	else if (state == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][n - j - 1];
			}
			cout << '\n';
		}
	}
	else if (state == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[n - i - 1][j];
			}
			cout << '\n';
		}
	}

	return 0;
}