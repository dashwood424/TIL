#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

bool check[100][100]; //십자가를 만들 수 있는 칸이면 true

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<tuple<int, int, int>> ans; //십자가의 중심위치, 크기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int len = 0;
			if (a[i][j] == '*') { //십자가의 중심이 될 수 있는 칸이면
				for (int k = 1; ; k++) {
					if (i - k >= 0 && i + k < n && j - k >= 0 && j + k < m) { //범위를 벗어나는지
						if (a[i - k][j] == '*' && a[i + k][j] == '*' && a[i][j - k] == '*' && a[i][j + k] == '*') {
							//십자가가 만들어 지는지
							len = k;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
			}
			if (len > 0) { //십자가를 만들 수 있는 칸 true
				check[i][j] = true;
				for (int k = 1; k <= len; k++) {
					check[i - k][j] = true;
					check[i + k][j] = true;
					check[i][j - k] = true;
					check[i][j + k] = true;
				}
				ans.push_back(make_tuple(i + 1, j + 1, len)); //십자가의 중심 위치와 길이 저장
			}
		}
	}

	for (int i = 0; i < n; i++) { //십자가로 주어진 격자판을 만들 수 없는 경우
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '*' && check[i][j] == false) { //십자가를 만들 수 있는 칸인데 만들 수 없는 칸이 존재하는 경우
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	cout << ans.size() << '\n';

	for (auto t : ans) {
		int x, y, len;
		tie(x, y, len) = t;
		cout << x << ' ' << y << ' ' << len << '\n';
	}

	return 0;
}