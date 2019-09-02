#include <iostream>
#include <queue>
using namespace std;

int a[100001]; //수빈이의 위치
int dist[200001]; //수빈이가 동생의 위치 i로 가는데 가장 빠른 시간
bool check[200001]; //방문 체크

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	check[n] = true;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int next : {2 * now, now - 1, now + 1}) {
			if (next >= 0 && next < 200001) { //범위 안에 있는지
				if (check[next] == false) { //이미 방문한 위치는 방문하지 않음
					check[next] = true;
					dist[next] = dist[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << dist[k] << '\n';
	return 0;
}


