#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
bool check[101][101];

vector<int> go(int d, int g) {
	vector<int> dir = { d };
	
	for (int i = 1; i <= g; i++) {
		vector<int> temp(dir);
		reverse(temp.begin(), temp.end());

		for (int &t : temp) {
			t = (t + 1) % 4;
		}
		dir.insert(dir.end(), temp.begin(), temp.end());
	}
	return dir;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x, y, d, g; //시작점, 방향, 세대
		cin >> y >> x >> d >> g;

		vector<int> dirs;
		dirs = go(d, g);
		check[x][y] = true;

		for (int d : dirs) { //방향으로 좌표 복원해서 드래곤 커브의 일부인 점 체크하기
			x += dx[d];
			y += dy[d];
			check[x][y] = true;
		}
	}

	int ans = 0;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1]) {
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}