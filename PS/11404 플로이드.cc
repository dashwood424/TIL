#include <iostream>
#include <vector>
#define INF 2147483647
using namespace std;

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<vector<int>> cost(n, vector<int>(n, INF));
	while (m--) {
		int x, y, c;
		cin >> x >> y >> c;
		if (cost[x - 1][y - 1] != INF) {
			if (c < cost[x - 1][y - 1]) {
				cost[x - 1][y - 1] = c;
			}
		}
		else {
			cost[x - 1][y - 1] = c;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				if (cost[i][j] == 0 || cost[i][k] != INF && cost[k][j] != INF) {
					if (cost[i][j] > cost[i][k] + cost[k][j]) {
						cost[i][j] = cost[i][k] + cost[k][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cost[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << cost[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}