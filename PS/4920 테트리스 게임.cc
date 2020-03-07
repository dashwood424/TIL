#include <iostream>
#include <cstring>
using namespace std;

int a[101][101];

int main() {
	int tc = 0;
	while (true) {
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		tc += 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		int ans = -2147483648;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j + 3 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 3 < n) {
					int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 1 < n && j + 2 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 2 < n && j - 1 >= 0) {
					int temp = a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 1 < n && j + 2 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 2 < n && j - 1 >= 0) {
					int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 1 < n && j + 2 < n) {
					int temp = a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 2 < n && j + 1 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j];
					if (ans < temp) {
						ans = temp;
					}
				}

				if (i + 2 < n) {
					if (j + 1 < n) {
						int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j + 1];
						if (ans < temp) {
							ans = temp;
						}
					}
					if (j - 1 >= 0) {
						int temp = a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1];
						if (ans < temp) {
							ans = temp;
						}
					}
				}

				if (j + 2 < n) {
					if (i + 1 < n) {
						int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1];
						if (ans < temp) {
							ans = temp;
						}
					}
					if (i - 1 >= 0) {
						int temp = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1];
						if (ans < temp) {
							ans = temp;
						}
					}
				}

				if (i + 1 < n && j + 1 < n) {
					int temp = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
					if (ans < temp) {
						ans = temp;
					}
				}
			}
		}
		cout << tc << ". " << ans << '\n';
	}
	return 0;
}