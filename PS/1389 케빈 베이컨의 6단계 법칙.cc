#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[101][101]; //친구관계이면 true
int kevin[101][101]; //i에서 j까지 가는 관계의 수
 
int main() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		check[a][b] = true;
		check[b][a] = true;
	}

	for (int i = 1; i <= n; i++) {
		vector<int> d(n + 1, -1); //j번 사람까지 거쳐가는 횟수
		queue<int> q;
		q.push(i);
		d[i] = 0;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int j = 1; j <= n; j++) {
				if (check[now][j] && d[j] == -1) {
					d[j] = d[now] + 1;
					q.push(j);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			kevin[i][j] = d[j];
		}
	}

	int temp_min = -1; //가장 작은 케빈 베이컨 수
	int ans = 0; //케빈 베이컨 수가 가장 작은 사람

	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += kevin[i][j];
		}
		if (temp_min == -1 || temp_min > temp) {
			temp_min = temp;
			ans = i;
		}
	}

	cout << ans << '\n';

	return 0;
}