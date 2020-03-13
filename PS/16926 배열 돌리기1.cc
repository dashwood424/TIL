#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[301][301];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, r;
	cin >> n >> m >> r; //r: 회전횟수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int groupn = min(n, m) / 2; //회전하는 그룹의 개수

	vector<vector<int>> groups;

	for (int k = 0; k < groupn; k++) {	
		vector<int> group;
		
		for (int j = k; j < m - k - 1; j++) {
			group.push_back(a[k][j]);
		}
		for (int i = k; i < n - k - 1; i++) {
			group.push_back(a[i][m - k - 1]);
		}
		for (int j = m - k - 1; j > k; j--) {
			group.push_back(a[n - k - 1][j]);
		}
		for (int i = n - k - 1; i > k; i--) {
			group.push_back(a[i][k]);
		}
		groups.push_back(group);
	}

	for (int k = 0; k < groupn; k++) {
		vector<int> &group = groups[k];
		
		for (int rot = 0; rot < r; rot++) {
			int temp = group[0];
			for (int i = 0; i < group.size() - 1; i++) {
				group[i] = group[i + 1];
			}
			group[group.size() - 1] = temp;
		}

		int index = 0;

		for (int j = k; j < m - k - 1; j++) {
			a[k][j] = group[index++];
		}
		for (int i = k; i < n - k - 1; i++) {
			a[i][m - k - 1] = group[index++];
		}
		for (int j = m - k - 1; j > k; j--) {
			a[n - k - 1][j] = group[index++];
		}
		for (int i = n - k - 1; i > k; i--) {
			a[i][k] = group[index++];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}