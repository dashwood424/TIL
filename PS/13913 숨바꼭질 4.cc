#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int d[200001]; //위치 i에 도착하는 시간
int from[200001]; //from[next]=now -> 다음 칸이 어디에서부터 오는지

void go(int n, int k) {
	if (n != k) {
		go(n, from[k]);
	}
	cout << k << ' ';
}

int main() {
	memset(d, -1, sizeof(d));
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	d[n] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= 0 && d[now - 1] == -1) {
			d[now - 1] = d[now] + 1;
			from[now - 1] = now;
			q.push(now - 1);			
		}
		if (now + 1 < 200001 && d[now + 1] == -1) {
			d[now + 1] = d[now] + 1;
			from[now + 1] = now;
			q.push(now + 1);
		}
		if (now * 2 < 200001 && d[now * 2] == -1) {
			d[now * 2] = d[now] + 1;
			from[now * 2] = now;
			q.push(now * 2);
		}
	}

	cout << d[k] << '\n';
	go(n, k);

	return 0;
}