/*
각각 부피가 1 <= A, B, C <=200 리터인 세 개의 물통
처음에는 물통 C만 가득 차 있음
물통 A가 비어있을 때 가능 한 물통 C의 상태 모두 구하기
한 물통이 비거나 다른 한 물통이 꽉 찰때까지 물을 붓는다.
물통 A->B, A->C, B->A, B->C, C->A, C->B 로 물을 이동 시킴 -> 6가지 경우의 수
*/
#include <iostream>
#include <queue>
using namespace std;

int cap[3]; //물통 A, B, C의 용량
bool check[201][201]; //물통 A,B에 담겨있을 수 있는 물의 양
bool ans[201]; //물통 A가 비어있을 때 물통 C에 담겨 있을 수 있는 물의 양
int from[] = { 0, 0, 1, 1, 2, 2 };
int to[] = { 1, 2, 0, 2, 0, 1 }; //0: A, 1: B, 2: C

int main() {
	cin >> cap[0] >> cap[1] >> cap[2];

	queue<pair<int, int>> q; //물통 A, B의 물의 양
	q.push(make_pair(0, 0));
	check[0][0] = true;
	ans[cap[2]] = true;

	while (!q.empty()) {
		int now[3];
		now[0] = q.front().first;
		now[1] = q.front().second;
		now[2] = cap[2] - now[0] - now[1];
		q.pop();

		if (now[0] == 0) { //물통 A가 비었으면
			ans[now[2]] = true; //물통 C에 담긴 물의 양 체크
		}

		for (int k = 0; k < 6; k++) {
			int next[3] = { now[0], now[1], now[2] };

			next[to[k]] += next[from[k]];
			next[from[k]] = 0;

			if (next[to[k]] > cap[to[k]]) { //용량을 초과한 경우
				next[from[k]] = next[to[k]] - cap[to[k]];
				next[to[k]] = cap[to[k]];
			}

			if (check[next[0]][next[1]] == false) { //만들어진 적이 없는 물통 A, B의 상태라면
				check[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));
			}
		}
	}

	for (int i = 0; i <= cap[2]; i++) {
		if (ans[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}