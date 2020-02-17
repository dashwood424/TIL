#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int d[200001];

int main() {
	int n, k;
	cin >> n >> k;

	memset(d, -1, sizeof(d));
	deque<int> q;
	q.push_back(n);
	d[n] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop_front();

		if (now * 2 < 200001 && d[now * 2] == -1) {
			d[now * 2] = d[now];
			q.push_front(now * 2);
		}

		if (now - 1 >= 0 && d[now - 1] == -1) {
			d[now - 1] = d[now] + 1;
			q.push_back(now - 1);
		}
		if (now + 1 < 200001 && d[now + 1] == -1) {
			d[now + 1] = d[now] + 1;
			q.push_back(now + 1);
		} 
		
	}

	cout << d[k] << '\n';

	return 0;
}