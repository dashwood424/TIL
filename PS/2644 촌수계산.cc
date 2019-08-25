#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> a[101];
bool check[101];
int d[101];

int main() {
	int n;
	cin >> n;
	int s, e;
	cin >> s >> e;
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d, -1, sizeof(d));
	queue<int> q;
	check[s] = true;
	d[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		
		for (int i = 0; i < a[now].size(); i++) {
			int next = a[now][i];
			if (check[next] == false && d[next] == -1) {
				check[next] = true;
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}
	if (d[e] != -1) {
		cout << d[e] << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}