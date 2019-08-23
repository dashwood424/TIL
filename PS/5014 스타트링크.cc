#include <iostream>
#include <queue>
using namespace std;

int dist[1000001];
bool check[1000001];

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	queue<int> q;
	check[s] = true;
	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now + u <= g && check[now + u] == false) {
			check[now + u] = true;
			dist[now + u] = dist[now] + 1;
			q.push(now + u);
		}

		if (now - d >= 0 && check[now - d] == false) {
			check[now - d] = true;
			dist[now - d] = dist[now] + 1;
			q.push(now - d);
		}
	}

	if (check[g]) {
		cout << dist[g] << '\n';
	}
	else {
		cout << "use the stairs" << '\n';
	}
	return 0;
}