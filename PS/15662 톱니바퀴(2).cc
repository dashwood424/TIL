#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int k; //회전 횟수
	cin >> k;

	while (k--) {
		int no, dir; //회전시킬 톱니, 회전 방향(1: 시계방향, -1: 반시계방향)
		cin >> no >> dir;
		no -= 1;

		vector<int> d(n, 0); //n번째 톱니의 회전 방향
		d[no] = dir; //회전 시키는 톱니의 회전 방향
		
		for (int i = no - 1; i >= 0; i--) { //no번째 톱니의 왼쪽에 있는 톱니의 방향을 연쇄적으로 구함
			if (a[i][2] != a[i + 1][6]) { //극이 다르면 반대 방향으로 회전
				d[i] = -d[i + 1];
			}
			else { //극이 같으면 회전하지 않음
				break;
			}
		}

		for (int i = no + 1; i < n; i++) { //no번째 톱니의 오른쪽에 있는 톱니의 방향을 연쇄적으로 구함
			if (a[i - 1][2] != a[i][6]) {
				d[i] = -d[i - 1];
			}
			else {
				break;
			}
		}

		//톱니의 방향에 따라 톱니 회전
		for (int i = 0; i < n; i++) {
			if (d[i] == 0) continue; //i번째 톱니가 회전하지 않음
			else if (d[i] == 1) { //i번째 톱니가 시계방향으로 회전
				int temp = a[i][7];
				for (int j = 7; j >= 1; j--) {
					a[i][j] = a[i][j - 1];
				}
				a[i][0] = temp;
			}
			else if (d[i] == -1) { //i번째 톱니가 반시계방향으로 회전
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
		if (a[i][0] == '1') {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}