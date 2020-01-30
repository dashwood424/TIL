#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m, k; //배열의 크기, 회전연산의 개수

void go(vector<vector<int>> &a, tuple<int, int, int> d) { //회전 연산을 수행
	int row, col, size;
	tie(row, col, size) = d;

	vector<vector<int>> groups; //size별로 배열의 원소 넣기

	for (int s = 1; s <= size; s++) {
		vector<int> group; //현재 size의 원소

		for (int c = col - s; c < col + s; c++) { //(row-s, col-s)부터 (row-s+1, col-s) 까지 시계방향으로 순서대로 벡터에 넣기
			int r = row - s;
			group.push_back(a[r][c]);
		}

		for (int r = row - s; r < row + s; r++) {
			int c = col + s;
			group.push_back(a[r][c]);
		}

		for (int c = col + s; c > col - s; c--) {
			int r = row + s;
			group.push_back(a[r][c]);
		}

		for (int r = row + s; r > row - s; r--) {
			int c = col - s;
			group.push_back(a[r][c]);
		}
		groups.push_back(group); //크기가 s인 배열의 원소 그룹
	}

	//한 칸씩 옆으로 밀기
	//ex) 8 7 2 1 1 5 4 2 -> 2 8 7 2 1 1 5 4
	//groups[1][0] -> size가 1인 배열의 첫번째 원소
	

	//다시 순서대로 채우기

	for (int s = 1; s <= size; s++) {
		vector<int> group = groups[s - 1];

		int temp = group[group.size() - 1];
		for (int j = group.size() - 1; j >= 1; j--) {
			group[j] = group[j - 1];
		}
		group[0] = temp;

		int index = 0;

		for (int c = col - s; c < col + s; c++) {
			int r = row - s;
			a[r][c] = group[index++];
		}

		for (int r = row - s; r < row + s; r++) {
			int c = col + s;
			a[r][c] = group[index++];
		}

		for (int c = col + s; c > col - s; c--) {
			int r = row + s;
			a[r][c] = group[index++];
		}

		for (int r = row + s; r > row - s; r--) {
			int c = col - s;
			a[r][c] = group[index++];
		}
	}
}

int main() {
	cin >> n >> m >> k;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<tuple<int, int, int>> d(k); //회전연산, 중심위치, 크기
	for (int i = 0; i < k; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		d[i] = make_tuple(x - 1, y - 1, s);
	}

	int ans = -1; //최소 배열의 값

	sort(d.begin(), d.end());

	//회전 연산의 순서를 바꿔가면서 배열의 최소값 구하기
	do {
		vector<vector<int>> b(a); //배열 b의 값을 직접 바꿀 것임 

		for (auto &t : d) { //회전 연산의 순서에 따라 회전연산 후
			go(b, t);
		}

		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < m; j++) {
				temp += b[i][j];
			}
			if (ans == -1 || ans > temp) {
				ans = temp;
			}
		}
	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';

	return 0;
}