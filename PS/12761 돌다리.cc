#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[100001];
int d[100001];

int main() {
	int a, b, n, m;
	cin >> a >> b >> n >> m;

	memset(d, -1, sizeof(d));
	queue<int> q;
	d[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int next = now*a;
		if (next < m + 1 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now*b;
		if (next <= m && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now - a;
		if (next >= 0 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now - b;
		if (next >= 0 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now + a;
		if (next <= m && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now + b;
		if (next <= m && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}

		next = now - 1;
		if (next >= 0 && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}
		
		next = now + 1;
		if (next <=m && d[next] == -1) {
			d[next] = d[now] + 1;
			q.push(next);
		}
	}

	cout << d[m] << '\n';

	return 0;
}