#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &a, int l) {
	int n = a.size();
	vector<bool> c(n, false);
	
	for (int i = 1; i < n; i++) {
		if (a[i - 1] != a[i]) { //높이가 다른 칸인지
			int diff = a[i - 1] - a[i];
			if (diff < 0) diff = -diff;
			if (diff != 1) return false; //인접한 칸의 높이가 1이 아님

			if (a[i - 1] < a[i]) {
				for (int j = 1; j <= l; j++) {
					if (i - j < 0) { //경사로를 놓을 범위를 벗어나는 경우
						return false;
					}
					if (c[i - j]) { //경사로를 놓은 곳에 또 경사로를 놓음
						return false;
					}
					if (a[i - 1] != a[i - j]) { //낮은 지점 칸의 높이가 모두 같지 않거나 연속하지 않음
						return false;
					}
					c[i - j] = true; //경사로 놓음
				}
			}
			else { //a[i-1] > a[i]
				for (int j = 0; j < l; j++) {
					if (i + j >= n) { //경사로를 놓을 범위를 벗어나는 경우
						return false;
					}
					if (c[i + j]) { //경사로를 놓은 곳에 또 경사로를 놓음
						return false;
					}
					if (a[i] != a[i + j]) {
						return false;
					}
					c[i + j] = true;
				}
			}
		}
	}
	return true;
}

int main() {
	int n, l;
	cin >> n >> l;
	vector<vector<int> > a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;

	///행 방향으로 지나갈 수 있는길 체크
	for (int i = 0; i < n; i++) {
		vector<int> d;
		for (int j = 0; j < n; j++) {
			d.push_back(a[i][j]);
		}
		if (check(d, l)) {
			ans += 1;
		}
	}

	//열 방향으로 지나갈 수 있는 길 체크
	for (int j = 0; j < n; j++) {
		vector<int> d;
		for (int i = 0; i < n; i++) {
			d.push_back(a[i][j]);
		}
		if (check(d, l)) {
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}