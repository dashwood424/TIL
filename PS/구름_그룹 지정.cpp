#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector<int> a[MAX];
bool check[MAX];

void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt += 1;
		}
	}
	cout << cnt << '\n';
	return 0;
}