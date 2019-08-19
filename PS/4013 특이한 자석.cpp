#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n = 4;
		int k;
		cin >> k; //자석을 회전시키는 횟수
		vector<vector<int>> a(n, vector<int>(8));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> a[i][j];
			}
		}

		while (k--) { //회전 횟수 만큼 반복
			int no, dir; //회전시킬 자석, 방향(1: 시계, -1:반시계)
			cin >> no >> dir;
			no -= 1; 
			vector<int> d(8, 0); //자석들의 회전 방향
			d[no] = dir; //no번째 자석의 방향
			
			for (int i = no - 1; i >= 0; i--) { //no번째 자석의 왼쪽자석의 회전 방향 정함
				if (a[i][2] != a[i + 1][6]) { //극이 다르면
					d[i] = -d[i + 1]; //반대 방향으로
				}
				else { //극이 같으면 회전하지 않음 -> 0
					break;
				}
			}

			for (int i = no + 1; i < n; i++) { //no번째 자석의 오른쪽 자석의 회전방향
				if (a[i - 1][2] != a[i][6]) { //극이 다르면
					d[i] = -d[i - 1];
				}
				else {
					break;
				}
			}

			for (int i = 0; i < n; i++) {
				if (d[i] == 0) continue; //i번째 자석이 회전하지 않는 경우

				else if (d[i] == 1) { //i번째 자석이 시계방향으로 회전하는 경우
					int temp = a[i][7];
					for (int j = 7; j > 0; j--) {
						a[i][j] = a[i][j - 1];
					}
					a[i][0] = temp;
				}
				else if (d[i] == -1) {
					int temp = a[i][0];
					for (int j = 0; j < 7; j++) {
						a[i][j] = a[i][j + 1];
					}
					a[i][7] = temp;
				}
			}
		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			if (a[i][0] == 1) {
				ans |= (1 << i);
			}
		}
		cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}