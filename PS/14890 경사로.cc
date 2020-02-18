/*
길 -> 한 행 or 한 열을 지나갈 수 있으면 길 -> 길의 개수

경사로는 높이가 항상 1, 길이 l
경사로는 낮은 칸에 놓음. l개의 연속된 칸에 경사로의 바닥이 모두 접해야 함
낮은 칸과 높은 칸의 차이는 1
낮은 칸의 높이가 모두 같아야 함. l개의 칸이 연속되어 있어야 함

경사로를 놓은 곳에 또 경사로를 놓음
낮은 칸과 높은 칸의 높이차이가 1이 아닌 경우
낮은 지점의 칸의 높이가 모두 같지 않거나 l개가 연속되지 않은 경우
경사로를 놓다가 범위를 벗어나는 경우

*/

#include <iostream>
#include <vector>
using namespace std;

bool go(vector<int> &b, int l) {
	int n = b.size();
	
	vector<bool> check(n);

	for (int i = 1; i < n; i++) {
		int diff = b[i - 1] - b[i];
		if (diff < 0) diff = -diff;
		if (diff > 1) return false;
		if (diff == 1) { //인접한 칸의 높이가 1인 경우만 경사로를 놓을 수 있음
			if (b[i - 1] < b[i]) { //i번째 칸이 높은 칸인 경우 
				for (int j = 1; j <= l; j++) {
					if (i - j < 0) return false; //경사로가 범위를 벗어나는 경우

					if (b[i - 1] != b[i - j]) return false; //높이가 다른 경우

					if (check[i - j]) return false; //경사로를 놓은 곳에 또 경사로를 놓은 경우

					check[i - j] = true; //경사로 놓기
				}
			}
			else if (b[i - 1] > b[i]) { //i번째 칸이 낮은 칸이 경우
				for (int j = 0; j < l; j++) {
					if (i + j >= n) return false; 

					if (b[i] != b[i + j]) return false;
					
					if (check[i + j]) return false;

					check[i + j] = true;
				}
			}
		}
	}

	return true;
}

int main() {
	int n, l;
	cin >> n >> l;
	
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0; //길의 개수

	//행 방향으로 지나갈 수 있는 길 체크
	for (int i = 0; i < n; i++) {
		vector<int> b;
		for (int j = 0; j < n; j++) {
			b.push_back(a[i][j]);
		}
		if (go(b, l)) { //i번째 행을 지나갈 수 있으면
			ans += 1;
			/*
			for (int j = 0; j < n; j++) {
				cout << b[j] << ' ';
			}
			cout << '\n';*/
		}
	}

	for (int j = 0; j < n; j++) {
		vector<int> b;
		for (int i = 0; i < n; i++) {
			b.push_back(a[i][j]);
		}
		if (go(b, l)) { //j번째 열을 지나갈 수 있으면
			ans += 1;
		/*	for (int j = 0; j < n; j++) {
				cout << b[j] << ' ';
			}
			cout << '\n';*/
		}
	}

	cout << ans << '\n';

	return 0;
}