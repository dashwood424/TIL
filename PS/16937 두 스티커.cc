#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;

	vector<pair<int, int>> s; //스티커의 세로, 가로

	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		s.push_back(make_pair(r, c));
	}

	int ans = 0; //스티커를 붙일 수 있는 최대 면적

	for (int i = 0; i < s.size(); i++) { //스티커 1을 고름
		int x1 = s[i].first;
		int y1 = s[i].second;

		for (int j = 0; j < s.size(); j++) { //스티커 2를 고름
			if (i == j) continue; //같은 스티커를 고른 경우
			int x2 = s[j].first;
			int y2 = s[j].second;

			for (int r1 = 0; r1 < 2; r1++) { //스티커 1을 회전시킴
				for (int r2 = 0; r2 < 2; r2++) { //스티커 2를 회전시킴
					if (y1 + y2 <= w && max(x1, x2) <= h) {
						int temp = x1*y1 + x2*y2;
						if (ans < temp) ans = temp;
					}
					if (x1 + x2 <= h && max(y1, y2) <= w) {
						int temp = x1*y1 + x2*y2;
						if (ans < temp) ans = temp;
					}
					swap(x2, y2);
				}
				swap(x1, y1);
			}
 		}
	}

	cout << ans << '\n';
	return 0;
}