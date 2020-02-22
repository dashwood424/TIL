#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {
	int n, m; //기차의 수, 명령의 수
	cin >> n >> m;

	vector<vector<bool>> a(n + 1, vector<bool>(21)); //n개의 기차
	set<string> s; //목록 비교

	while (m--) {
		int op, num; //명령어, 기차 번호
		cin >> op >> num;
		

		if (op == 1) { //x번 좌석에 승객을 태움
			int x;
			cin >> x;
			if (!a[num][x]) {
				a[num][x] = true;
			}
		}
		else if (op == 2) { //x번 좌석의 승객을 하차시킴
			int x;
			cin >> x;
			if (a[num][x]) {
				a[num][x] = false;
			}
		}
		else if (op == 3) { //num번째 기차에 앉아있는 승객들을 한칸씩 뒤로
			for (int i = 20; i > 0; i--) {
				a[num][i] = a[num][i - 1];
			}
		}
		else if (op == 4) {
			for (int i = 1; i <= 20; i++) {
				a[num][i] = a[num][i + 1];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		string temp;
		for (int j = 1; j <= 20; j++) {
			if (a[i][j]) {
				temp += '1';
			}
			else {
				temp += '0';
			}
		}
		s.insert(temp);
	}
	cout << s.size() << '\n';

	return 0;
}