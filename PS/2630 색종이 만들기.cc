#include <iostream>
using namespace std;
int n;
int a[129][129];

int zero = 0;
int one = 0;

void go(int sx, int sy, int n) {
	int color = a[sx][sy];

	for (int i = sx; i < sx + n; i++) {
		for (int j = sy; j < sy + n; j++) {
			if (color != a[i][j]) {
				go(sx, sy, n / 2);
				go(sx, sy + n / 2, n / 2);
				go(sx + n / 2, sy, n / 2);
				go(sx + n / 2, sy + n / 2, n / 2);

				return;
			}
		}
	}

	if (color == 1) {
		one++;
	}
	else {
		zero++;
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	go(0, 0, n);

	cout << zero << '\n' << one << '\n';

	return 0;
}