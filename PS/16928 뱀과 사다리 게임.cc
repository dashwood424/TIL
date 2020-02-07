#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int v[101]; //i번칸 출발할 경우 다음 칸
int d[101]; //현재 칸 까지 주사위를 던진 최소 횟수

int main() {
	memset(d, -1, sizeof(d));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= 100; i++) {
		v[i] = i;
	}
	while (n--) {
		int x, y;
		cin >> x >> y;
		v[x] = y;
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		v[x] = y;
	}

	queue<int> q;
	d[1] = 0; //현재 1번칸
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = v[now + i]; //주사위를 던져 나온 칸의 다음 칸
			
			if (1 <= next && next <= 100) {
				if (d[next] == -1) {
					d[next] = d[now] + 1;
					q.push(next);
				}
			}
		}
	}

	cout << d[100] << '\n';

	return 0;
}