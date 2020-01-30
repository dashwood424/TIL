/*

n개의 세로선, m개의 가로선, 각각의 세로선 마다 가로선을 놓을 수 있는 위치 h
두 가로선이 연속하거나 서로 접하면 안됨
2 <= n <= 10, 1 <= h <= 30
0 <= m <= (n-1)*h 이지만 실제로 가능한 경우는 아님! 러프한 경우의 수! <- 두 가로선이 연속하거나 접하면 안됨
가로선의 정보 -> a, b -> b번 세로선과 b+1번 세로선을 a번 위치에서 연결
1 <= a <= h
ladder[a][b]=1, ladder[a][b+1]=2 이런식으로 배열에 가로선이 놓여있음을 표현하자

가로선을 놓을 수 있는 위치에 가로선을 3개까지 놓아

***i번 세로선에서 시작한 값이 i번에서 끝나는 가로선을 놓는 최소 개수 구하기
정답이 3보다 크면 -1 출력
불가능한 경우도 -1 출력

1. i번 세로선에서 시작한 사다리의 결과가 몇 번 세로선인지
2. i번 세로선에서 시작한 사다리가 i번에서 끝나는지

*/

#include <iostream>
#include <vector>
using namespace std;

int n, m, h; //세로선의 개수, 가로선의 개수, 가로선을 놓을 수 있는 위치의 개수 -> 사다리는 n*h행렬임
int ladder[31][31];

int start(int col) { //col번째 세로선의 사다리 게임 결과
	int row = 1;

	while (row <= h) {
		if (ladder[row][col] == 1) {
			col += 1;
		}
		else if (ladder[row][col] == 2) {
			col -= 1;
		}
		row += 1;
	}

	return col;
}

bool go() { //모든 i번째 세로선의 결과가 i번이면 true 리턴
	for (int i = 1; i <= n; i++) {
		int res = start(i);
		if (res != i) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m >> h;

	while (m--) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1; //왼쪽 끝
		ladder[a][b + 1] = 2; //오른쪽 끝
	}

	vector<pair<int, int>> candi; //가로선을 놓을 수 있는 후보 위치

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (ladder[i][j] != 0 && ladder[i][j + 1] != 0) continue; 
			candi.push_back(make_pair(i, j));
		}
	}

	int ans = -1;

	if (go()) { //이미 i번 세로선에서 i번 세로선으로 도착하는 경우인지
		cout << 0 << '\n';
		return 0; //가로선을 추가하지 않았으므로 여기서 종료하기
	}

	int l = candi.size(); // 후보 위치의 개수


	//모든 놓을 수 있는 위치에 3개까지 놓아보고 최소인지 비교
	for (int i = 0; i < l; i++) {
		int x1 = candi[i].first;
		int y1 = candi[i].second;

		if (ladder[x1][y1] != 0 || ladder[x1][y1 + 1] != 0) continue;

		ladder[x1][y1] = 1;
		ladder[x1][y1 + 1] = 2; //가로선을 놓아보고

		if (go()) { 
			if (ans == -1 || ans > 1) { //현재 정답이 1보다 큰 경우이면
				ans = 1;
			}
		}

		for (int j = i + 1; j < l; j++) {
			int x2 = candi[j].first;
			int y2 = candi[j].second;

			if (ladder[x2][y2] != 0 || ladder[x2][y2 + 1] != 0) continue;
			
			ladder[x2][y2] = 1;
			ladder[x2][y2 + 1] = 2;

			if (go()) {
				if (ans == -1 || ans > 2) {
					ans = 2;
				}
			}

			for (int k = j + 1; k < l; k++) {
				int x3 = candi[k].first;
				int y3 = candi[k].second;

				if (ladder[x3][y3] != 0 || ladder[x3][y3 + 1] != 0) continue;

				ladder[x3][y3] = 1;
				ladder[x3][y3 + 1] = 2;

				if (go()) {
					if (ans == -1 || ans > 3) {
						ans = 3;
					}
				}

				ladder[x3][y3] = 0;
				ladder[x3][y3 + 1] = 0;
			}
			ladder[x2][y2] = 0;
			ladder[x2][y2 + 1] = 0;
		}
		ladder[x1][y1] = 0;
		ladder[x1][y1 + 1] = 0;
	}

	cout << ans << '\n';

	return 0;
}